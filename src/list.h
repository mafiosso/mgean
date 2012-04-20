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

#ifndef LIST_H
#define LIST_H

typedef struct NODE
{
  void *value;
  struct NODE *node;
} NODE;

extern void MG_add (NODE ** root, void *value);
extern void MG_destructive_map (NODE * list, void (*func) (void *value));
extern void *MG_remove_node (NODE ** l, void *value);
extern NODE *MG_add_nth (NODE ** l, void *val, int nth);
extern int MG_list_length (NODE * l);
extern void MG_remove_list (NODE * list, void (*func) (void *rm));
extern void *MG_list_nth (NODE * l, int n);

#endif
