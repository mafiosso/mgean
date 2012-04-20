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
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "MG_lib.h"
//#include "audio.h"
//#include "list.h"

void
MG_play_music (int *channel, int ms_expire, int current_time, Mix_Chunk * m)
{
  if ((current_time < ms_expire) || !m)
    return;

  if (*channel == -1)
    {
      *channel = Mix_PlayChannelTimed (-1, m, 1, ms_expire);
      printf ("got channel: %d\n", *channel);
    }
  else
    {
      Mix_HaltChannel (*channel);
      Mix_PlayChannelTimed (*channel, m, 1, ms_expire);
    }
}

void MG_sprite_play_music( SPRITE * self )
{
	if( !self->anim || !self->anim->music )
		return;

	int expire = self->anim->delay*self->anim->count;

	if( self->audio_state.channel < 0 )
	{
		self->audio_state.channel = Mix_PlayChannel( -1 , self->anim->music , -1 );
		self->audio_state.played_time = 0;
		return;
	}

	self->audio_state.played_time += MG_get_system_dt();
	if( self->audio_state.played_time >= expire ){
		if( Mix_Playing( self->audio_state.channel ) ){
//			Mix_HaltChannel( self->audio_state.channel );
			Mix_FadeOutChannel( self->audio_state.channel , MG_get_system_dt()*2 );
		}

		self->audio_state.channel = -1;

		if( self->audio_state.repeat ){
			MG_sprite_play_music( self );
		}

	}

}
