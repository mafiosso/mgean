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

#ifndef TEXTLIST_H
#define TEXTLIST_H

enum HASH_TYPES
{ TUNKNOWN = 0x0, THASH, SYMBOL };

typedef struct HASH
{
  int type;
  NODE *values;
} HASH;

extern HASH *MG_hash_get_key (HASH * h, const char *key);
extern HASH *MG_hash_copy (HASH * h);
extern char *MG_hash_dump (HASH * h);
extern void MG_hash_free (HASH * h);
extern HASH *MG_text_list (const char *in);

#endif
