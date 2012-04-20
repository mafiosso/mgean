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

#ifndef ANIMATION_H
#define ANIMATION_H

/** ANIMATION structure, any of variables are read-only for user*/
typedef struct ANIMATION
{
  /** array of animation rectangles, its length should be same as count */
  SDL_Rect *anim_array;
  /** current rectangle in animation sequence */
  SDL_Rect rect;
  /** count of rectangles in animation sequence */
  Uint32 count;
  /** delay between two frames */
  Uint32 delay;
  /** audio chunk played until animation ends */
  Mix_Chunk *music;
} ANIMATION;

/** makes new animation, in this case rectangles must be side by side in source bitmap

    \param s a string identifier of animation
    \param count how many rects the animation has
    \param delay time between two frames (in milliseconds)
    \param r initial rectangle   

    \returns newly created ANIMATION object
*/
extern ANIMATION *MG_make_animation (const char *s, int count, Uint32 delay,
				     SDL_Rect * r);

/** sets to an existing animation the animation rects, which allow more flexibility - the rects can be everywhere in source bitmap

    \param a animation
    \param rects array of rects with length a->count
*/
extern void MG_set_animation_rects (ANIMATION * a, SDL_Rect * rects);

/** gets animation by identifier

    \param string identifier of animation
    \returns existing ANIMATION or NULL when not found    
*/
extern ANIMATION *MG_get_animation (const char *string);

/** sets audio to an animation
    
    \param a animation
    \param s identifier of an audio file
 */
extern void MG_set_audio (ANIMATION * a, const char *s);

SDL_Rect get_frame (ANIMATION * a, int *delayed);
void free_animations ();

#endif
