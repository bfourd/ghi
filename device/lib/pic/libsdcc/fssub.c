/*
** libgcc support for software floating point.
** Copyright (C) 1991 by Pipeline Associates, Inc.  All rights reserved.
** Permission is granted to do *anything* you want with this file,
** commercial or otherwise, provided this message remains intact.  So there!
** I would appreciate receiving any updates/patches/changes that anyone
** makes, and am willing to be the repository for said changes (am I
** making a big mistake?).
**
** Pat Wood
** Pipeline Associates, Inc.
** pipeline!phw@motown.com or
** sun!pipeline!phw or
** uunet!motown!pipeline!phw
*/

/*
** $Id: fssub.c 4776 2007-04-29 13:15:51Z borutr $
*/

/* (c)2000/2001: hacked a little by johan.knol@iduna.nl for sdcc */

#include <float.h>

union float_long
  {
    float f;
    long l;
  };

/* subtract two floats */
float __fssub (float a1, float a2) _FS_REENTRANT
{
  FS_STATIC volatile union float_long fl1, fl2;

  fl1.f = a1;
  fl2.f = a2;

  /* check for zero args */
  if (!fl2.l)
    return (fl1.f);
  if (!fl1.l)
    return (-fl2.f);

  /* twiddle sign bit and add */
  fl2.l ^= SIGNBIT;
  return fl1.f + fl2.f; 
}
