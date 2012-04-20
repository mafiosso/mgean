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
#include "physics.h"

#define GRAVITY 0.000001

static VECTOR g_environment_physics = { 0.0f, 0.000001f };

void
MG_compute_physics (PHYSICS * p)
{
  if (p->m <= 0)
    return;


  VECTOR a;
  a.x = p->f.x / p->m;
  a.x += g_environment_physics.x;
  a.y = p->f.y / p->m;
  a.y += g_environment_physics.y;
  p->v.x += a.x * (MG_get_system_dt ());
  p->v.y += a.y * (MG_get_system_dt ());
}

void
MG_set_environment_physics (VECTOR env_physics)
{
  g_environment_physics = env_physics;
}
