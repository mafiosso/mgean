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

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include"list.h"
#include"pair_list.h"
#include "text_list.h"

HASH *
MG_hash_get_key (HASH * h, const char *key)
{
  if (h->type == SYMBOL)
    {
      printf ("mg_err: can not get key from symbol!\n");
      return NULL;
    }

  int i = 0;
  NODE *tmp = h->values;

  while (tmp)
    {
      HASH *value = tmp->value;

      if (!value)
	return NULL;

      if (value->type == SYMBOL && !(i % 2))
	{
	  if (!(strcmp (key, (char *) value->values)))
	    {
	      if (tmp->node)
		{
		  return (HASH *) tmp->node->value;
		}
	      return NULL;
	    }
	}
      tmp = tmp->node;
      i++;
    }

  return NULL;
}

HASH *
MG_hash_copy (HASH * h)
{
  HASH *out = (HASH *) malloc (sizeof (HASH));
  out->type = h->type;
  out->values = NULL;

  if (h->type == SYMBOL)
    {
      out->values = (void *) strdup ((char *) h->values);
      return out;
    }

  NODE *it = h->values;
  while (it)
    {
      HASH *ct = MG_hash_copy ((HASH *) it->value);
      MG_add (&(out->values), ct);

      it = it->node;
    }
  return out;
}

static char *
string_append (const char *s1, const char *s2)
{
  int s1l = s1 ? strlen (s1) : 0;
  int s2l = s2 ? strlen (s2) : 0;
  int total_len = sizeof (char) * (s1l + s2l + 1);
  char *out = (char *) malloc (total_len);
  memset (out, 0, total_len);

  if (s1)
    strcpy (out, s1);
  if (s2)
    strcat (out, s2);

  return out;
}

char *
MG_hash_dump (HASH * h)
{
  char *out = NULL;
  char *working_txt = NULL;

  if (h->type == SYMBOL)
    {
      char *symbol = (char *) h->values;

      if (!symbol)
	return NULL;

      char *out = (char *) malloc (sizeof (char) * (2 + strlen (symbol)));
      sprintf (out, "%s ", symbol);
      return out;
    }
  else if (h->type == THASH)
    {
      out = string_append (out, "(");

      NODE *tmp = h->values;
      while (tmp)
	{
	  char * deep = MG_hash_dump ((HASH *) tmp->value);
	  working_txt =
	    string_append (out, deep);
	  free (out);
	  free (deep);
	  out = working_txt;

	  tmp = tmp->node;
	}

      working_txt = string_append (out, ")");
      free (out);
      out = working_txt;
      return out;
    }

  return NULL;
}

void
MG_hash_free (HASH * h)
{
  if (h->type == SYMBOL)
    {
      free (h->values);
    }
  else if (h->type == THASH)
    {
      MG_remove_list (h->values, (void (*)(void *)) MG_hash_free);
    }
  free( h );
}

#ifdef WIN32
static char *
strndup (const char *str, unsigned int n)
{
  char *out = (char *) malloc (sizeof (char) * (n + 1));
  int i = 0;

  memset (out, 0, sizeof (char) * (n + 1));

  while (str[i] && i < n)
    {
      out[i] = str[i];
      i++;
    }
  return out;
}
#endif


/* example ((((a b c)))) */
static int
string_syntactic_check (const char *str)
{
  int parity = 0;
  char *txt = (char *) str;

  while (*txt)
    {
      if (*txt == '(')
	{
	  parity++;
	}
      else if (*txt == ' ' || *txt == '\n')
	{
	  if (*(txt - 1) == '(')	/* space can not be between left bracket and string */
	    return 0;
	}
      else if (*txt == ')')
	{
	  parity--;
	}
      else if (!parity && (*txt != ' ' || *txt != '\n'))	/* if we are out of brackets and no empty char is given */
	{
	  return 0;
	}

      txt++;
    }

  return !parity;		/* if parity is 0 return true else false */
}

static char *
get_plain_string (const char *str, char **end)
{
  char *str_ptr = (char *) str;
  int parity = 0;
  char c;
  int len = 0;
  char *begin_ptr;
  int spaces_count = 0;

  while (c = *str_ptr)
    {
      if ((c == '\n' || c == ' ') && !parity)
	{
	  spaces_count++;
	}
      else if (!parity && c != ')')
	{
	  parity++;
	  begin_ptr = str_ptr;
	}
      else if (parity && (c == ' ' || c == '\n' || c == ')'))
	{
	  char *out = strndup (begin_ptr, len + 1);

	  *end = str_ptr;
	  return out;
	}
      else if (!parity && c == ')')	/* no more symbol */
	{
	  *end = str_ptr;
	  return NULL;
	}
      else if (parity && c)
	{
	  len++;
	}

      str_ptr++;
    }

  *end = str_ptr;
  return NULL;			/* unterminated symbol */
}

HASH *
text_list_impl (const char *in, char **end_ptr, int *list_p)
{
  char *in_ptr = (char *) in;
  int parity = 0;
  int i = 0;			/* pair tracking */
  char c;
  HASH *out = (HASH *) malloc (sizeof (HASH));
  memset (out, 0, sizeof (HASH));
  out->type = THASH;

  int l_p;

  while ((c = *(in_ptr++)))
    {
      if (!parity && (c == ' ' || c == '\n'))
	{
	  continue;
	}
      else if (c == '(' && !parity)
	{
	  parity++;
	  *list_p = 1;
	}
      else if (parity && c != ')')
	{
	  char *e_ptr;
	  void *val = text_list_impl (in_ptr - 1, &e_ptr, &l_p);
	  if (val)
	    {
	      out->type = THASH;
	      MG_add (&(out->values), val);
	    }

	  in_ptr = e_ptr;
	}
      else if (!parity)		/* it is plain symbol only - "blah" */
	{
	  char *e;
	  char *txt_out;

	  txt_out = get_plain_string (in_ptr - 1, &e);
	  *end_ptr = e;

	  if (!txt_out)
	    {
	      free (out);
	      return NULL;
	    }

	  out->type = SYMBOL;
	  out->values = (NODE *) txt_out;

	  return out;
	}
      else if (c == ')')
	{
	  if (!parity)
	    {
	      printf ("ERROR: mismatched right parenthesis\n");
	      if (out)
		{
		  MG_remove_list (out->values, (void (*)(void *)) free);
		}
	      *end_ptr = in_ptr;
	      return NULL;
	    }
	  else
	    {
	      *end_ptr = in_ptr;
	      return out;
	    }
	}
      else
	{
	  printf ("ERROR: unknown when parsing\n");
	  *end_ptr = in_ptr;
	  return NULL;
	}
    }

  printf ("ERROR: parity check not successfull!\n");

  return NULL;
}

/*
  fmt:
  (:a b :c (:d e :f g ))
*/
HASH *
MG_text_list (const char *in)
{
  char *end_str;
  int list_p = 0;

  if (!string_syntactic_check (in))
    {
      printf ("MG: warn: bad syntax - list!\n");
      return NULL;
    }

  return text_list_impl (in, &end_str, &list_p);
}
