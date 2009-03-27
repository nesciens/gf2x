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

#ifndef GF2X_IMPL_H_
#define GF2X_IMPL_H_

#include "gf2x.h"
#include "gf2x/gf2x-config.h"

#ifndef GF2X_WORDSIZE
#define GF2X_WORDSIZE  (8 * SIZEOF_UNSIGNED_LONG)
#endif

/* These flags are for internal use */
#define	GF2X_SELECT_KARA	0	/* do not change ! */
#define	GF2X_SELECT_TC3		1
#define	GF2X_SELECT_TC3W	2
#define	GF2X_SELECT_TC4		3
#define	GF2X_SELECT_UNB_DFLT	0
#define	GF2X_SELECT_UNB_TC3U	1	/* do not change ! */

#ifdef __cplusplus
extern "C" {
#endif

extern long gf2x_toomspace(long n);
extern long gf2x_toomuspace(long n);
extern void gf2x_mul_basecase(unsigned long * c, const unsigned long * a,
			 long na, const unsigned long * b, long nb) MAYBE_UNUSED;


extern void gf2x_mul_toom(unsigned long *c, const unsigned long *a,
			const unsigned long *b, long n, unsigned long *stk);
extern void gf2x_mul_kara(unsigned long *c, const unsigned long *a, const unsigned long *b,
			long n, unsigned long *stk);
extern void gf2x_mul_tc3(unsigned long *c, const unsigned long *a, const unsigned long *b,
		 	long n, unsigned long *stk);
extern void gf2x_mul_tc3w(unsigned long *c, const unsigned long *a, const unsigned long *b,
		        long n, unsigned long *stk);
extern void gf2x_mul_tc4(unsigned long *c, const unsigned long *a, const unsigned long *b,
			long n, unsigned long *stk);
extern short gf2x_best_toom(unsigned int);
extern long gf2x_toomspace(long);

extern void gf2x_mul_tc3u(unsigned long * c, const unsigned long * a, long sa,
	      const unsigned long * b, unsigned long * stk);
extern short gf2x_best_utoom(unsigned int);
extern long gf2x_toomuspace(long);


extern void gf2x_mul_fft0(unsigned long *c, const unsigned long *a, long an,
	     const unsigned long *b, long bn, long K, long M);
extern void gf2x_mul_fft(unsigned long *c, const unsigned long *a, long an,
		            const unsigned long *b, long bn, long K);
extern void gf2x_mul_fft1(unsigned long *c, long cn,
	     const unsigned long *aa, long an,
	     const unsigned long *bb, long bn, long K, long M);
extern void gf2x_mul_fft2(unsigned long *c, const unsigned long *a, long an,
	     const unsigned long *b, long bn, long K);


/* tunetoom.c need to peek into toom.c's tables ; that's very ugly. SO
 * please don't use for anything else.
 * */
extern short best_tab[GF2X_TOOM_TUNING_LIMIT];
extern short best_utab[GF2X_TOOM_TUNING_LIMIT];


/* Karatsuba, Toom, and so on are in separate .c files */

#ifdef __cplusplus
}
#endif

#endif	/* GF2X_IMPL_H_ */
