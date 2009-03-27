
AC_INIT([gf2x], [0.9.1])
AC_CANONICAL_TARGET

AC_SUBST([gf2x_lib_version], [1:0:0])

AM_INIT_AUTOMAKE

# Use LT_LANG once switched to libtool 2.2
m4_defun([_LT_AC_LANG_F77_CONFIG], [:])
m4_defun([_LT_AC_LANG_GCJ_CONFIG], [:])

AC_ARG_ENABLE([ntl-checks],
              [AS_HELP_STRING([--enable-ntl-checks],
                              [Turn on ntl checks])])
AC_ARG_ENABLE([sse2],
              [AS_HELP_STRING([--enable-sse2],
                              [Turn on sse-2 code (default is yes)])])

AM_CONDITIONAL([ENABLE_NTL_CHECKS],[test x$enable_ntl_checks = xyes])

AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_CXX
AC_COMPILE_WARNINGS
AC_PROG_CC_C99

# This macro is used for tuning
AM_PROG_CC_C_O

# A fallback for generic builds. Otherwise unused.
AC_CHECK_SIZEOF([unsigned long])
gf2x_wordsize=`expr 8 \* $ac_cv_sizeof_unsigned_long`
AC_SUBST([GF2X_WORDSIZE], [$gf2x_wordsize])

CHECK_SSE2_SUPPORT()

machine_dir=generic$gf2x_wordsize
case "$target_cpu" in
 i?86|pentium*) machine_dir=x86_sse2
  if test "$gf2x_cv_cc_supports_sse2" = "no" ; then
   machine_dir=x86_nosse2
  fi;;
 x86_64) machine_dir=x86_64;;
esac

for f in gf2x-thresholds.h gf2x_mul1.h gf2x_mul2.h gf2x_mul3.h gf2x_mul4.h ; do
 who=tuned
 if ! test -f $srcdir/hardware/$who/$f ; then who=$machine_dir; fi
 if ! test -f $srcdir/hardware/$who/$f ; then who=generic$gf2x_wordsize; fi
 if ! test -f $srcdir/hardware/$who/$f ; then who=generic; fi
 if ! test -f $srcdir/hardware/$who/$f ; then AC_MSG_ERROR([$f not found]); fi
 AC_CONFIG_LINKS([gf2x/$f:hardware/$who/$f])
 if test "$f" = "gf2x-thresholds.h" ; then
    tuned_nbits=[`sed -n 's/^#define[ 	][ 	]*GF2X_WORDSIZE[ 	][ 	]*\([0-9][0-9]*\).*$/\1/p' $srcdir/hardware/$who/$f`]
 fi
done

if test x$tuned_nbits = x ; then
 tuned_nbits=$gf2x_wordsize
fi

# This is used in tuning/Makefile.am
AM_CONDITIONAL([GF2X_32BIT_SOURCES],[test "x$tuned_nbits" = x32])
AM_CONDITIONAL([GF2X_64BIT_SOURCES],[test "x$tuned_nbits" = x64])
AM_CONDITIONAL([GF2X_SSE2_AVAILABLE],[test "x$gf2x_cv_cc_supports_sse2" != xno])

AC_CONFIG_HEADERS([gf2x/gf2x-config.h])

AC_CONFIG_FILES([version.sh Makefile tests/Makefile apps/Makefile tuning/Makefile])
AC_OUTPUT

# vim: set sw=1:
