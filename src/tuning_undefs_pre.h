#ifndef TUNING_UNDEFS_@@SIZE@@_H_
#define TUNING_UNDEFS_@@SIZE@@_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Tuning code does two things. It uses the gf2x library, compiled with
 * its default settings, and it tries as well other candidate functions,
 * to see if performance improves. The trick is that the code for these
 * functions is also valid code for the library include files. Therefore,
 * the ``candidate functions'' must not have the same name as in the gf2x
 * library, because otherwise we could end up with two different
 * definitions for the same code, and ambiguity as to what gf2x_mul_X
 * stands for: the library code, or the function we are currently testing ?
 */

/* First we include the gf2x standard inlines. Not necessarily because we
 * need them, but rather because we might have seen a prototype for one
 * of these with static declaration. Therefore we need the code.
 * Including it here causes declaration for the standard functions to be
 * emitted, since this header is protected: when gf2x-small.h includes
 * gf2x/gf2x_mul@@SIZE@@.h, the file _is_ read due to the fact that we
 * undefine the protection flag below. However this file
 * tuning_undefs_@@SIZE@@.h  is not included again.
 */
#undef  GF2X_MUL@@SIZE@@_H_
#include "gf2x/gf2x_mul@@SIZE@@.h"


/* Now we undefine this flag, so that it is possible to re-include
 * another function for doing mul@@SIZE@@
 */


#define gf2x_mul@@SIZE@@               tuning_gf2x_mul@@SIZE@@
#undef  GF2X_STORAGE_CLASS_mul@@SIZE@@
#define GF2X_STORAGE_CLASS_mul@@SIZE@@ /**/

#if @@SIZE@@ == 1
#define gf2x_mul_1_n            tuning_gf2x_mul_1_n
#define gf2x_addmul_1_n         tuning_gf2x_addmul_1_n
#undef  GF2X_STORAGE_CLASS_mul_1_n
#define GF2X_STORAGE_CLASS_mul_1_n /**/
#undef  GF2X_STORAGE_CLASS_addmul_1_n
#define GF2X_STORAGE_CLASS_addmul_1_n /**/
#endif

#ifdef __cplusplus
}
#endif

#endif	/* TUNING_UNDEFS_@@SIZE@@_H_ */
