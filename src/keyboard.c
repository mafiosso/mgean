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
#include "list.h"
#include "init.h"

//#include "MG_lib.h"

int
MG_key_down_p (int key)
{
  MACHINE *m = MG_get_machine ();

  return m->keyboard_state[key];
}

void
MG_get_keys ()
{
  MACHINE *m;
  m = MG_get_machine ();
  MG_remove_list (m->events, free);
  m->events = NULL;

  SDL_Event ev;
  while (SDL_PollEvent (&ev))
    {
      SDL_Event *e = (SDL_Event *) malloc (sizeof (SDL_Event));
      *e = ev;
      MG_add (&(m->events), e);
    }

  m->keyboard_state = SDL_GetKeyState (NULL);
  m->mouse.state = SDL_GetMouseState (&m->mouse.x, &m->mouse.y);
}

Uint8
MG_get_mouse_state ()
{
  MACHINE *m = MG_get_machine ();
  return m->mouse.state;
}

int
MG_get_mouse_x ()
{
  MACHINE *m = MG_get_machine ();
  return m->mouse.x+m->view_rect.x;
}

int
MG_get_mouse_y ()
{
  MACHINE *m = MG_get_machine ();
  return m->mouse.y+m->view_rect.y;
}
