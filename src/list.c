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
#include<stdlib.h>
#include"list.h"

static NODE *
make_node (void *val, NODE * next)
{
  NODE *out = (NODE *) malloc (sizeof (NODE));
  out->value = val;
  out->node = next;
  return out;
}

void
MG_add (NODE ** root, void *value)
{
  if (*root == NULL)
    {
      *root = (NODE *) malloc (sizeof (NODE));
      (*root)->value = value;
      (*root)->node = NULL;
      return;
    }
  NODE *child;
  NODE *temp;
  child = (NODE *) malloc (sizeof (NODE));
  child->value = value;
  child->node = NULL;
  temp = *root;
  while (temp->node)
    {
      temp = temp->node;
    }
  temp->node = child;
}

void
MG_destructive_map (NODE * list, void (*func) (void *value))
{
  NODE *tmp = list;
  while (tmp)
    {
      func (tmp->value);
      tmp = tmp->node;
    }
}

void
MG_remove_list (NODE * list, void (*func) (void *rm))
{
  NODE *tmp = list;
  NODE *to_rm = list;

  while (tmp)
    {
      to_rm = tmp;

      if (func)
	func (tmp->value);

      tmp = tmp->node;
      free (to_rm);
    }
}

void *
MG_remove_node (NODE ** l, void *value)
{
  NODE *tmp = *l;
  NODE *prev = NULL;
  void *v;

  while (tmp)
    {
      if (tmp->value == value)
	{
	  v = tmp->value;

	  if (!prev)		/* at begin */
	    {
	      *l = tmp->node;
	      free (tmp);
	      return v;
	    }
	  prev->node = tmp->node;
	  free (tmp);
	  return v;
	}

      prev = tmp;
      tmp = tmp->node;
    }
  return NULL;
}

NODE *
MG_add_nth (NODE ** l, void *val, int nth)
{
  int i = 0;
  NODE *prev = NULL;
  NODE *tmp = NULL;
  NODE *out = make_node (val, NULL);

  if (*l)
    {
      tmp = *l;
    }
  else
    {
      *l = out;
      return out;
    }

  while (tmp)
    {
      if (i == nth)
	{
	  if (prev)
	    {
	      out->node = prev->node;
	      prev->node = out;
	    }
	  else
	    {
	      out->node = *l;
	      *l = out;
	    }
	  return out;
	}
      i++;
      prev = tmp;
      tmp = tmp->node;
    }

  tmp = prev;
  tmp->node = out;
  out->node = NULL;
  return out;
}

int
MG_list_length (NODE * l)
{
  int i = 0;
  NODE *tmp = l;
  while (tmp)
    {
      i++;
      tmp = tmp->node;
    }
  return i;
}

void *
MG_list_nth (NODE * l, int n)
{
  int i = 0;
  NODE *tmp = l;

  while (tmp && (i < n))
    {
      tmp = tmp->node;
      i++;
    }

  if (!tmp)
    return NULL;

  return tmp->value;
}
