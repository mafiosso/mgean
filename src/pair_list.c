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
#include<string.h>
#include<stdlib.h>
#include"list.h"

void
MG_add_pair (NODE ** list, const char *key, void *value)
{
  char *_key = strdup (key);
  MG_add (list, _key);
  MG_add (list, value);
}

void *
MG_get_nth (NODE * list, const char *symbolic_id)
{
  NODE *tmp = list;
  int i = 0;

  while (tmp)
    {
      if (!(i % 2) && strcmp (symbolic_id, (char *) tmp->value) == 0)
	{
	  tmp = tmp->node;
	  if (tmp)
	    return tmp->value;
	  return NULL;		/* malformed pair! */
	}
      tmp = tmp->node;
      i++;
    }
  return NULL;
}

void
MG_destroy_pair (NODE * l, void (*func) (void *value))
{
  int i = 0;
  NODE *tmp = l;
  NODE *to_remove = tmp;

  while (tmp)
    {
      if (!(i % 2))
	{
	  free (tmp->value);
	}
      else
	{
	  if (func)
	    func (tmp->value);
	}
      tmp->value = NULL;

      to_remove = tmp;
      tmp = tmp->node;
      free (to_remove);
      to_remove = NULL;
      i++;
    }
}
