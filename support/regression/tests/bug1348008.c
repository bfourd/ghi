/*
   bug1348008.c
*/

#include <testfwk.h>

#ifndef PORT_HOST

void foo(void) { }

void IRQ_ISR(void) interrupt
{
  foo();
}

#endif

void testBug(void)
{
}
