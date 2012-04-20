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

#ifndef PHYSIC_H
#define PHYSIC_H

/** POINT structure */
typedef struct POINT
{
  /** read-write axis variables */
  int x, y;
} POINT;

/** VECTOR structure */
typedef struct VECTOR
{
  /** read-write axis variable x */
  float x;
  /** read-write axis variable y */
  float y;
} VECTOR;

/** PHYSICS structure */
typedef struct PHYSICS
{
  /** read-write wieght variable */
  float m;
  /** read-write force vector */
  VECTOR f;
  /** read-write speed vector */
  VECTOR v;
} PHYSICS;

/** gets delta time between two calls MG_draw_stack
    
    \returns time in milliseconds
 */
extern int MG_get_system_dt ();

/** computes new physics state corresponding to dt
    
    \param p in/out physics that can not be NULL, otherwise segfaulting
 */
extern void MG_compute_physics (PHYSICS * p);

/** sets global physic frequently used for setting gravitation or wind 
    \param env_physics physics of environment
*/
extern void MG_set_environment_physics (VECTOR env_physics);

#endif
