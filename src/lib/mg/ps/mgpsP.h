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
#ifndef MGPSP_H
#define MGPSP_H

typedef struct {
	Pt3Coord	x, y, z, w;
        ColorA		vcol;
	int		drawnext;
	} CPoint3;

/*****************************************************************************/

#define		MGX_NULL		0
#define		MGX_END			0
#define		MGX_BGNLINE		1
#define		MGX_BGNPOLY		2
#define		MGX_BGNEPOLY		3
#define		MGX_BGNSLINE		4
#define		MGX_BGNSPOLY		5
#define		MGX_BGNSEPOLY		6
#define		MGX_VERTEX		7
#define		MGX_CVERTEX		8
#define		MGX_COLOR		9
#define		MGX_ECOLOR		10

#define		PRIM_LINE		1
#define		PRIM_POLYGON		2
#define		PRIM_EPOLYGON		3
#define		PRIM_SLINE		4 /* smooth shaded primitives */
#define		PRIM_SPOLYGON		5
#define		PRIM_SEPOLYGON		6
#define		PRIM_INVIS		7

/*****************************************************************************/

typedef struct _mgpsprim {
  int                   mykind; /* kind of primitive */
  int                   index;  /* index into array of vertices */
  int                   numvts; /* number of vertices */
  float                 depth;  /* z value for sorting (at least for now) */
  int                   color[3]; /* rgb color of polygon */
  int                   ecolor[3]; /* edge color of polygon */
  int                   ewidth; /* edge width */
} mgpsprim;

/*****************************************************************************/

typedef struct _mgps_sort
{
  vvec 		 primsort;	/* pointers to mgx11prim array elements*/
  vvec		 prims;		/* array of mgx11prim structures */
  int            primnum;	/* number of primitives */
  int		 cprim;		/* current primitive being stored */

  vvec		 pverts;	/* array of vertices */
  int            pvertnum;
  int		 cvert;		/* current vertex being stored */
  int		 maxverts;	/* maximum number of vertices */

} mgps_sort;

/*****************************************************************************/

typedef struct mgpscontext {
    struct mgcontext mgctx;	/* The mgcontext */
    FILE *file;
    char filepath[280];
    unsigned char *buf;
    float *zbuf;
    int xsize, ysize;
    float zrange;
    int znudge;			/* znudge for drawing lines closer */
    float znudgeby;		/* how much of a nudge ? */
    long znear, zfar;		/* Current Z-buffer limits */
    vvec room;			/* Scratch space */
#if 0
    int  pvertnum;		/* number of vertices */
    vvec pverts;		/* Primitve vertices */
#endif
    mgps_sort *mysort;          /* sorting structure */
    int	sizelock;		/* for prohibiting size change from within mg
				   when the cam window is part of a larger
				   hierarchy of windows as with Widgets */
    int born;
} mgpscontext;

#define MAXZNUDGE	8	/* Max depth of mgbuf_closer()/farther() */

#define _mgpsc		((mgpscontext*)_mgc)

extern void mgps_add(int primtype, int ndata, void *data, void *cdata);

extern void mgps_init_zrange();
extern int mgps_primclip(mgpsprim *aprim);

#endif

