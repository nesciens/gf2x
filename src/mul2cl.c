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
/* Implements 128x128 -> 256 bit product using pclmulqdq instruction. */

#ifndef GF2X_MUL2_H_
#define GF2X_MUL2_H_

#include "gf2x.h"
#include "gf2x/gf2x-impl.h"
/* All gf2x source files for lowlevel functions must include gf2x-small.h
 * This is mandatory for the tuning mechanism. */
#include "gf2x/gf2x-small.h"

#include <stdint.h>
#include <wmmintrin.h>

#if GF2X_WORDSIZE != 64
#error "This code is for 64-bit only"
#endif

#include "gf2x/gf2x-config.h"

#ifndef HAVE_PCLMUL_SUPPORT
#error "This code needs pclmul support"
#endif

#ifdef  TUNING
#undef  GF2X_STORAGE_CLASS_mul2
#define GF2X_STORAGE_CLASS_mul2 /**/
#endif

#ifndef __GNUC__
GF2X_STORAGE_CLASS_mul2
void gf2x_mul2(unsigned long * t, unsigned long const * s1,
        unsigned long const * s2)
{
    typedef union {
        __v2di s;
        unsigned long x[2];
    } __v2di_proxy;

    __v2di ss1, ss2, s1s, s2s;
    __v2di_proxy t00, t11, tk;
    ss1 = (__v2di) { s1[0], s1[1] };
    ss2 = (__v2di) { s2[0], s2[1] };

    t00.s = _mm_clmulepi64_si128(ss1, ss2, 0);
    t11.s = _mm_clmulepi64_si128(ss1, ss2, 17);
    
    s1s = _mm_shuffle_epi32(ss1, 78);
    ss1 ^= s1s;
    s2s = _mm_shuffle_epi32(ss2, 78);
    ss2 ^= s2s;
    
    tk.s = _mm_clmulepi64_si128(ss1, ss2, 0);

    tk.s ^= t00.s ^ t11.s;

    /* store result */
    t[0] = t00.x[0];
    t[1] = t00.x[1] ^ tk.x[0];
    t[2] = t11.x[0] ^ tk.x[1];
    t[3] = t11.x[1];
}
#else

/* GCC (4.4.3) seems reluctant to use movdqu which was slow. 
 * However, this code is for processors having pclmulqdq, ie pretty
 * recent ones (in 2010), and for those using movdqu is fast enough and
 * gives an overall speedup.
 *
 * Hopefully this piece of code will become obsolete at some point, when
 * GCC learns how to optimize on the target cpu.
 */
GF2X_STORAGE_CLASS_mul2
void gf2x_mul2(unsigned long * t, unsigned long const * s1,
        unsigned long const * s2)
{
   __asm__ __volatile__(
"movdqu (%%rsi), %%xmm1\n\t"
"movdqu (%%rdx), %%xmm0\n\t"
"pshufd $78, %%xmm1, %%xmm5\n\t"
"movdqa %%xmm1, %%xmm3\n\t"
"pshufd $78, %%xmm0, %%xmm4\n\t"
"movdqa %%xmm1, %%xmm2\n\t"
"pclmulqdq      $0, %%xmm0, %%xmm3\n\t"
"pxor   %%xmm5, %%xmm1\n\t"
"pclmulqdq      $17, %%xmm0, %%xmm2\n\t"
"pxor   %%xmm4, %%xmm0\n\t"
"movdqu %%xmm3, -24(%%rsp)\n\t"
"movq   -24(%%rsp), %%rax\n\t"
"pclmulqdq      $0, %%xmm0, %%xmm1\n\t"
"movdqa %%xmm3, %%xmm0\n\t"
"movdqu %%xmm2, -40(%%rsp)\n\t"
"pxor   %%xmm2, %%xmm0\n\t"
"movq   %%rax, (%%rdi)\n\t"
"pxor   %%xmm1, %%xmm0\n\t"
"movdqu %%xmm0, -56(%%rsp)\n\t"
"movq   -56(%%rsp), %%rax\n\t"
"xorq   -16(%%rsp), %%rax\n\t"
"movq   %%rax, 8(%%rdi)\n\t"
"movq   -48(%%rsp), %%rax\n\t"
"xorq   -40(%%rsp), %%rax\n\t"
"movq   %%rax, 16(%%rdi)\n\t"
"movq   -32(%%rsp), %%rax\n\t"
"movq   %%rax, 24(%%rdi)\n\t"
: : "S" (s1), "d" (s2), "D" (t)
: "memory", "%eax", "%xmm0", "%xmm1", "%xmm2", "%xmm3", "%xmm4", "%xmm5"
);
}

#endif
#endif  /* GF2X_MUL2_H_ */
