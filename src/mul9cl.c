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
    __v2di ab[9] = {
        (__v2di) { a[0], b[0] },
        (__v2di) { a[1], b[1] },
        (__v2di) { a[2], b[2] },
        (__v2di) { a[3], b[3] },
        (__v2di) { a[4], b[4] },
        (__v2di) { a[5], b[5] },
        (__v2di) { a[6], b[6] },
        (__v2di) { a[7], b[7] },
        (__v2di) { a[8], b[8] },
    };
    __v2di pab[30];


    pab[ 0] = ab[0]^ab[1]^ab[2]^ab[3]^ab[4]^ab[5]^ab[6]^ab[7]^ab[8];
    pab[ 1] = ab[0]^      ab[2]^      ab[4]^      ab[6]^      ab[8];
    pab[ 2] =       ab[1]^ab[2]^ab[3]^      ab[5]^            ab[8];
    pab[ 3] = ab[0]^      ab[2]^ab[3]^      ab[5]^ab[6]^      ab[8];
    pab[ 4] = ab[0]^ab[1]^      ab[3]^ab[4]^      ab[6]^ab[7];
    pab[ 5] = ab[0]^            ab[3]^ab[4]^ab[5]^      ab[7];
    pab[ 6] =       ab[1]^ab[2]^ab[3]^            ab[6]^      ab[8];
    pab[ 7] =             ab[2]^      ab[4]^ab[5]^ab[6];
    pab[ 8] =             ab[2]^ab[3]^ab[4]^      ab[6];
    pab[ 9] =       ab[1]^      ab[3]^      ab[5]^      ab[7];
    pab[10] = ab[0]^ab[1]^            ab[4]^      ab[6]^ab[7]^ab[8];
    pab[11] = ab[0]^            ab[3]^      ab[5]^ab[6]^ab[7];
    pab[12] = ab[0]^ab[1]^            ab[4]^ab[5]^            ab[8];
    pab[13] =       ab[1]^ab[2]^      ab[4]^ab[5]^      ab[7]^ab[8];
    pab[14] = ab[0]^ab[1]^      ab[3]^            ab[6]^ab[7]^ab[8];
    pab[15] =       ab[1]^      ab[3]^ab[4]^ab[5]^            ab[8];
    pab[16] = ab[0]^      ab[2]^ab[3]^ab[4]^            ab[7];
    pab[17] =       ab[1]^            ab[4]^ab[5]^ab[6]^      ab[8];
    pab[18] = ab[0]^      ab[2]^            ab[5]^ab[6]^ab[7];
    pab[19] =             ab[2]^ab[3]^            ab[6]^ab[7];
    pab[20] =                                     ab[6]^      ab[8];
    pab[21] = ab[0]^      ab[2];
    pab[22] = ab[0]^ab[1];
    pab[23] = ab[0];
    pab[24] =       ab[1];
    pab[25] =                                           ab[7];
    pab[26] =                                           ab[7]^ab[8];
    pab[27] =                                     ab[6];
    pab[28] =                                                 ab[8];
    pab[29] =             ab[2];

    int i;
    for (i = 0; i < 30; ++i)
        pab[i] = _mm_clmulepi64_si128(pab[i], pab[i], 0x10);

    __v2di cc[17];

    cc[0 ] = pab[23];
    cc[1 ] = pab[22]^pab[23]^pab[24];
    cc[2 ] = pab[21]^pab[23]^pab[24]^pab[29];
    cc[3 ] = pab[28]^pab[17]^pab[2]^pab[15]^pab[7]^pab[6]^pab[5]^pab[29]^pab[21]^pab[22]^pab[12]^pab[19]^pab[9]^pab[13]^pab[11]^pab[3]^pab[26]^pab[20]^pab[27];
    cc[4 ] = pab[4]^pab[3]^pab[10]^pab[11]^pab[6]^pab[2]^pab[8]^pab[14]^pab[9]^pab[22]^pab[23]^pab[24]^pab[1]^pab[20]^pab[27]^pab[28]^pab[25];
    cc[5 ] = pab[26]^pab[25]^pab[28]^pab[0]^pab[9]^pab[21]^pab[23]^pab[29]^pab[24]^pab[1]^pab[3]^pab[13]^pab[14]^pab[5]^pab[18]^pab[16]^pab[11]^pab[15];
    cc[6 ] = pab[26]^pab[12]^pab[19]^pab[21]^pab[23]^pab[29]^pab[4]^pab[3]^pab[14]^pab[5]^pab[18]^pab[22]^pab[1]^pab[20]^pab[27];
    cc[7 ] = pab[20]^pab[27]^pab[28]^pab[25]^pab[23]^pab[0]^pab[15]^pab[7]^pab[11]^pab[6]^pab[14]^pab[5]^pab[18];
    cc[8 ] = pab[0]^pab[23]^pab[24]^pab[10]^pab[15]^pab[7]^pab[2]^pab[18]^pab[14]^pab[17]^pab[22]^pab[26]^pab[25]^pab[28];
    cc[9 ] = pab[21]^pab[23]^pab[29]^pab[24]^pab[0]^pab[16]^pab[11]^pab[7]^pab[10]^pab[2]^pab[8]^pab[18]^pab[5]^pab[28];
    cc[10] = pab[12]^pab[0]^pab[19]^pab[9]^pab[21]^pab[29]^pab[22]^pab[3]^pab[13]^pab[16]^pab[11]^pab[7]^pab[10]^pab[20]^pab[27]^pab[28]^pab[26];
    cc[11] = pab[16]^pab[11]^pab[7]^pab[10]^pab[17]^pab[5]^pab[2]^pab[0]^pab[9]^pab[4]^pab[3]^pab[22]^pab[23]^pab[24]^pab[1]^pab[20]^pab[27]^pab[28]^pab[25];
    cc[12] = pab[26]^pab[25]^pab[28]^pab[8]^pab[14]^pab[5]^pab[17]^pab[10]^pab[6]^pab[16]^pab[15]^pab[3]^pab[13]^pab[1]^pab[9]^pab[21]^pab[23]^pab[29]^pab[24];
    cc[13] = pab[8]^pab[18]^pab[2]^pab[15]^pab[16]^pab[5]^pab[29]^pab[21]^pab[23]^pab[22]^pab[0]^pab[12]^pab[19]^pab[1]^pab[11]^pab[4]^pab[3]^pab[26]^pab[20]^pab[27];
    cc[14] = pab[20]^pab[27]^pab[28]^pab[25];
    cc[15] = pab[25]^pab[26]^pab[28];
    cc[16] = pab[28];

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
