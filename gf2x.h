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

/* Multiplication over GF(2)[x] */

#ifndef GF2X_H_
#define GF2X_H_

/**********************************************************************/
/* Some support macros */

#include <assert.h>
#ifndef ASSERT
#define ASSERT(x)	assert(x)
#endif
#ifndef	MAYBE_UNUSED
#if defined(__GNUC__)
#define MAYBE_UNUSED __attribute__ ((unused))
#else
#define MAYBE_UNUSED
#endif
#endif
#ifndef	GNUC_VERSION
#define GNUC_VERSION(X,Y,Z)     \
    (defined(__GNUC__) &&        \
    (__GNUC__ == X && __GNUC_MINOR__ == Y && __GNUC_PATCHLEVEL__ == Z))
#endif
#if GNUC_VERSION(4,3,0) || GNUC_VERSION(4,3,1)
#warning "Your GCC version is buggy. Binary fields may fail randomly"
/* Gcc bug reports 37101 and 37340 -- the only convenient fix is to
 * upgrade to 4.3.2 */
#endif

/*********************************************************************/
/* Helper macros */
#include <stdlib.h>

#include "gf2x/gf2x-thresholds.h"

#ifdef __cplusplus
extern "C" {
#endif

/* This is the toplevel multiplication routine, the only one that really
 * matters.
 *
 * The destination must not overlap with the inputs.
 *
 * c must have enough room to hold an+bn words.
 */
extern void gf2x_mul(unsigned long *c,
		const unsigned long *aa, unsigned int an,
		const unsigned long *bb, unsigned int bn);

/* The second version is reentrant */
struct gf2x_mul_pool_s {
	unsigned long * stk;
	size_t stk_size;
};
typedef struct gf2x_mul_pool_s gf2x_mul_pool_t[1];
extern void gf2x_mul_pool_init(gf2x_mul_pool_t);
extern void gf2x_mul_pool_clear(gf2x_mul_pool_t);

extern void gf2x_mul_r(unsigned long *c,
		const unsigned long *aa, unsigned int an,
		const unsigned long *bb, unsigned int bn, gf2x_mul_pool_t);

#ifdef __cplusplus
}
#endif

#endif	/* GF2X_H_ */
