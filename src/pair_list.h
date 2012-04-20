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

#ifndef PAIR_LIST_H
#define PAIR_LIST_H

extern void MG_add_pair (NODE ** list, const char *key, void *value);
extern void *MG_get_nth (NODE * list, const char *symbolic_id);
extern void MG_destroy_pair (NODE * l, void (*func) (void *value));
#endif
