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

#ifndef MG_INIT_H
#define MG_INIT_H

typedef struct MOUSE
{
  int x, y;
  Uint8 state;
} MOUSE;

typedef struct MACHINE
{
  SDL_Surface *screen;
  SDL_Surface *game_world;
  Uint8 *keyboard_state;
  MOUSE mouse;
//  Uint8 use_audio;
  NODE *events;
  SDL_Rect view_rect;
} MACHINE;

extern void MG_set_view_rect( SDL_Rect r );
extern SDL_Surface * MG_set_world( int w , int h );
extern MACHINE *MG_get_machine ();
extern int MG_init_video (int width, int height, Uint32 video_flags);
extern void MG_quit ();

#endif
