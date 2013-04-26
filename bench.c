/* This file is part of the gf2x library.

   Copyright 2007, 2008, 2009
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

#include <sys/resource.h>
#include <sys/types.h>
#include <stdlib.h>
#include "gf2x.h"

/* Usage: ./bench <limit size> */

double runtime(void)
{
   struct rusage used;

   getrusage(RUSAGE_SELF, &used);
   return (used.ru_utime.tv_sec + used.ru_stime.tv_sec +
      (used.ru_utime.tv_usec + used.ru_stime.tv_usec) / 1e6);
}

int main(int argc, char * argv[])
{
    unsigned long i;
    unsigned long n0 = 1;
    unsigned long n = 200;
    if (argc > 1) {
        n = atoi(argv[1]);
    }
    if (argc > 2) {
        n0 = n;
        n = atoi(argv[2]);
    }

    setbuf(stdout,NULL);

    unsigned long * a, * b, * c;

    a = malloc(n * sizeof(unsigned long));
    b = malloc(n * sizeof(unsigned long));
    c = malloc(2 * n * sizeof(unsigned long));

    for(i = 0 ; i < n ; i++) {
        a[i] = rand();
        b[i] = rand();
    }

    unsigned long jmax = 100000;

    for(i = n0 ; i < n ; i++) {
        /* warm up */
        gf2x_mul(c,a,i,b,i);
        gf2x_mul(c,a,i,b,i);
        gf2x_mul(c,a,i,b,i);
        double t = runtime();
        unsigned long j;
        double d;
#if 0
        for(j = 0 ; j < jmax ; j++) {
            gf2x_mul(c,a,i,b,i);
        }
        d = runtime() - t;

        if (d > 1 && jmax > 8) {
            jmax -= jmax / 3;
        }
#else
        for(j = 0 ; (d=runtime()-t) < 1 && (j < 2000 || d < 0.2) ; j++) {
            gf2x_mul(c,a,i,b,i);
        }
#endif
        printf("%u %e\t%u %.2f\n", i, d/j,j,d);

    }

    free(a);
    free(b);
    free(c);
}

