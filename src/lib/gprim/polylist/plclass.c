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

/* $Header: /cvsroot/geomview/geomview/src/lib/gprim/polylist/plclass.c,v 1.7 2007/02/09 17:15:35 rotdrop Exp $ */


/*
 * Initialize the PolyList class record.
 */

#include "polylistP.h"


static GeomClass *aPolyListMethods = NULL;

int	PolyListPresent = 1;

static char polylistName[] = "polylist";

char *
PolyListName()
{
  return polylistName;
}

GeomClass *PolyListMethods(void)
{
  if (!aPolyListMethods) {
    aPolyListMethods = GeomClassCreate(polylistName);
    aPolyListMethods->name = (GeomNameFunc *) PolyListName;
    aPolyListMethods->methods = (GeomMethodsFunc *) PolyListMethods;
    aPolyListMethods->draw = (GeomDrawFunc *) PolyListDraw;
    aPolyListMethods->bsptree = (GeomBSPTreeFunc *) PolyListBSPTree;
    aPolyListMethods->bound = (GeomBoundFunc *) PolyListBound;
    aPolyListMethods->boundsphere = (GeomBoundSphereFunc *) PolyListSphere;
    aPolyListMethods->evert = (GeomEvertFunc *) PolyListEvert;
    aPolyListMethods->create = (GeomCreateFunc *) PolyListCreate;
    aPolyListMethods->copy = (GeomCopyFunc *) PolyListCopy;
    aPolyListMethods->fsave = (GeomFSaveFunc *) PolyListFSave;
    aPolyListMethods->Delete = (GeomDeleteFunc *) PolyListDelete;
    aPolyListMethods->fload = (GeomFLoadFunc *) PolyListFLoad;
    aPolyListMethods->pick = (GeomPickFunc *) PolyListPick;
    aPolyListMethods->transform = (GeomTransformFunc *) PolyListTransform;
    aPolyListMethods->transformto = (GeomTransformToFunc *) PolyListTransform;
  }
  return aPolyListMethods;
}
