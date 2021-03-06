/*-------------------------------------------------------------------------
   _mullong.c - routine for multiplication of 32 bit (unsigned) long

             Written By -  Jean Louis VERN jlvern@writeme.com (1999)
             Written By -  Sandeep Dutta . sandeep.dutta@usa.net (1999)

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

/* Signed and unsigned multiplication are the same - as long as the output
   has the same precision as the input.

   Assembler-functions are provided for:
     mcs51 small
     mcs51 small stack-auto
*/


struct some_struct {
	short a ;
	char b;
	long c ;};
union bil {
        struct {unsigned char b3,b2,b1,b0 ;} b;
        struct {unsigned short hi,lo ;} i;
        unsigned long l;
        struct { unsigned char b3; unsigned short i12; unsigned char b0;} bi;
} ;

#  define bcast(x) ((union bil *)&(x))

/*
                     3   2   1   0
       X             3   2   1   0
       ----------------------------
                   0.3 0.2 0.1 0.0
               1.3 1.2 1.1 1.0
           2.3 2.2 2.1 2.0
       3.3 3.2 3.1 3.0
       ----------------------------
                  |3.3|1.3|0.2|0.0|   A
                    |2.3|0.3|0.1|     B
                    |3.2|1.2|1.0|     C
                      |2.2|1.1|       D
                      |3.1|2.0|       E
                        |2.1|         F
                        |3.0|         G
                          |-------> only this side 32 x 32 -> 32
*/
long
_mullong (long a, long b)
{
        union bil t;

        t.i.hi = bcast(a)->b.b0 * bcast(b)->b.b2;       // A
        t.i.lo = bcast(a)->b.b0 * bcast(b)->b.b0;       // A
        t.b.b3 += bcast(a)->b.b3 *
                                  bcast(b)->b.b0;       // G
        t.b.b3 += bcast(a)->b.b2 *
                                  bcast(b)->b.b1;       // F
        t.i.hi += bcast(a)->b.b2 * bcast(b)->b.b0;      // E <- b lost in .lst
        // bcast(a)->i.hi is free !
        t.i.hi += bcast(a)->b.b1 * bcast(b)->b.b1;      // D <- b lost in .lst

        bcast(a)->bi.b3 = bcast(a)->b.b1 *
                                          bcast(b)->b.b2;
        bcast(a)->bi.i12 = bcast(a)->b.b1 *
                           bcast(b)->b.b0;              // C

        bcast(b)->bi.b3 = bcast(a)->b.b0 *
                                          bcast(b)->b.b3;
        bcast(b)->bi.i12 = bcast(a)->b.b0 *
                           bcast(b)->b.b1;              // B
        bcast(b)->bi.b0 = 0;                            // B
        bcast(a)->bi.b0 = 0;                            // C
        t.l += a;

        return t.l + b;
}

