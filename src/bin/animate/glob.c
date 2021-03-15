/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#if 0
#ifndef lint
static char sccsid[] = "@(#)glob.c	5.7 (Berkeley) 12/14/88";
#endif /* not lint */
#endif

#if HAVE_CONFIG_H
# include "config.h"
#endif

/*
 * C-shell glob for random programs.
 */


#include <sys/param.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <pwd.h>

#if !defined(dirfd) && !defined(__GLIBC__) && !defined(__linux__) && !defined(__FreeBSD__) && !defined(__CYGWIN__) && !defined(__APPLE__)
#define dirfd(dirp)  ((dirp)->dd_fd)
#endif

#ifndef NCARGS
#define	NCARGS  10240
#endif

#define	QUOTE 0200
#define	TRIM 0177
#define	eq(a,b)		(strcmp(a, b)==0)
#define	GAVSIZ		(NCARGS/6)
#define	isdir(d)	((d.st_mode & S_IFMT) == S_IFDIR)

static	char **gargv;		/* Pointer to the (stack) arglist */
static	int gargc;		/* Number args in gargv */
static	int gnleft;
static	short gflag;
static	int tglob();
char	**glob();
static  void rscan(char **, int ());
static  void ginit(char **);
static  void collect(char *);
static  void acollect(char *);
static  void sort();
static  void expand(char *);
static  void matchdir(char *);
static  int  execbrc(char *, char *);
static  int  match(char *, char *);
static  int  amatch(char *, char *);
#if 0
static  int  Gmatch(char *, char *);
#endif
static  void Gcat(char *, char *);
static  void addpath(char);
static  void fatal(char *);
/*static  void scan(char **, int ());*/
char	*globerr;
char	*home;
struct	passwd *getpwnam();
extern	int errno;
static	char *strspl(), *strend();
/*char	*malloc(), *strcpy(), *strcat(); */
char	**copyblk();

static	int globcnt;

char	*globchars = "`{[*?";

static	char *gpath, *gpathp, *lastgpathp;
static	int globbed;
static	char *entp;
static	char **sortbas;

void blkfree();
int letter();
int digit();
int gethdir();
int any();


char **
glob(v)
	char *v;
{
	char agpath[BUFSIZ];
	char *agargv[GAVSIZ];
	char *vv[2];
	vv[0] = v;
	vv[1] = 0;
	gflag = 0;
	rscan(vv, tglob);
	if (gflag == 0)
		return (copyblk(vv));

	globerr = 0;
	gpath = agpath; gpathp = gpath; *gpathp = 0;
	lastgpathp = &gpath[sizeof agpath - 2];
	ginit(agargv); globcnt = 0;
	collect(v);
	if (globcnt == 0 && (gflag&1)) {
		blkfree(gargv), gargv = 0;
		return (0);
	} else
		return (gargv = copyblk(gargv));
}

static void
ginit(agargv)
	char **agargv;
{

	agargv[0] = 0; gargv = agargv; sortbas = agargv; gargc = 0;
	gnleft = NCARGS - 4;
}

static void
collect(as)
	char *as;
{
	if (eq(as, "{") || eq(as, "{}")) {
		Gcat(as, "");
		sort();
	} else
		acollect(as);
}

static void
acollect(as)
	char *as;
{
	int ogargc = gargc;

	gpathp = gpath; *gpathp = 0; globbed = 0;
	expand(as);
	if (gargc != ogargc)
		sort();
}

static void
sort()
{
	char **p1, **p2, *c;
	char **Gvp = &gargv[gargc];

	p1 = sortbas;
	while (p1 < Gvp-1) {
		p2 = p1;
		while (++p2 < Gvp)
			if (strcmp(*p1, *p2) > 0)
				c = *p1, *p1 = *p2, *p2 = c;
		p1++;
	}
	sortbas = Gvp;
}

static void
expand(as)
	char *as;
{
	char *cs;
	char *sgpathp, *oldcs;
	struct stat stb;

	sgpathp = gpathp;
	cs = as;
	if (*cs == '~' && gpathp == gpath) {
		addpath('~');
		for (cs++; letter(*cs) || digit(*cs) || *cs == '-';)
			addpath(*cs++);
		if (!*cs || *cs == '/') {
			if (gpathp != gpath + 1) {
				*gpathp = 0;
				if (gethdir(gpath + 1))
					globerr = "Unknown user name after ~";
				(void) strcpy(gpath, gpath + 1);
			} else {
				if(home == NULL) {
				    struct passwd *pp;
				    extern char *getenv();

				    home = getenv("HOME");
				    if(home == NULL) {
					pp = getpwuid(getuid());
					if(pp != NULL)
					    home = pp->pw_dir;
				    }
				}
				if(home == NULL) {
				    home = "";
				    globerr = "Can't determine own home directory";
				} else {
				    (void) strcpy(gpath, home);
				}
			}
			gpathp = strend(gpath);
		}
	}
	while (!any(*cs, globchars)) {
		if (*cs == 0) {
			if (!globbed)
				Gcat(gpath, "");
			else if (stat(gpath, &stb) >= 0) {
				Gcat(gpath, "");
				globcnt++;
			}
			goto endit;
		}
		addpath(*cs++);
	}
	oldcs = cs;
	while (cs > as && *cs != '/')
		cs--, gpathp--;
	if (*cs == '/')
		cs++, gpathp++;
	*gpathp = 0;
	if (*oldcs == '{') {
		(void) execbrc(cs, ((char *)0));
		return;
	}
	matchdir(cs);
endit:
	gpathp = sgpathp;
	*gpathp = 0;
}

static void
matchdir(pattern)
	char *pattern;
{
	struct stat stb;
	struct dirent *dp;
	DIR *dirp;

	dirp = opendir(gpath[0] == '\0' ? "." : gpath);
	if (dirp == NULL) {
		if (globbed)
			return;
		goto patherr2;
	}
	if (fstat(dirfd(dirp), &stb) < 0)
		goto patherr1;
	if (!isdir(stb)) {
		errno = ENOTDIR;
		goto patherr1;
	}
	while ((dp = readdir(dirp)) != NULL) {
		if (dp->d_ino == 0)
			continue;
		if (match(dp->d_name, pattern)) {
			Gcat(gpath, dp->d_name);
			globcnt++;
		}
	}
	closedir(dirp);
	return;

patherr1:
	closedir(dirp);
patherr2:
	globerr = "Bad directory components";
}

static int
execbrc(p, s)
	char *p, *s;
{
	char restbuf[BUFSIZ + 2];
	char *pe, *pm, *pl;
	int brclev = 0;
	char *lm, savec, *sgpathp;

	for (lm = restbuf; *p != '{'; *lm++ = *p++)
		continue;
	for (pe = ++p; *pe; pe++)
	switch (*pe) {

	case '{':
		brclev++;
		continue;

	case '}':
		if (brclev == 0)
			goto pend;
		brclev--;
		continue;

	case '[':
		for (pe++; *pe && *pe != ']'; pe++)
			continue;
		continue;
	}
pend:
	brclev = 0;
	for (pl = pm = p; pm <= pe; pm++)
	switch (*pm & (QUOTE|TRIM)) {

	case '{':
		brclev++;
		continue;

	case '}':
		if (brclev) {
			brclev--;
			continue;
		}
		goto doit;

	case ','|QUOTE:
	case ',':
		if (brclev)
			continue;
doit:
		savec = *pm;
		*pm = 0;
		(void) strcpy(lm, pl);
		(void) strcat(restbuf, pe + 1);
		*pm = savec;
		if (s == 0) {
			sgpathp = gpathp;
			expand(restbuf);
			gpathp = sgpathp;
			*gpathp = 0;
		} else if (amatch(s, restbuf))
			return (1);
		sort();
		pl = pm + 1;
		if (brclev)
			return (0);
		continue;

	case '[':
		for (pm++; *pm && *pm != ']'; pm++)
			continue;
		if (!*pm)
			pm--;
		continue;
	}
	if (brclev)
		goto doit;
	return (0);
}

static int
match(s, p)
	char *s, *p;
{
	int c;
	char *sentp;
	char sglobbed = globbed;

	if (*s == '.' && *p != '.')
		return (0);
	sentp = entp;
	entp = s;
	c = amatch(s, p);
	entp = sentp;
	globbed = sglobbed;
	return (c);
}

static int
amatch(s, p)
	char *s, *p;
{
	int scc;
	int ok, lc;
	char *sgpathp;
	struct stat stb;
	int c, cc;

	globbed = 1;
	for (;;) {
		scc = *s++ & TRIM;
		switch (c = *p++) {

		case '{':
			return (execbrc(p - 1, s - 1));

		case '[':
			ok = 0;
			lc = 077777;
			while ((cc = *p++)) {
				if (cc == ']') {
					if (ok)
						break;
					return (0);
				}
				if (cc == '-') {
					if (lc <= scc && scc <= *p++)
						ok++;
				} else
					if (scc == (lc = cc))
						ok++;
			}
			if ((cc == 0)) {
			  if (ok) {
			    p--;
			  } else {
			    return 0;
			  }
			}
			continue;

		case '*':
			if (!*p)
				return (1);
			if (*p == '/') {
				p++;
				goto slash;
			}
			s--;
			do {
				if (amatch(s, p))
					return (1);
			} while (*s++);
			return (0);

		case 0:
			return (scc == 0);

		default:
			if (c != scc)
				return (0);
			continue;

		case '?':
			if (scc == 0)
				return (0);
			continue;

		case '/':
			if (scc)
				return (0);
slash:
			s = entp;
			sgpathp = gpathp;
			while (*s)
				addpath(*s++);
			addpath('/');
			if (stat(gpath, &stb) == 0 && isdir(stb)) {
				if (*p == 0) {
					Gcat(gpath, "");
					globcnt++;
				} else {
					expand(p);
				}
			}
			gpathp = sgpathp;
			*gpathp = 0;
			return (0);
		}
	}
}

#if 0
static int
Gmatch(s, p)
	char *s, *p;
{
	int scc;
	int ok, lc;
	int c, cc;

	for (;;) {
		scc = *s++ & TRIM;
		switch (c = *p++) {

		case '[':
			ok = 0;
			lc = 077777;
			while ((cc = *p++)) {
				if (cc == ']') {
					if (ok)
						break;
					return (0);
				}
				if (cc == '-') {
					if (lc <= scc && scc <= *p++)
						ok++;
				} else
					if (scc == (lc = cc))
						ok++;
			}
			if ((cc == 0)) {
			  if (ok) {
			    p--;
			  } else {
			    return 0;
			  }
			}
			continue;

		case '*':
			if (!*p)
				return (1);
			for (s--; *s; s++)
				if (Gmatch(s, p))
					return (1);
			return (0);

		case 0:
			return (scc == 0);

		default:
			if ((c & TRIM) != scc)
				return (0);
			continue;

		case '?':
			if (scc == 0)
				return (0);
			continue;

		}
	}
}
#endif

static void
Gcat(s1, s2)
	char *s1, *s2;
{
	int len = strlen(s1) + strlen(s2) + 1;

	if (len >= gnleft || gargc >= GAVSIZ - 1)
		globerr = "Arguments too long";
	else {
		gargc++;
		gnleft -= len;
		gargv[gargc] = 0;
		gargv[gargc - 1] = strspl(s1, s2);
	}
}

static void
addpath(char c)
{

	if (gpathp >= lastgpathp)
		globerr = "Pathname too long";
	else {
		*gpathp++ = c;
		*gpathp = 0;
	}
}

static void
rscan(t, f)
	char **t;
	int (*f)();
{
	char *p, c;

	while ((p = *t++)) {
	  if (f == tglob) {
	    if (*p == '~') {
	      gflag |= 2;
	    } else if (eq(p, "{") || eq(p, "{}")) {
	      continue;
	    }
	  }
		while ((c = *p++))
			(*f)(c);
	}
}
/*
static void
scan(t, f)
	char **t;
	int (*f)();
{
	char *p, c;

	while (p = *t++)
		while (c = *p)
			*p++ = (*f)(c);
} */

static int
tglob(c)
	char c;
{

	if (any(c, globchars))
		gflag |= c == '{' ? 2 : 1;
	return (c);
}
/*
static void
trim(c)
	char c;
{

	return (c & TRIM);
} */


int
letter(c)
	char c;
{

	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_');
}

int
digit(c)
	char c;
{

	return (c >= '0' && c <= '9');
}

int
any(c, s)
	int c;
	char *s;
{

	while (*s)
		if (*s++ == c)
			return(1);
	return(0);
}

int
blklen(av)
	char **av;
{
	int i = 0;

	while (*av++)
		i++;
	return (i);
}

char **
blkcpy(oav, bv)
	char **oav;
	char **bv;
{
	char **av = oav;

	while ((*av++ = *bv++))
		continue;
	return (oav);
}

void
blkfree(av0)
	char **av0;
{
	char **av = av0;

	while (*av)
		free(*av++);
}

static
char *
strspl(cp, dp)
	char *cp, *dp;
{
	char *ep = malloc((unsigned)(strlen(cp) + strlen(dp) + 1));

	if (ep == (char *)0)
		fatal("Out of memory");
	(void) strcpy(ep, cp);
	(void) strcat(ep, dp);
	return (ep);
}

char **
copyblk(v)
	char **v;
{
	char **nv = (char **)malloc((unsigned)((blklen(v) + 1) *
						sizeof(char **)));
	if (nv == (char **)0)
		fatal("Out of memory");

	return (blkcpy(nv, v));
}

static
char *
strend(cp)
	char *cp;
{

	while (*cp)
		cp++;
	return (cp);
}
/*
 * Extract a home directory from the password file
 * The argument points to a buffer where the name of the
 * user whose home directory is sought is currently.
 * We write the home directory of the user back there.
 */
int
gethdir(home)
	char *home;
{
	struct passwd *pp = getpwnam(home);

	if (!pp || home + strlen(pp->pw_dir) >= lastgpathp)
		return (1);
	(void) strcpy(home, pp->pw_dir);
	return (0);
}

static void
fatal(s)
char *s;
{
    fprintf( stderr, "glob: %s\n", s );
    exit(1);
}
