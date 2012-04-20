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

#ifndef DRAWING_H
#define DRAWING_H

extern SDL_Rect MG_rects_cut (SDL_Rect r1, SDL_Rect r2);
extern void MG_invalidate_rect (SDL_Rect rect);
extern void MG_update_screen ();
extern int MG_null_rect_p (SDL_Rect rect);

#endif
