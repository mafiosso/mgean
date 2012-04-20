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

int
intersect_p_line (int x1, int w1, int x2, int w2)
{

  if (((x2 + w2) >= x1) && (x2 <= (x1 + w1)))
    return 1;

  return 0;
}

int
intersect_p_rect (SDL_Rect * rct1, SDL_Rect * rct2)
{
  if (intersect_p_line (rct1->x, rct1->w, rct2->x, rct2->w))
    {
      if (intersect_p_line (rct1->y, rct1->h, rct2->y, rct2->h))
	{
	  return 1;
	}
    }

  return 0;
}
