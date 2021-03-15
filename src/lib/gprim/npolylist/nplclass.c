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

/* $Header: /cvsroot/geomview/geomview/src/lib/gprim/npolylist/nplclass.c,v 1.9 2007/02/09 17:40:13 rotdrop Exp $ */


/*
 * Initialize the PolyList class record.
 */

#include "npolylistP.h"


static GeomClass *aNPolyListMethods = NULL;
extern NPolyList *NPolyListDraw(NPolyList *);
extern NPolyList *NPolyListCreate(NPolyList *exist, GeomClass *classp, va_list *a_list);
extern NPolyList *NPolyListCopy(NPolyList *);
extern NPolyList *NPolyListFSave(NPolyList *, FILE *outf, char *fname);
extern NPolyList *NPolyListDelete(NPolyList *);
extern NPolyList *NPolyListPick(NPolyList *pl, Pick *p, Appearance *ap,
				Transform T, TransformN *TN, int *axes);
extern NPolyList *NPolyListBSPTree(NPolyList *mesh, BSPTree *tree, int action);

int	NPolyListPresent = 1;

static char npolylistName[] = "npolylist";

char *
NPolyListName()
{
  return npolylistName;
}

GeomClass *NPolyListMethods(void)
{
  if (!aNPolyListMethods) {
    aNPolyListMethods = GeomClassCreate(npolylistName);
    aNPolyListMethods->name = (GeomNameFunc *) NPolyListName;
    aNPolyListMethods->methods = (GeomMethodsFunc *) NPolyListMethods;
    aNPolyListMethods->draw = (GeomDrawFunc *) NPolyListDraw;
    aNPolyListMethods->bsptree = (GeomBSPTreeFunc *) NPolyListBSPTree;
    aNPolyListMethods->bound = (GeomBoundFunc *) NPolyListBound;
    aNPolyListMethods->boundsphere = (GeomBoundSphereFunc *) NPolyListSphere;
    aNPolyListMethods->create = (GeomCreateFunc *) NPolyListCreate;
    aNPolyListMethods->copy = (GeomCopyFunc *) NPolyListCopy;
    aNPolyListMethods->fsave = (GeomFSaveFunc *) NPolyListFSave;
    aNPolyListMethods->Delete = (GeomDeleteFunc *) NPolyListDelete;
    aNPolyListMethods->fload = (GeomFLoadFunc *) NPolyListFLoad;
    aNPolyListMethods->transform = (GeomTransformFunc *) NPolyListTransform;
    aNPolyListMethods->transformto = (GeomTransformToFunc *) NPolyListTransform;
    aNPolyListMethods->pick = (GeomPickFunc *) NPolyListPick;
  }
  return aNPolyListMethods;
}
