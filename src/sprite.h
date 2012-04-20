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

#ifndef SPRITE_H
#define SPRITE_H
#include "audio.h"

/** SPRITE structure
*/
typedef struct SPRITE
{
  /** private variable that references an animation, should not be changed directly from user code
   */
  ANIMATION *anim;
  /** read-only variable that describes a rectangle in surface, which is recently drawn
   */
  SDL_Rect src;

  /** read-only variable describing destination area of sprite in world
   */
  SDL_Rect dest;

  /** read-only holding pointer to a surface used for drawing
   */
  SDL_Surface *img;
  /** read-only additional arguments of sprite where are stored keys and callbacks
   */
  NODE *args;
  /** read-only list of attached sprites
   */
  NODE *attached_sprites;
  /** read-write physics descriptor
   */
  PHYSICS physics;
  /** unvisible variable used for inner animation handling 
   */
  int time;
  /** read-only audio state
   */
  AUDIO audio_state;
  /** read-write used for storing obligate type to fast recognition of object type
   */
  int type;
} SPRITE;

#define TYPE_UNKNOWN 0

/** makes sprite and pushes it on the drawing stack
    
    \param s argument expects a valid SDL_Surface * or NULL [in]
    \param src is a rectangle specifying drawing area from s [in]

    \returns pointer to the newly created sprite, it must not be explicitly freed
*/

extern void *MG_send_msg (SPRITE * s, const char *msg);
extern void MG_set_rect (SPRITE * self, SDL_Rect r);
extern void MG_set_srcrect (SPRITE * self, SDL_Rect r);

extern SPRITE *MG_make_sprite (SDL_Surface * s, SDL_Rect * src);
/** makes sprite and places it on the nth position 
    \param s argument expects a valid SDL_Surface * or NULL [in]
    \param src is a rectangle specifying drawing area from s [in]
    \param nth specifies order of output SPRITE on drawing stack [in]
    
    \returns pointer to the newly created sprite, it must not be explicitly freed
 */
extern SPRITE *MG_make_sprite_nth (SDL_Surface * s, SDL_Rect * src, int nth);

/** draws everything on drawing stack, apllies physics and messaging

    \param delay is a number specifing how much time should one frame take [in]
 */
extern void MG_draw_stack (int delay);

/** sets animation to a sprite
   
   \param s is a sprite on which should be the animation set
   \param string specifies identifier of animation
 */
extern void MG_set_animation (SPRITE * s, const char *string);

/** sets power to a sprite

    \param s is sprite
    \param v pointer to vector with power
 */
extern void MG_set_power (SPRITE * s, VECTOR * v);

/** sets speed to a sprite
    
    \param s is a sprite
    \param v is vector with speed
 */
extern void MG_set_speed (SPRITE * s, VECTOR * v);

/** sets weight to a sprite

    \param s is a sprite
    \param m weight in kg
 */
extern void MG_set_weight (SPRITE * s, float m);

/** installs callback function to a sprite
    
    \param s is a sprite
    \param key is an identifier of message
    \param function is a callback function
 */
extern void MG_install_callback (SPRITE * s, const char *key,
				 void (*function));

/** sets a key to a sprite

    \param s is a sprite
    \param key is an indentifier to a value key
    \param val pointer to user defined value (should be on heap)
*/
extern void MG_set_key (SPRITE * s, const char *key, void *val);

/** gets key from a sprite, can be also used for getting callbacks
    
    \param s sprite
    \param key identifier of pair

    \returns a pointer to value, NULL when not set
 */
extern void *MG_get_key (SPRITE * s, const char *key);

/** sets image to a sprite
    
    \param self a sprite
    \param surf a surface

    \returns the same as surf was set when everything went ok, otherwise NULL
 */
extern SDL_Surface *MG_set_img (SPRITE * self, SDL_Surface * surf);

/** removes sprite from drawing stack and fires "on_destroy" message, the sprite object is implicitly freed

    \param s is a sprite
 */
extern void MG_remove_sprite (SPRITE * s);

/** moves sprite

    \param s moving sprite
    \param dx delta in x axis
    \param dy delta in y axis
 */
extern void MG_move_sprite (SPRITE * s, int dx, int dy);

/** returns current drawing stack state

    \returns drawing stack list
*/
extern NODE *MG_drawing_stack ();

/** clears keys and callbacks of sprite
    
    \param s is a sprite    
*/
extern void MG_unload_sprite (SPRITE * s);

/** frees everything on drawing stack and sets it to NULL
 */
extern void MG_drawing_stack_free ();

/** attaches sprite to an other one, so the attached sprite will move with owner and messages from owner will be populated to the attached

    \param owner to which sprite are we attaching
    \param attached attachement to owner
 */
extern void MG_attach_sprite (SPRITE * owner, SPRITE * attached, int offset_x,
			      int offset_y);

/** detaches previously attached sprite
    
    \param owner owner of attached sprite
    \param attached attached sprite

    \returns attached sprite which is left on drawing stack
 */
extern SPRITE *MG_detach_sprite (SPRITE * owner, SPRITE * attached);

/** sets absolute position to the sprite
    
    \param s is a sprite
    \param x axis
    \param y axis
 */
extern void MG_sprite_set_position (SPRITE * s, int x, int y);

/** applies physics to a rect

    \param p physics descriptor
    \param r rectangle
    \param dt delta time

    \returns rect with new position computed with inner physics computation priciple   
 */
extern SDL_Rect MG_apply_physics (PHYSICS * p, SDL_Rect r, int dt);
extern void MG_transform_sprites( SPRITE * (*filter_func)( SPRITE * s ) , int move_x , int move_y );

extern void MG_sprite_play_music( SPRITE * self );

#endif

