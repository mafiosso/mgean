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
#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include"list.h"
#include"pair_list.h"
#include"load.h"
#include"animation.h"

static NODE *animation_stack = NULL;

ANIMATION *
MG_make_animation (const char *s, int count, Uint32 delay, SDL_Rect * r)
{
  ANIMATION *a;
  a = (ANIMATION *) malloc (sizeof (ANIMATION));
  memset (a, 0, sizeof (ANIMATION));
  a->rect = *r;
  a->count = count;
  a->delay = delay;
  MG_add_pair (&animation_stack, s, a);
  return a;
}

void
MG_set_audio (ANIMATION * a, const char *s)
{
  a->music = MG_get_audio (s);
}

SDL_Rect
get_frame (ANIMATION * a, int *delayed )
{
  SDL_Rect tmp;

  if (!a)
    return tmp;

  int t = a->count * a->delay;
  int nth = (int) (((float) (*delayed) / (float) t) * (float) a->count);

  if (nth >= a->count)
    {
      nth = 0;
      *delayed = 0;
    }

  if (a->anim_array)
    {
      return a->anim_array[nth];
    }

  tmp.x = a->rect.w * nth;
  tmp.y = 0;
  tmp.w = a->rect.w;
  tmp.h = a->rect.h;
  return tmp;
}

ANIMATION *
MG_get_animation (const char *string)
{
  if (!string)
    return NULL;
  return (ANIMATION *) MG_get_nth (animation_stack, string);
}

void
free_anim (ANIMATION * a)
{
  if (a->anim_array)
    free (a->anim_array);
  free (a);
}

void
free_animations ()
{
  MG_destroy_pair (animation_stack, (void (*)(void *)) free_anim);
}

void
MG_set_animation_rects (ANIMATION * a, SDL_Rect * rects)
{
  a->anim_array = rects;
}
