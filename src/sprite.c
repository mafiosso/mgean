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

/*! \file */
/*! \brief sprite implementation */
#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>

#include"list.h"
#include"pair_list.h"

#include"init.h"
#include "keyboard.h"


#include"physics.h"
#include"audio.h"
#include"animation.h"

#include"sprite.h"
#include"collision.h"
#include "drawing.h"

void search_collision ();
void free_trash ();

static NODE *drawing_stack = NULL;
static NODE *trash = NULL;
static Uint32 time_offset = 0;

static void
handle_keys (SPRITE * sprite)
{
  void (*function) (SPRITE * s) = MG_get_nth (sprite->args, "on_iter");
  if (function)
    function (sprite);
}

NODE *
MG_drawing_stack ()
{
  return drawing_stack;
}

int
MG_get_system_dt ()
{
  return time_offset;
}

void *
MG_send_msg (SPRITE * s, const char *msg)
{
  void *(*function) (SPRITE * sp) = MG_get_nth (s->args, msg);

  if (function)
    return function (s);

  return NULL;
}

static SPRITE *
create_sprite (SDL_Surface * s, SDL_Rect * src)
{
  SPRITE *new = (SPRITE *) malloc (sizeof (SPRITE));
  memset (new, 0, sizeof (SPRITE));

  if (!s)
    return new;

  SDL_Rect tmp;

  if (!src)
    {
      tmp.x = 0;
      tmp.y = 0;
      tmp.w = s->w;
      tmp.h = s->h;
    }
  else
    {
      tmp = *src;
    }

  new->img = s;
  new->src = tmp;
  new->dest.x = 0;
  new->dest.y = 0;
  new->dest.w = tmp.w;
  new->dest.h = tmp.h;

  new->audio_state.channel = -1;	/* because of range is 0-n */

  MG_invalidate_rect (new->dest);

  return new;
}

void
MG_attach_sprite (SPRITE * owner, SPRITE * attached, int offset_x,
		  int offset_y)
{
  MG_add (&owner->attached_sprites, attached);
  MG_sprite_set_position (attached, owner->dest.x + offset_x,
			  owner->dest.y + offset_y);
}

SPRITE *
MG_detach_sprite (SPRITE * owner, SPRITE * attached)
{
  return (SPRITE *) MG_remove_node (&owner->attached_sprites,
				    (void *) attached);
}

SDL_Surface *
MG_set_img (SPRITE * self, SDL_Surface * surf)
{
  MG_invalidate_rect (self->dest);

  return (self->img = surf);
}

void
MG_set_rect (SPRITE * self, SDL_Rect r)
{
  self->dest = r;
}

void
MG_set_srcrect (SPRITE * self, SDL_Rect r)
{
  self->src = r;
  self->dest.w = r.w;
  self->dest.h = r.h;

  MG_invalidate_rect (self->dest);
}

SPRITE *
MG_make_sprite (SDL_Surface * s, SDL_Rect * src)
{
  SPRITE *sprt = create_sprite (s, src);
  if (!sprt)
    return NULL;

  MG_add (&drawing_stack, sprt);
  return sprt;
}

SPRITE *
MG_make_sprite_nth (SDL_Surface * s, SDL_Rect * src, int nth)
{
  SPRITE *sprt = create_sprite (s, src);
  if (!sprt)
    return NULL;

  MG_add_nth (&drawing_stack, sprt, nth);
  return sprt;
}

SDL_Rect
MG_apply_physics (PHYSICS * p, SDL_Rect r, int dt)
{
  SDL_Rect out = r;

  MG_compute_physics (p);

  if (p->m > 0.0f)
    {
      out.x += (int) (p->v.x * dt);
      out.y += (int) (p->v.y * dt);
    }
  return out;
}

void
apply_physics (SPRITE * s)
{
  static int dt = 0;
  dt = MG_get_system_dt ();
  MG_compute_physics (&s->physics);

  if (s->physics.m > 0.0f)
    {
      MG_move_sprite (s, s->physics.v.x * dt, s->physics.v.y * dt);
    }
}

static int rect_cmp( SDL_Rect r1 , SDL_Rect r2 )
{
	return (r1.x == r2.x) && (r1.y == r2.y ) &&
		(r1.w == r2.w ) && (r1.h == r2.h);
}

void
draw_sprite (SPRITE * sprite)
{
  SDL_Rect current_frame;

  handle_keys (sprite);
  apply_physics (sprite);
  search_collision (sprite);

  if (sprite->anim)
    {
      MG_sprite_play_music (sprite);

      current_frame = get_frame (sprite->anim, &sprite->time);
      sprite->time += MG_get_system_dt ();

      if( rect_cmp( current_frame , sprite->src ) )
	  return;

      sprite->src = current_frame;

      sprite->dest.w = current_frame.w;
      sprite->dest.h = current_frame.h;

      MG_invalidate_rect (sprite->dest);
    }
}

void
MG_draw_stack (int delay)
{
  static Uint32 begin = 0;
  int to_sleep = 0;

  MG_get_keys ();

  MG_destructive_map (drawing_stack, (void (*)(void *)) draw_sprite);

  free_trash ();
  MG_update_screen ();

  time_offset = SDL_GetTicks () - begin;
  to_sleep = (delay - time_offset);

  if (to_sleep > 0)
    SDL_Delay (to_sleep);

  time_offset = SDL_GetTicks () - begin;
  if( time_offset > delay )
      time_offset = delay;

  begin = SDL_GetTicks ();
}

void
MG_sprite_set_position (SPRITE * s, int x, int y)
{
  MG_invalidate_rect (s->dest);
  int dx, dy;

  NODE *attachements = s->attached_sprites;
  SPRITE *attached;

  while (attachements)
    {
      attached = attachements->value;
      dx = attached->dest.x - s->dest.x;
      dy = attached->dest.y - s->dest.y;

      MG_sprite_set_position (attached, x + dx, y + dy);
      attachements = attachements->node;
    }

  s->dest.x = x;
  s->dest.y = y;

  MG_invalidate_rect (s->dest);
}

void
MG_move_sprite (SPRITE * s, int dx, int dy)
{
  if (!dx && !dy)
    return;

  NODE *attachements = s->attached_sprites;

  MG_invalidate_rect (s->dest);

  s->dest.x += dx;
  s->dest.y += dy;

  /* move all attached sprites too */
  while (attachements)
    {
      MG_move_sprite ((SPRITE *) attachements->value, dx, dy);
      attachements = attachements->node;
    }

  MG_invalidate_rect (s->dest);
}

void
MG_set_power (SPRITE * s, VECTOR * v)
{
  s->physics.f = *v;
}

void
MG_set_speed (SPRITE * s, VECTOR * v)
{
  s->physics.v = *v;
}

void
MG_set_weight (SPRITE * s, float m)
{
  if (!m)
    return;

  s->physics.m = m;
}

void
MG_set_animation (SPRITE * s, const char *string)
{
  s->time = 0;
  s->anim = MG_get_animation (string);
  s->audio_state.channel = -1;
  s->audio_state.repeat = 1;

  if (s->img)
    {
      if (!s->anim)
	{
	  s->src.x = 0;
	  s->src.y = 0;
	  s->src.w = s->img->w;
	  s->src.h = s->img->h;
	  MG_invalidate_rect (s->dest);
	}
    }
}

void
MG_install_callback (SPRITE * s, const char *key, void (*function))
{
  MG_set_key (s, key, function);
}

void
MG_set_key (SPRITE * s, const char *key, void *val)
{
  NODE *tmp = s->args;
  int i = 0;

  while (tmp)
    {
      if (!(i % 2))
	{
	  if (!strcmp ((char *) tmp->value, key))
	    {
	      tmp = tmp->node;
	      tmp->value = val;
	      return;
	    }
	}

      i++;
      tmp = tmp->node;
    }

  MG_add_pair (&s->args, key, val);
}

void *
MG_get_key (SPRITE * s, const char *key)
{
  return MG_get_nth (s->args, key);
}

void
search_collision (SPRITE * s)
{
  if (!s)
    return;

  NODE *tmp1 = drawing_stack;
  void (*function) (SPRITE * sprt1, SPRITE * sprt2) =
    MG_get_key (s, "on_collide");
  SPRITE *sp2;

  if (!function)
    return;

  while (tmp1)
    {
      sp2 = (SPRITE *) tmp1->value;

      if (sp2 && intersect_p_rect (&s->dest, &sp2->dest))
	{
	  function (s, sp2);
	}

      tmp1 = tmp1->node;
    }
}

void
free_sprite (SPRITE * s)
{
  void (*function) (SPRITE * s);
  if (MG_remove_node (&drawing_stack, s))
    {
      function = (void (*)(SPRITE * s)) MG_get_key (s, "on_destroy");
      if (function)
	function (s);

      MG_destroy_pair (s->args, NULL);
      MG_remove_list (s->attached_sprites, NULL);
      memset (s, 0, sizeof (SPRITE));
      free (s);
    }
}


void
free_trash ()
{
  if (!trash)
    return;

  NODE *help_trash = trash;

  while (trash)			/* remove until trash grows */
    {
      trash = NULL;
      MG_remove_list (help_trash, (void (*)(void *)) free_sprite);
      help_trash = trash;
    }

  trash = NULL;
}

void
MG_remove_sprite (SPRITE * s)
{
  if (!s)
    return;
  MG_add (&trash, s);
  MG_invalidate_rect (s->dest);
}

void
MG_unload_sprite (SPRITE * s)
{
  MG_send_msg (s, "on_destroy");
  MG_destroy_pair (s->args, NULL);
  MG_remove_list (s->attached_sprites, NULL);
  free (s);
}

void invalid_rects_clear ();

void
MG_drawing_stack_free ()
{
  //MG_remove_list( drawing_stack , (void (*)(void *))MG_unload_sprite );
  MG_destructive_map (drawing_stack, (void (*)(void *)) MG_remove_sprite);

  free_trash ();
  MG_remove_list (drawing_stack, NULL);

  drawing_stack = NULL;
  invalid_rects_clear ();
}
