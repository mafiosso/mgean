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

#ifndef LOAD_H
#define LOAD_H
#include <SDL/SDL_ttf.h>

/** preloads an image of type .bmp, .png, .jpeg

    \param path is a path to source pixmap
    \returns -1 if something went wrong 0 on success
 */
extern int MG_preload_img (const char *path);

/** gets image from MGEAN cache, when not used before is it preloaded

    \param path path to pixmap
    \returns a SDL surface when all ok otherwise NULL
*/
extern SDL_Surface *MG_get_img (const char *path);

/** preloads audio of type .wav, .ogg 

    \param path path to a audio file
    \returns 0 on success -1 on fail
*/
extern int MG_preload_audio (const char *path);

/** gets audio, caching is used

    \param path path to file
    \returns chunk of audio file
*/
extern Mix_Chunk *MG_get_audio (const char *path);

extern void MG_set_system_font_size (int size);
extern TTF_Font *MG_preload_ttf (const char *path);
extern TTF_Font *MG_get_ttf (const char *path);

void free_surfaces ();
void free_audio ();
void free_animations ();
void free_ttfs ();

#endif
