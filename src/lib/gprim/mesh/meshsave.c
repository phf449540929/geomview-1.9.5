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

#include "meshP.h"

static void ign_fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t result;
  
  result = fwrite(ptr, size, nmemb, stream);
  (void)result;
}

Mesh *MeshFSave(Mesh *m, FILE *outf)
{
  int i, j;
  HPoint3 *p = m->p;
  Point3 *n = m->n;
  ColorA *c = m->c;
  TxST   *u = m->u;

  if (!outf || !m)
    return NULL;
  if (m->n == NULL)
    m->geomflags &= ~MESH_N;
  if (m->c == NULL)
    m->geomflags &= ~MESH_C;
  if (m->u == NULL)
    m->geomflags &= ~MESH_U;

  if (m->geomflags & MESH_C) fputc('C', outf);
  if (m->geomflags & MESH_N) fputc('N', outf);
  if (m->geomflags & MESH_Z) fputc('Z', outf);
  if (m->geomflags & VERT_4D) fputc('4', outf);
  if (m->geomflags & MESH_U) fputc('U', outf);
  if (m->geomflags & MESH_UWRAP) fputc('u', outf);
  if (m->geomflags & MESH_VWRAP) fputc('v', outf);
  if (m->geomflags & MESH_BINARY) /* Hack -- should be sent by context */
  {
    fprintf(outf, "MESH BINARY\n");
    ign_fwrite(&m->nu, 4, 1, outf);
    ign_fwrite(&m->nv, 4, 1, outf);
    for (i = 0; i < m->nv; i++) {
      for (j = 0; j < m->nu; j++) {
	if (m->geomflags & MESH_Z) ign_fwrite(&p->z, 4, 1, outf);
	else if (m->geomflags & MESH_4D) ign_fwrite(p, 4, 4, outf);
	else ign_fwrite(p, 4, 3, outf);
	p++;
	if (m->geomflags & MESH_N) { ign_fwrite(n, 4, 3, outf); n++; }
	if (m->geomflags & MESH_C) { ign_fwrite(c, 4, 4, outf); c++; }
	if (m->geomflags & MESH_U) { ign_fwrite(u, 4, 3, outf); u++; }
      }
    }
  }
  else
  {
    fprintf(outf, "MESH\n%d %d\n", m->nu, m->nv);
    for (i = 0; i < m->nv; i++) {
      for (j = 0; j < m->nu; j++) {
	if(!(m->geomflags & MESH_Z))
	  fprintf(outf, "%.8g %.8g ", p->x, p->y);
	fprintf(outf, "%.8g ", p->z);
	if (m->geomflags & VERT_4D)
	  fprintf(outf, "%.8g ", p->w);
	p++;
	if (m->geomflags & MESH_N) {
	  fprintf(outf, " %.8g %.8g %.8g ", n->x, n->y, n->z);
	  n++;
	}
	if (m->geomflags & MESH_C) {
	  fprintf(outf, " %.3g %.3g %.3g %.3g ",
		  c->r, c->g, c->b, c->a);
	  c++;
	}
	if (m->geomflags & MESH_U) {
	  fprintf(outf, " %.8g %.8g 0", u->s, u->t);
	  u++;
	}
	fputc('\n', outf);
      }
      fputc('\n', outf);
    }
  }

  return m;
}


Mesh *MeshSave(Mesh *m, char *name)
{
  Mesh *tm;
  FILE *outf;

  outf = fopen(name, "w");
  if (!outf) {
    perror(name);
    return NULL;
  }
  tm = MeshFSave(m, outf);
  fclose(outf);

  return tm;
}
