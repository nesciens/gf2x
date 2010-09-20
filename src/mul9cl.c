/* This file is part of the gf2x library.

   Copyright 2007, 2008, 2009, 2010
   Richard Brent, Pierrick Gaudry, Emmanuel Thome', Paul Zimmermann

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 2.1 of the License, or (at
   your option) any later version.
   
   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
   License for more details.
   
   You should have received a copy of the GNU Lesser General Public
   License along with CADO-NFS; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/
#ifndef GF2X_MUL9_H_
#define GF2X_MUL9_H_

#include "gf2x.h"
/* All gf2x source files for lowlevel functions must include gf2x-small.h
 * This is mandatory for the tuning mechanism. */
#include "gf2x/gf2x-small.h"

#include <wmmintrin.h>

#if GF2X_WORDSIZE != 64
#error "This code is for 64-bit only"
#endif

#include "gf2x/gf2x-config.h"

#ifndef HAVE_PCLMUL_SUPPORT
#error "This code needs pclmul support"
#endif

/* TODO: if somebody comes up with a neat way to improve the interface so
 * as to remove the false dependency on pclmul, that would be nice.
 */
static inline __v2di
GF2X_FUNC(mul9clk_c_mul1) (unsigned long a, unsigned long b)
{   
    __v2di aa = (__v2di) { a, 0 };
    __v2di bb = (__v2di) { b, 0 };
    return _mm_clmulepi64_si128(aa, bb, 0);
}

/* variant with 30 multiplications */
GF2X_STORAGE_CLASS_mul9
void gf2x_mul9 (unsigned long *c, const unsigned long *a, const unsigned long *b)
{
    /* Taken from Cenk & Ozbudak 2009 */
    /* We reserve one more to follow notations of the paper */
    unsigned long pa[31], pb[31];  

    pa[ 1] = a[0]^a[1]^a[2]^a[3]^a[4]^a[5]^a[6]^a[7]^a[8];
    pa[ 2] = a[0]^a[2]^a[4]^a[6]^a[8];
    pa[ 3] = a[1]^a[2]^a[3]^a[5]^a[8];
    pa[ 4] = a[0]^a[2]^a[3]^a[5]^a[6]^a[8];
    pa[ 5] = a[0]^a[1]^a[3]^a[4]^a[6]^a[7];
    pa[ 6] = a[0]^a[3]^a[4]^a[5]^a[7];
    pa[ 7] = a[1]^a[2]^a[3]^a[6]^a[8];
    pa[ 8] = a[2]^a[4]^a[5]^a[6];
    pa[ 9] = a[2]^a[3]^a[4]^a[6];
    pa[10] = a[1]^a[3]^a[5]^a[7];
    pa[11] = a[0]^a[1]^a[4]^a[6]^a[7]^a[8];
    pa[12] = a[0]^a[3]^a[5]^a[6]^a[7];
    pa[13] = a[0]^a[1]^a[4]^a[5]^a[8];
    pa[14] = a[1]^a[2]^a[4]^a[5]^a[7]^a[8];
    pa[15] = a[0]^a[1]^a[3]^a[6]^a[7]^a[8];
    pa[16] = a[1]^a[3]^a[4]^a[5]^a[8];
    pa[17] = a[0]^a[2]^a[3]^a[4]^a[7];
    pa[18] = a[1]^a[4]^a[5]^a[6]^a[8];
    pa[19] = a[0]^a[2]^a[5]^a[6]^a[7];
    pa[20] = a[2]^a[3]^a[6]^a[7];
    pa[21] = a[6]^a[8];
    pa[22] = a[0]^a[2];
    pa[23] = a[0]^a[1];
    pa[24] = a[0];
    pa[25] = a[1];
    pa[26] = a[7];
    pa[27] = a[7]^a[8];
    pa[28] = a[6];
    pa[29] = a[8];
    pa[30] = a[2];
    
    pb[ 1] = b[0]^b[1]^b[2]^b[3]^b[4]^b[5]^b[6]^b[7]^b[8];
    pb[ 2] = b[0]^b[2]^b[4]^b[6]^b[8];
    pb[ 3] = b[1]^b[2]^b[3]^b[5]^b[8];
    pb[ 4] = b[0]^b[2]^b[3]^b[5]^b[6]^b[8];
    pb[ 5] = b[0]^b[1]^b[3]^b[4]^b[6]^b[7];
    pb[ 6] = b[0]^b[3]^b[4]^b[5]^b[7];
    pb[ 7] = b[1]^b[2]^b[3]^b[6]^b[8];
    pb[ 8] = b[2]^b[4]^b[5]^b[6];
    pb[ 9] = b[2]^b[3]^b[4]^b[6];
    pb[10] = b[1]^b[3]^b[5]^b[7];
    pb[11] = b[0]^b[1]^b[4]^b[6]^b[7]^b[8];
    pb[12] = b[0]^b[3]^b[5]^b[6]^b[7];
    pb[13] = b[0]^b[1]^b[4]^b[5]^b[8];
    pb[14] = b[1]^b[2]^b[4]^b[5]^b[7]^b[8];
    pb[15] = b[0]^b[1]^b[3]^b[6]^b[7]^b[8];
    pb[16] = b[1]^b[3]^b[4]^b[5]^b[8];
    pb[17] = b[0]^b[2]^b[3]^b[4]^b[7];
    pb[18] = b[1]^b[4]^b[5]^b[6]^b[8];
    pb[19] = b[0]^b[2]^b[5]^b[6]^b[7];
    pb[20] = b[2]^b[3]^b[6]^b[7];
    pb[21] = b[6]^b[8];
    pb[22] = b[0]^b[2];
    pb[23] = b[0]^b[1];
    pb[24] = b[0];
    pb[25] = b[1];
    pb[26] = b[7];
    pb[27] = b[7]^b[8];
    pb[28] = b[6];
    pb[29] = b[8];
    pb[30] = b[2];

    __v2di p[31];
    
    int i;
    for (i = 1; i < 31; ++i)
        p[i] = GF2X_FUNC(mul9clk_c_mul1)(pa[i], pb[i]);

    __v2di cc[17];

    cc[0 ] = p[24];
    cc[1 ] = p[23]^p[24]^p[25];
    cc[2 ] = p[22]^p[24]^p[25]^p[30];
    cc[3 ] = p[29]^p[18]^p[3]^p[16]^p[8]^p[7]^p[6]^p[30]^p[22]^p[23]^p[13]^p[20]^p[10]^p[14]^p[12]^p[4]^p[27]^p[21]^p[28];
    cc[4 ] = p[5]^p[4]^p[11]^p[12]^p[7]^p[3]^p[9]^p[15]^p[10]^p[23]^p[24]^p[25]^p[2]^p[21]^p[28]^p[29]^p[26];
    cc[5 ] = p[27]^p[26]^p[29]^p[1]^p[10]^p[22]^p[24]^p[30]^p[25]^p[2]^p[4]^p[14]^p[15]^p[6]^p[19]^p[17]^p[12]^p[16];
    cc[6 ] = p[27]^p[13]^p[20]^p[22]^p[24]^p[30]^p[5]^p[4]^p[15]^p[6]^p[19]^p[23]^p[2]^p[21]^p[28];
    cc[7 ] = p[21]^p[28]^p[29]^p[26]^p[24]^p[1]^p[16]^p[8]^p[12]^p[7]^p[15]^p[6]^p[19];
    cc[8 ] = p[1]^p[24]^p[25]^p[11]^p[16]^p[8]^p[3]^p[19]^p[15]^p[18]^p[23]^p[27]^p[26]^p[29];
    cc[9 ] = p[22]^p[24]^p[30]^p[25]^p[1]^p[17]^p[12]^p[8]^p[11]^p[3]^p[9]^p[19]^p[6]^p[29];
    cc[10] = p[13]^p[1]^p[20]^p[10]^p[22]^p[30]^p[23]^p[4]^p[14]^p[17]^p[12]^p[8]^p[11]^p[21]^p[28]^p[29]^p[27];
    cc[11] = p[17]^p[12]^p[8]^p[11]^p[18]^p[6]^p[3]^p[1]^p[10]^p[5]^p[4]^p[23]^p[24]^p[25]^p[2]^p[21]^p[28]^p[29]^p[26];
    cc[12] = p[27]^p[26]^p[29]^p[9]^p[15]^p[6]^p[18]^p[11]^p[7]^p[17]^p[16]^p[4]^p[14]^p[2]^p[10]^p[22]^p[24]^p[30]^p[25];
    cc[13] = p[9]^p[19]^p[3]^p[16]^p[17]^p[6]^p[30]^p[22]^p[24]^p[23]^p[1]^p[13]^p[20]^p[2]^p[12]^p[5]^p[4]^p[27]^p[21]^p[28];
    cc[14] = p[21]^p[28]^p[29]^p[26];
    cc[15] = p[26]^p[27]^p[29];
    cc[16] = p[29];

    _mm_storeu_si128((__v2di*)(c),    cc[0]                           ^ _mm_slli_si128(cc[1], 8));
    _mm_storeu_si128((__v2di*)(c+2),  cc[2]  ^ _mm_srli_si128(cc[1], 8) ^ _mm_slli_si128(cc[3], 8));
    _mm_storeu_si128((__v2di*)(c+4),  cc[4]  ^ _mm_srli_si128(cc[3], 8) ^ _mm_slli_si128(cc[5], 8));
    _mm_storeu_si128((__v2di*)(c+6),  cc[6]  ^ _mm_srli_si128(cc[5], 8) ^ _mm_slli_si128(cc[7], 8));
    _mm_storeu_si128((__v2di*)(c+8),  cc[8]  ^ _mm_srli_si128(cc[7], 8) ^ _mm_slli_si128(cc[9], 8));
    _mm_storeu_si128((__v2di*)(c+10), cc[10] ^ _mm_srli_si128(cc[9], 8) ^ _mm_slli_si128(cc[11], 8));
    _mm_storeu_si128((__v2di*)(c+12), cc[12] ^ _mm_srli_si128(cc[11], 8) ^ _mm_slli_si128(cc[13], 8));
    _mm_storeu_si128((__v2di*)(c+14), cc[14] ^ _mm_srli_si128(cc[13], 8) ^ _mm_slli_si128(cc[15], 8));
    _mm_storeu_si128((__v2di*)(c+16), cc[16] ^ _mm_srli_si128(cc[15], 8));
}

#endif  /* GF2X_MUL9_H_ */
