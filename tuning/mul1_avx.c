/* This file is part of the gf2x library.

   Copyright 2007,2008,2009
   Richard Brent, Pierrick Gaudry, Emmanuel Thome', Paul Zimmermann

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2 of the License, or (at your
   option) any later version.

   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   You should have received a copy of the GNU General Public License along
   with this program; see the file COPYING.  If not, write to the Free
   Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
   02111-1307, USA.
*/

/* 64-bit multiplication routine over GF(2)[x], using AVX. */

/* assumes unsigned long is 64 bit */

#include <wmmintrin.h>

/* cf http://www.intel.com/software/products/compilers/docs/clin/main_cls/intref_cls/common/intref_aes_intrinsics.htm */

/* c[0,1] <- a * b */
static unsigned long
mul1 (unsigned long *c, unsigned long a, unsigned long b)
{
  __m128i v1[1] = {a, 0};
  __m128i v2[1] = {b, 0};
  __m128i v3;
  __m128i *v4 = (__m128i*) c;

  v3 = _mm_clmulepi64_si128(__m128i v1, __m128i v2, 0);
  v4[0] = v4;
}
