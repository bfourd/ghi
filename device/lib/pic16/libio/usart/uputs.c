
/*
 * uputs - put a string to USART
 *
 * written by Vangelis Rokas, 2004 <vrokas AT otenet.gr>
 *
 * Devices implemented:
 *	PIC18F[24][45][28]
 *
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
 *
 *
 * $Id: uputs.c 3711 2005-03-31 16:25:17Z vrokas $
 */


#include <pic18fregs.h>

#include <usart.h>

void usart_puts(char *dat)
{
  do {
    while( usart_busy() );
    usart_putc( *dat );
  } while( *dat++ );
}
