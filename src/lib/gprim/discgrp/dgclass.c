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

#include "discgrpP.h"

GeomClass *DiscGrpClass = NULL;

int DiscGrpPresent = 1;

static char discgrpName[] = "discgrp";

extern DiscGrp      *DiscGrpCreate( DiscGrp *, GeomClass *, va_list * );
extern DiscGrp      *DiscGrpDelete( DiscGrp * );
extern DiscGrp      *DiscGrpCopy( DiscGrp * );
extern int           DiscGrpGet( DiscGrp *, int attr, void *attrp );

extern GeomScanFunc DiscGrpHandleScan;

char *
DiscGrpName()
{
	return discgrpName;
}

GeomClass      *
DiscGrpMethods()
{
	if (!DiscGrpClass)
	{
		DiscGrpClass = GeomClassCreate(discgrpName);

		DiscGrpClass->name = DiscGrpName;
		DiscGrpClass->methods = (GeomMethodsFunc *) DiscGrpMethods;
		DiscGrpClass->create = (GeomCreateFunc *) DiscGrpCreate;
		DiscGrpClass->Delete = (GeomDeleteFunc *) DiscGrpDelete;
		DiscGrpClass->copy = (GeomCopyFunc *) DiscGrpCopy;
		DiscGrpClass->fsave = (GeomFSaveFunc *) DiscGrpFSave;
		DiscGrpClass->bound = (GeomBoundFunc *) DiscGrpBound;
		DiscGrpClass->pick = (GeomPickFunc *) DiscGrpPick;
		DiscGrpClass->draw = (GeomDrawFunc *) DiscGrpDraw;
		DiscGrpClass->scan = (GeomScanFunc *)DiscGrpHandleScan;
		DiscGrpClass->import = (GeomImportFunc *) DiscGrpImport;
		DiscGrpClass->get = (GeomGetFunc *) DiscGrpGet;
/*
		DiscGrpClass->fload = (GeomFLoadFunc *) DiscGrpFLoad;
		DiscGrpClass->evert = (GeomEvertFunc *) DiscGrpEvert;
		DiscGrpClass->transform = 
		  (GeomTransformFunc *) DiscGrpTransform;
		DiscGrpClass->transformto = 
		  (GeomTransformToFunc *) DiscGrpTransformTo;
*/
	}
	return DiscGrpClass;
}
