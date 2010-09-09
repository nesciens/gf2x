/* This file is part of the gf2x library.

   Copyright 2007, 2008, 2009
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
/* Tuning program for GF(2)[x] low-level multiplication. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <string.h>

/* gf2x is used for checking correctness -- not otherwise */
#include "gf2x.h"

#include "timing.h"

#include "tuning_undefs_@@SIZE@@.h"

// make it somewhat realistic.
#define N       (1 << 16)
#define NMASK   ((N)-1)

#if @@SIZE@@ == 1
extern void gf2x_mul@@SIZE@@(unsigned long *c, unsigned long a, unsigned long b);
#else
extern void gf2x_mul@@SIZE@@(unsigned long *c, const unsigned long *a, const unsigned long *b);
#endif

int main(int argc, char *argv[])
{
    unsigned long i, *c0, *c, *a, *b;
    uint64_t st;

    char * progname = "me";
    if (argc >= 1) {
        progname = argv[0];
    }

    a = (unsigned long *) malloc((N + @@SIZE@@) * sizeof(unsigned long));
    b = (unsigned long *) malloc((N + @@SIZE@@) * sizeof(unsigned long));
    c = (unsigned long *) malloc(2 * @@SIZE@@ * sizeof(unsigned long));
    c0 = (unsigned long *) malloc(2 * @@SIZE@@ * sizeof(unsigned long));

    for (i = 0; i < N + @@SIZE@@; i++) {
        a[i] = (unsigned long) rand();
        b[i] = (unsigned long) rand();
    }

    st = 0;
    for (i = 0; i < 10 && i < N; i++) {
        /* Use this one as a reference implementation */
        gf2x_mul(c0, a + i, @@SIZE@@, b + i, @@SIZE@@);
        st -= microseconds();
#if @@SIZE@@ == 1
        gf2x_mul@@SIZE@@ (c, a[i & NMASK], b[i & NMASK]);
#else
        gf2x_mul@@SIZE@@ (c, a + (i & NMASK), b + (i & NMASK));
#endif
        st += microseconds();
        if (memcmp(c, c0, 2 * @@SIZE@@ * sizeof(unsigned long)) != 0) {
            fprintf(stderr, "Error, computed test values do not match\n");
            exit(255);
        }
    }

    uint64_t m = i;

    /* arrange for the measure to take at least .1 seconds */
    for( ; ; ) {
        st = -microseconds();
        for (i = 0; i < m; i++) {
#if @@SIZE@@ == 1
            gf2x_mul@@SIZE@@ (c, a[i & NMASK], b[i & NMASK]);
#else
            gf2x_mul@@SIZE@@ (c, a + (i & NMASK), b + (i & NMASK));
#endif
        }
        st += microseconds();
        if (st >= 100000)
            break;
        m *= 3;
    }

    printf("%s : %1.1f ns\n", progname, (double) st / (double) m * 1.0e3);


    free(c0);
    free(c);
    free(b);
    free(a);
    return 0;
}