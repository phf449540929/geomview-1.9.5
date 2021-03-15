/* Copyright (C) 1992-1998 The Geometry Center
 * Copyright (C) 1998-2000 Stuart Levy, Tamara Munzner, Mark Phillips
 *
 * This file is part of Geomview.
 * 
 * Geomview is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * Geomview is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with Geomview; see the file COPYING.  If not, write
 * to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139,
 * USA, or visit http://www.gnu.org.
 */

#if HAVE_CONFIG_H
# include "config.h"
#endif

#if 0
static char copyright[] = "Copyright (C) 1992-1998 The Geometry Center\n\
Copyright (C) 1998-2000 Stuart Levy, Tamara Munzner, Mark Phillips";
#endif


/* Authors: Charlie Gunn, Stuart Levy, Tamara Munzner, Mark Phillips */

/*
 * $Header: /cvsroot/geomview/geomview/src/lib/gprim/geom/knownclass.c,v 1.6 2006/08/01 03:38:48 smr99 Exp $
 */

#include <string.h>

#include "geomclass.h"

/*
 * Here's we list all classes known to this object library.
 * Edit this if you add a new class for general use.
 * It's not mandatory to list a class here, but it helps -- generic
 * GeomLoad, GeomPrivate, GeomClassForAll routines benefit from this.
 *
 * Some may not really be linked in, but only ghosts from the stub library.
 * We tell ghosts from warm bodies by their "present" tag -- an int
 * which is 1 for real object routines, 0 for stubs.
 *
 * If you call GeomKnownClassInit(), better link either with all
 * object libraries or with the stub library!
 *
 */
extern int
	BBoxPresent,
	BezierListPresent,
	BezierPresent,
	CommentPresent,
	DiscGrpPresent,
	InstPresent,
	LincolnPresent,
	ListPresent,
	MeshPresent,
	NDMeshPresent,
	NPolyListPresent,
	PolyListPresent,
	QuadPresent,
	SkelPresent,
	SpherePresent,
	TlistPresent,
	VectPresent;

typedef GeomClass *GeomClassPtr;
extern GeomClassPtr
	BBoxMethods(),
	BezierListMethods(),
	BezierMethods(),
	CommentMethods(),
	DiscGrpMethods(),
	InstMethods(),
	LincolnMethods(),
	ListMethods(),
	MeshMethods(),
	NDMeshMethods(),
	NPolyListMethods(),
	PolyListMethods(),
	QuadMethods(),
	SkelMethods(),
	SphereMethods(),
	TlistMethods(),
	VectMethods();

static struct knownclass {
	int *presenttag;
	GeomClass *(*methods)();
	char *loadsuffix;
} known[] = {

/* Testing _WIN32 here is wrong, but the Visual C++ compiler
 * has an ANSI C preprocessor but doesn't define either of these.
 */
#if defined(__STDC__) || defined(__ANSI_CPP__) || defined(_WIN32)

#define KNOWN(name, suffix) \
	{ &name##Present, (GeomClass *(*)())name##Methods,  suffix }

#else /* non-ANSI */

#define	KNOWN(name, suffix) \
	{ &name/**/Present,  (GeomClass *(*)())name/**/Methods,  suffix }
#endif

	KNOWN(Bezier,	NULL),
	KNOWN(BezierList,	"bez"),
	KNOWN(BezierList,	"bbp"),
	KNOWN(Comment,	NULL),
	KNOWN(DiscGrp,	"dgp"),
	KNOWN(PolyList,	"off"),
	KNOWN(Sphere,	"sph"),
	KNOWN(Tlist,	"tl"),
	KNOWN(Tlist,	"prj"),
	KNOWN(BBox,	NULL),
	KNOWN(Inst,	NULL),
	KNOWN(List,	"list"),
	KNOWN(Quad,	"quad"),
	KNOWN(Mesh,	"mesh"),
	KNOWN(NDMesh,	"mesh"),
	KNOWN(Vect,	"vect"),
	KNOWN(Skel,	"skel"),
	KNOWN(NPolyList, "off"),
	KNOWN(Lincoln,	"iL"),
	{NULL, NULL, NULL}
};

void
GeomKnownClassInit()
{
	struct knownclass *k;
	static char done = 0;

	if(!done) {
	    done = 1;
	    for(k = known; k->presenttag != NULL; k++)
		if(*k->presenttag)
		    (void) (*k->methods)();
	}
}

/*
 * This should really be in per-class attributes, not this
 * centralized table, but there's no mechanism for that yet.
 */
GeomClass *
GeomFName2Class(str)
	char *str;
{
	char *p;
	struct knownclass *k;

	if(str == NULL || (p = strrchr(str, '.')) == NULL)
		return NULL;
	p++;
	for(k = known; k->presenttag != NULL; k++)
		if(*k->presenttag && k->loadsuffix != NULL &&
		   strcmp(p, k->loadsuffix) == 0)
			return((*k->methods)());
	return NULL;
}
