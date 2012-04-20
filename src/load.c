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
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "list.h"
#include "pair_list.h"
#include "init.h"
#include "load.h"

static NODE *image_list = NULL;

SDL_Surface *
MG_load_image (const char *path)
{
  SDL_Surface *image;
  image = IMG_Load (path);
  if (!image)
    {
      printf ("[WARN] image %s could not be loaded!\n", path);
      return NULL;
    }
  SDL_SetColorKey (image, SDL_SRCCOLORKEY,
		   SDL_MapRGB (image->format, 255, 0, 255));
  return image;
}

int
MG_preload_img (const char *path)
{
  SDL_Surface *img = MG_load_image (path);
  if (!img)
    return -1;

  MG_add_pair (&image_list, path, (SDL_Surface *) img);
  return 0;
}

SDL_Surface *
MG_get_img (const char *path)
{
  SDL_Surface *img = (SDL_Surface *) MG_get_nth (image_list, path);
  if (img)
    {
      return img;
    }
  img = MG_load_image (path);
  if (!img)
    return NULL;
  MG_add_pair (&image_list, path, (SDL_Surface *) img);
  return img;
}

void
free_surfaces ()
{
  MG_destroy_pair (image_list, (void (*)(void *)) SDL_FreeSurface);
}

// ========== Loading audio =============
static NODE *audio_list = NULL;


Mix_Chunk *
MG_load_audio (const char *path)
{
  Mix_Chunk *audio;
  audio = Mix_LoadWAV (path);
  return audio;
}

int
MG_preload_audio (const char *path)
{
  Mix_Chunk *audio = MG_load_audio (path);
  if (!audio)
    return -1;

  MG_add_pair (&audio_list, path, (Mix_Chunk *) audio);
  return 0;
}

Mix_Chunk *
MG_get_audio (const char *path)
{
  Mix_Chunk *audio = (Mix_Chunk *) MG_get_nth (audio_list, path);
  if (audio)
    {
      return audio;
    }
  audio = MG_load_audio (path);
  if (!audio)
    return NULL;
  MG_add_pair (&audio_list, path, (Mix_Chunk *) audio);
  return audio;
}

void
free_audio ()
{
  MG_destroy_pair (audio_list, (void (*)(void *)) Mix_FreeChunk);
}

/* ttf fonts loading */

static NODE *font_list = NULL;
static int font_size = 16;

static TTF_Font *
load_ttf (const char *path)
{
  return TTF_OpenFont (path, font_size);
}

void
MG_set_system_font_size (int size)
{
  font_size = size;
}

TTF_Font *
MG_preload_ttf (const char *path)
{
  TTF_Font *f = load_ttf (path);
  if (f)
    {
      MG_add_pair (&font_list, path, (void *) f);
    }
  else
    {
      printf ("[WARN] font: %s could not be loaded!\n", path);
    }
  return f;
}

TTF_Font *
MG_get_ttf (const char *path)
{
  TTF_Font *f = (TTF_Font *) MG_get_nth (font_list, path);
  if (!f)
    {
      return MG_preload_ttf (path);
    }
  return f;
}

void
free_ttfs ()
{
  NODE *tmp = font_list;
  while (tmp)
    {
      TTF_CloseFont ((TTF_Font *) tmp->value);
      tmp = tmp->node;
    }

  font_list = NULL;
}
