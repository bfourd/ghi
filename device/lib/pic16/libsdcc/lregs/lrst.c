/*-------------------------------------------------------------------------

   lrst.c :- store local registers in stack upon function entry

   Written for pic16 port by Vangelis Rokas, 2004 (vrokas@otenet.gr)

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU Library General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this program; if not, write to the Free Software
   Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   In other words, you are welcome to use, share and improve this program.
   You are forbidden to forbid anyone else to use, share and improve
   what you give them.   Help stamp out software-hoarding!
-------------------------------------------------------------------------*/
/*
** $Id: lrst.c 3835 2005-08-07 20:09:11Z tecodev $
*/

/* FSR0 points to first register to store, WREG holds the register count
 */
 
extern POSTDEC1;
extern POSTINC0;
extern WREG;

void _lr_store(void) __naked
{
  __asm
loop:
    movff	_POSTINC0, _POSTDEC1
    decfsz	_WREG, f
    bra		loop
    
    return
  __endasm;
}
