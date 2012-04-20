/*
This file is part of MGEAN library.

MGEAN library is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

MGEAN library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with MGEAN library.  If not, see <http://www.gnu.org/licenses/>.

Copyright 2010-2011 Pavel Procházka
*/

#include <stdio.h>
#include <SDL/SDL.h>
#include "list.h"
#include "MG_lib.h"

/* Implements optimization over dirty rects */

static NODE *invalid_rects = NULL;

void
invalid_rects_clear ()
{
  MG_remove_list (invalid_rects, free);
  invalid_rects = NULL;
}

void
MG_invalidate_rect (SDL_Rect rect)
{
  SDL_Rect *inv_rect = (SDL_Rect *) malloc (sizeof (SDL_Rect));
  MACHINE * m = MG_get_machine();
  SDL_Rect wrld = { 0 , 0 , m->game_world->w , m->game_world->h };

  *inv_rect = MG_rects_cut( rect , wrld );
  if( MG_null_rect_p (*inv_rect) )
    {
      free( inv_rect );
      return;
    }

  MG_add (&invalid_rects, inv_rect);
}

int
MG_null_rect_p (SDL_Rect rect)
{
  return (rect.w <= 0 || rect.h <= 0);
}

#define MIN(a,b)(a < b ? a : b)
#define MAX(a,b)(a > b ? a : b)

static const SDL_Rect rect_invalid = { 0, 0, 0, 0 };

SDL_Rect
MG_rects_cut (SDL_Rect r1, SDL_Rect r2)
{
  SDL_Rect out;
  POINT p1;
  POINT p2;
  int tmp;

  out.x = MAX (r1.x, r2.x);
  out.y = MAX (r1.y, r2.y);

  p1.x = r1.x + r1.w;
  p1.y = r1.y + r1.h;

  p2.x = r2.x + r2.w;
  p2.y = r2.y + r2.h;

  tmp = MIN (p1.x, p2.x) - out.x;
  if (tmp <= 0)
    return rect_invalid;
  out.w = tmp;
  tmp = MIN (p1.y, p2.y) - out.y;
  if (tmp <= 0)
    return rect_invalid;
  out.h = tmp;
  return out;
}

static void
update_sprite (SPRITE * s, SDL_Rect * invalid_rect, MACHINE * m,
	       SDL_Rect * screen_rect)
{
  if (!s->img)
    return;

  SDL_Rect cut = MG_rects_cut (s->dest, *invalid_rect);

  SDL_Rect src = cut;
  src.x -= s->dest.x;
  src.y -= s->dest.y;

  src.x += s->src.x;
  src.y += s->src.y;

  src = MG_rects_cut (src, s->src);

  SDL_BlitSurface (s->img, &src, m->game_world, &cut);
}

void
MG_update_screen ()
{
  MACHINE *m = MG_get_machine ();	//  SDL_UpdateRect( m->screen , cut.x , cut.y , cut.w , cut.h );

  SDL_Rect r_screen = { 0, 0, m->screen->w, m->screen->h };
  NODE *ds = NULL;
  NODE *ir_ptr = invalid_rects;

  while (ir_ptr)
    {
      ds = MG_drawing_stack ();
      while (ds)
	{
	  update_sprite ((SPRITE *) ds->value, (SDL_Rect *) ir_ptr->value, m,
			 &r_screen);

	  ds = ds->node;
	}

      ir_ptr = ir_ptr->node;
    }

  //SDL_Flip (m->screen);
  SDL_Rect v = m->view_rect;
  SDL_BlitSurface( m->game_world, &v , m->screen , NULL );
  SDL_UpdateRect( m->screen , 0 , 0 , 0 , 0 );

  MG_remove_list (invalid_rects, free);
  invalid_rects = NULL;
}
