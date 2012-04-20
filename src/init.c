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

#include<stdio.h>
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include "list.h"
#include "init.h"
#include "load.h"

static MACHINE *machine = NULL;

SDL_Surface *
MG_set_world( int w , int h )
{
  MACHINE * m = MG_get_machine();
  if( !m )
    return NULL;
  if( m->game_world )
    SDL_FreeSurface( m->game_world );

  m->game_world = SDL_CreateRGBSurface( SDL_SWSURFACE, w, h,
					m->screen->format->BitsPerPixel,
					m->screen->format->Rmask, m->screen->format->Gmask,
					m->screen->format->Bmask, m->screen->format->Amask
					);
  SDL_Rect r = {0,0,m->screen->w, m->screen->h};
  MG_set_view_rect( r );
}

void
MG_set_view_rect( SDL_Rect r )
{
  machine->view_rect = r;
}

static void on_mix_halt(int channel){

}

int
MG_init_video (int width, int height, Uint32 video_flags)
{
  SDL_Surface *screen;
  int audio_rate = 22050;
  Uint16 audio_format = AUDIO_S16;	/* 16-bit stereo */
  int audio_channels = 2;
  int audio_buffers = 2048;

  machine = (MACHINE *) malloc (sizeof (MACHINE));
  memset (machine, 0, sizeof (MACHINE));
//  machine->use_audio = 1;

  if( !( SDL_WasInit( SDL_INIT_VIDEO ) & SDL_INIT_VIDEO ) )
    {
      printf("SDL was not inited yet ... initing\n");

      if( !SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO) )
      {
	if (TTF_Init () == -1)
	  {
	    printf ("Unable to start TTF rendering\n");
	    SDL_Quit ();
	  }
      }
      else
	{
	  printf("err: can not set up SDL\n");
	  SDL_Quit();
	  return -1;
	}
    }
  else
    {
      printf("SDL was already inited\n");
    }

  screen = SDL_SetVideoMode (width, height, 32, video_flags);
  if (!screen)
    {
      printf ("[FATAL] can not set video mode properly!\n");
      exit (-1);
    }

  Mix_VolumeMusic(SDL_MIX_MAXVOLUME);

  if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 2048) ){
	  printf("[ERROR] Unable to open audio!\n");
	  exit(-1);
  }

  Mix_ChannelFinished(on_mix_halt);

  machine->screen = screen;

  if( !machine->game_world )
    {
      machine->game_world = SDL_CreateRGBSurface( SDL_SWSURFACE, width, height,
						  screen->format->BitsPerPixel,
						  screen->format->Rmask, screen->format->Gmask,
						  screen->format->Bmask, screen->format->Amask
						  );
    }

  SDL_Rect v = {0,0,machine->screen->w , machine->screen->h };
  MG_set_view_rect( v );

  MG_get_keys ();
  return 0;
}

MACHINE *
MG_get_machine ()
{
  return machine;
}

void
MG_quit ()
{
  MG_drawing_stack_free ();
  free_surfaces ();
  free_audio ();
  free_animations ();
  free_ttfs ();
  Mix_HaltMusic ();

  SDL_FreeSurface( machine->game_world );

  SDL_Quit ();
  TTF_Quit ();

}
