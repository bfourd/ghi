
/*
 * ugetc - get received character
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
 * $Id: ugetc.c 3711 2005-03-31 16:25:17Z vrokas $
 */


#include <pic18fregs.h>

#include <usart.h>

extern union USART USART_Status;

unsigned char usart_getc(void)
{
  USART_Status.val &= 0xf0;

  if(RCSTAbits.RX9) {
    USART_Status.RX_NINE = 0;
    if(RCSTAbits.RX9D)
      USART_Status.RX_NINE = 1;
  }

  if(RCSTAbits.FERR)
    USART_Status.FRAME_ERROR = 1;

  if(RCSTAbits.OERR)
    USART_Status.OVERRUN_ERROR = 1;

  return (RCREG);
}
