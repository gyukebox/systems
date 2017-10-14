/* Testing Code */

#include <limits.h>
/* Copyright (C) 1991-2014 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
long test_isZero(long x) {
  return x == 0;
}
long test_bitOr(long x, long y)
{
  return x|y;
}
long test_bitAnd(long x, long y)
{
  return x&y;
}
long test_minusOne(void) {
  return -1;
}
long test_negate(long x) {
  return -x;
}
long test_bitXor(long x, long y)
{
  return x^y;
}
long test_isPositive(long x) {
  return x > 0;
}
long test_getByte(long x, long n)
{
  union {
    long word;
    unsigned char bytes[8];
  } u;
  long test = 1;
  long littleEndian = (long) *(char *) &test;
  u.word = x;
  return littleEndian ? (unsigned) u.bytes[n] : (unsigned) u.bytes[7-n];
}
long test_isNotEqual(long x, long y)
{
  return x != y;
}
long test_evenBits(void) {
   long result = 0;
   long i = 0;
   for (i = 0 ; i < 32 ; i += 2) {
       result |= 1 << i;
   }
   result = result << 32;
   for (i = 0 ; i < 32 ; i += 2) {
       result |= 1 << i;
   }
   return result;
}
long test_reverseBytes(long x)
{
  union U {
    long result;
    char byte[8];
  };
  union U u;
  char temp;
  u.result = x;
  temp = u.byte[0];
  u.byte[0] = u.byte[7];
  u.byte[7] = temp;
  temp = u.byte[1];
  u.byte[1] = u.byte[6];
  u.byte[6] = temp;
  temp = u.byte[2];
  u.byte[2] = u.byte[5];
  u.byte[5] = temp;
  temp = u.byte[3];
  u.byte[3] = u.byte[4];
  u.byte[4] = temp;
  return u.result;
}
long test_conditional(long x, long y, long z)
{
  return x?y:z;
}
long test_isGreater(long x, long y)
{
  return x > y;
}
long test_bang(long x)
{
  return !x;
}
