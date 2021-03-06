/*
 * putchar.c - putchar dummy function
 *
 * written by Vangelis Rokas, 2005 (vrokas@otenet.gr)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
** $Id: putchar.c 3714 2005-04-02 13:13:53Z vrokas $
 */

#include <stdio.h>

/* this is a dummy function so that sources compile,
 * even when user doesn't give a putchar() function.
 * NOTE that putchar() is declared in stdio.h to
 * have the argument in WCHAR (via the wparam pragma) */

PUTCHAR(c)
{
  c;
  __asm
    return
  __endasm;
}
