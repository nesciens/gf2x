
# This impacts the storage class of the functions in the inlines files.
AM_CPPFLAGS = -I$(top_builddir) -I$(top_srcdir)
EXTRA_DIST=

# We've got a lot of per-target cfiles here, but it's rather silly to
# have automake produce separate .o files for the files which fo _not_
# change in this regard. So we resort to having lots of silly libraries,
# as a workaround.

EXTRA_LTLIBRARIES=libtiming.la
libtiming_la_SOURCES=timing.c

LOWLEVEL=
CLEANFILES=
BUILT_SOURCES=

# Autotools already use sed, so normally it's not an extraordinary
# difficult dependency.
tuning_undefs_1.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/1/g < $< > $@
tuning_undefs_2.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/2/g < $< > $@
tuning_undefs_3.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/3/g < $< > $@
tuning_undefs_4.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/4/g < $< > $@
tuning_undefs_5.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/5/g < $< > $@
tuning_undefs_6.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/6/g < $< > $@
tuning_undefs_7.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/7/g < $< > $@
tuning_undefs_8.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/8/g < $< > $@
tuning_undefs_9.h: tuning_undefs_pre.h ; sed -e s/@@SIZE@@/9/g < $< > $@
tuneup_1.c: tuneup_pre.c ; sed -e s/@@SIZE@@/1/g < $< > $@
tuneup_2.c: tuneup_pre.c ; sed -e s/@@SIZE@@/2/g < $< > $@
tuneup_3.c: tuneup_pre.c ; sed -e s/@@SIZE@@/3/g < $< > $@
tuneup_4.c: tuneup_pre.c ; sed -e s/@@SIZE@@/4/g < $< > $@
tuneup_5.c: tuneup_pre.c ; sed -e s/@@SIZE@@/5/g < $< > $@
tuneup_6.c: tuneup_pre.c ; sed -e s/@@SIZE@@/6/g < $< > $@
tuneup_7.c: tuneup_pre.c ; sed -e s/@@SIZE@@/7/g < $< > $@
tuneup_8.c: tuneup_pre.c ; sed -e s/@@SIZE@@/8/g < $< > $@
tuneup_9.c: tuneup_pre.c ; sed -e s/@@SIZE@@/9/g < $< > $@
tuneup_1.$(OBJEXT): tuning_undefs_1.h
tuneup_2.$(OBJEXT): tuning_undefs_2.h
tuneup_3.$(OBJEXT): tuning_undefs_3.h
tuneup_4.$(OBJEXT): tuning_undefs_4.h
tuneup_5.$(OBJEXT): tuning_undefs_5.h
tuneup_6.$(OBJEXT): tuning_undefs_6.h
tuneup_7.$(OBJEXT): tuning_undefs_7.h
tuneup_8.$(OBJEXT): tuning_undefs_8.h
tuneup_9.$(OBJEXT): tuning_undefs_9.h
BUILT_SOURCES +=tuneup_1.c tuning_undefs_1.h
BUILT_SOURCES +=tuneup_2.c tuning_undefs_2.h
BUILT_SOURCES +=tuneup_3.c tuning_undefs_3.h
BUILT_SOURCES +=tuneup_4.c tuning_undefs_4.h
BUILT_SOURCES +=tuneup_5.c tuning_undefs_5.h
BUILT_SOURCES +=tuneup_6.c tuning_undefs_6.h
BUILT_SOURCES +=tuneup_7.c tuning_undefs_7.h
BUILT_SOURCES +=tuneup_8.c tuning_undefs_8.h
	
EXTRA_LTLIBRARIES+=libtuneup-s1.la
nodist_libtuneup_s1_la_SOURCES=tuneup_1.c tuning_undefs_1.h
libtuneup_s1_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)

EXTRA_LTLIBRARIES+=libtuneup-s2.la
nodist_libtuneup_s2_la_SOURCES=tuneup_2.c tuning_undefs_2.h
libtuneup_s2_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)

EXTRA_LTLIBRARIES+=libtuneup-s3.la
nodist_libtuneup_s3_la_SOURCES=tuneup_3.c tuning_undefs_3.h
libtuneup_s3_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)

EXTRA_LTLIBRARIES+=libtuneup-s4.la
nodist_libtuneup_s4_la_SOURCES=tuneup_4.c tuning_undefs_4.h
libtuneup_s4_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)
#
#EXTRA_LTLIBRARIES+=libtuneup-s5.la
#nodist_libtuneup_s5_la_SOURCES=tuneup_5.c tuning_undefs_5.h
#libtuneup_s5_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)
#
#EXTRA_LTLIBRARIES+=libtuneup-s6.la
#nodist_libtuneup_s6_la_SOURCES=tuneup_6.c tuning_undefs_6.h
#libtuneup_s6_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)
#
#EXTRA_LTLIBRARIES+=libtuneup-s7.la
#nodist_libtuneup_s7_la_SOURCES=tuneup_7.c tuning_undefs_7.h
#libtuneup_s7_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)
#
#EXTRA_LTLIBRARIES+=libtuneup-s8.la
#nodist_libtuneup_s8_la_SOURCES=tuneup_8.c tuning_undefs_8.h
#libtuneup_s8_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)
#
#EXTRA_LTLIBRARIES+=libtuneup-s9.la
#nodist_libtuneup_s9_la_SOURCES=tuneup_9.c tuning_undefs_9.h
#libtuneup_s9_la_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir)

# noinst_PROGRAMS=tuneup_mul1 tuneup_mul2 tuneup_mul4

EXTRA_PROGRAMS=gen_bb_mul_code$(EXEEXT)
gen_bb_mul_code_SOURCES=gen_bb_mul_code.c


# The list below is the result of variations around the following vim macro:
# s/.*/EXTRA_PROGRAMS+=tune_&^Mtune_&_SOURCES=tuneup.c
# &.c^Mtune_&_CPPFLAGS=-DTSIZE=&/g
#
#  which is fed the list of all functions to be tested.
######################################################################
if GF2X_32BIT_SOURCES
LOWLEVEL+=tune_gen_mul1_w32k1$(EXEEXT)
tune_gen_mul1_w32k1_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w32k1_SOURCES=gen_mul1_w32k1.c tuning_undefs_1.h
gen_mul1_w32k1.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w32k1_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w32k1.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 32 1 > $@
BUILT_SOURCES+=gen_mul1_w32k1.c 


LOWLEVEL+=tune_gen_mul1_w32k2$(EXEEXT)
tune_gen_mul1_w32k2_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w32k2_SOURCES=gen_mul1_w32k2.c tuning_undefs_1.h
gen_mul1_w32k2.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w32k2_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w32k2.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 32 2 > $@
BUILT_SOURCES+=gen_mul1_w32k2.c 


LOWLEVEL+=tune_gen_mul1_w32k3$(EXEEXT)
tune_gen_mul1_w32k3_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w32k3_SOURCES=gen_mul1_w32k3.c tuning_undefs_1.h
gen_mul1_w32k3.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w32k3_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w32k3.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 32 3 > $@
BUILT_SOURCES+=gen_mul1_w32k3.c 


LOWLEVEL+=tune_gen_mul1_w32k4$(EXEEXT)
tune_gen_mul1_w32k4_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w32k4_SOURCES=gen_mul1_w32k4.c tuning_undefs_1.h
gen_mul1_w32k4.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w32k4_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w32k4.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 32 4 > $@
BUILT_SOURCES+=gen_mul1_w32k4.c 


LOWLEVEL+=tune_gen_mul1_w32k5$(EXEEXT)
tune_gen_mul1_w32k5_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w32k5_SOURCES=gen_mul1_w32k5.c tuning_undefs_1.h
gen_mul1_w32k5.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w32k5_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w32k5.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 32 5 > $@
BUILT_SOURCES+=gen_mul1_w32k5.c 


LOWLEVEL+=tune_gen_mul1_w32k6$(EXEEXT)
tune_gen_mul1_w32k6_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w32k6_SOURCES=gen_mul1_w32k6.c tuning_undefs_1.h
gen_mul1_w32k6.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w32k6_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w32k6.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 32 6 > $@
BUILT_SOURCES+=gen_mul1_w32k6.c 


LOWLEVEL+=tune_gen_mul1_w32k7$(EXEEXT)
tune_gen_mul1_w32k7_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w32k7_SOURCES=gen_mul1_w32k7.c tuning_undefs_1.h
gen_mul1_w32k7.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w32k7_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w32k7.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 32 7 > $@
BUILT_SOURCES+=gen_mul1_w32k7.c 


LOWLEVEL+=tune_gen_mul1_w32k8$(EXEEXT)
tune_gen_mul1_w32k8_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w32k8_SOURCES=gen_mul1_w32k8.c tuning_undefs_1.h
gen_mul1_w32k8.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w32k8_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w32k8.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 32 8 > $@
BUILT_SOURCES+=gen_mul1_w32k8.c 


endif

######################################################################

if GF2X_64BIT_SOURCES
LOWLEVEL+=tune_gen_mul1_w64k1$(EXEEXT)
tune_gen_mul1_w64k1_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w64k1_SOURCES=gen_mul1_w64k1.c tuning_undefs_1.h
gen_mul1_w64k1.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w64k1_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w64k1.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 64 1 > $@
BUILT_SOURCES+=gen_mul1_w64k1.c 


LOWLEVEL+=tune_gen_mul1_w64k2$(EXEEXT)
tune_gen_mul1_w64k2_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w64k2_SOURCES=gen_mul1_w64k2.c tuning_undefs_1.h
gen_mul1_w64k2.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w64k2_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w64k2.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 64 2 > $@
BUILT_SOURCES+=gen_mul1_w64k2.c 


LOWLEVEL+=tune_gen_mul1_w64k3$(EXEEXT)
tune_gen_mul1_w64k3_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w64k3_SOURCES=gen_mul1_w64k3.c tuning_undefs_1.h
gen_mul1_w64k3.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w64k3_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w64k3.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 64 3 > $@
BUILT_SOURCES+=gen_mul1_w64k3.c 


LOWLEVEL+=tune_gen_mul1_w64k4$(EXEEXT)
tune_gen_mul1_w64k4_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w64k4_SOURCES=gen_mul1_w64k4.c tuning_undefs_1.h
gen_mul1_w64k4.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w64k4_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w64k4.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 64 4 > $@
BUILT_SOURCES+=gen_mul1_w64k4.c 


LOWLEVEL+=tune_gen_mul1_w64k5$(EXEEXT)
tune_gen_mul1_w64k5_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w64k5_SOURCES=gen_mul1_w64k5.c tuning_undefs_1.h
gen_mul1_w64k5.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w64k5_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w64k5.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 64 5 > $@
BUILT_SOURCES+=gen_mul1_w64k5.c 


LOWLEVEL+=tune_gen_mul1_w64k6$(EXEEXT)
tune_gen_mul1_w64k6_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w64k6_SOURCES=gen_mul1_w64k6.c tuning_undefs_1.h
gen_mul1_w64k6.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w64k6_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w64k6.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 64 6 > $@
BUILT_SOURCES+=gen_mul1_w64k6.c 


LOWLEVEL+=tune_gen_mul1_w64k7$(EXEEXT)
tune_gen_mul1_w64k7_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w64k7_SOURCES=gen_mul1_w64k7.c tuning_undefs_1.h
gen_mul1_w64k7.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w64k7_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w64k7.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 64 7 > $@
BUILT_SOURCES+=gen_mul1_w64k7.c 


LOWLEVEL+=tune_gen_mul1_w64k8$(EXEEXT)
tune_gen_mul1_w64k8_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
nodist_tune_gen_mul1_w64k8_SOURCES=gen_mul1_w64k8.c tuning_undefs_1.h
gen_mul1_w64k8.$(OBJEXT): tuning_undefs_1.h
tune_gen_mul1_w64k8_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
gen_mul1_w64k8.c: gen_bb_mul_code$(EXEEXT) ; ./gen_bb_mul_code 64 8 > $@
BUILT_SOURCES+=gen_mul1_w64k8.c 


endif

######################################################################
LOWLEVEL+=tune_mul2k$(EXEEXT)
tune_mul2k_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=2
tune_mul2k_SOURCES=mul2k.c tuning_undefs_2.h
tune_mul2k_LDADD=libtuneup-s2.la libtiming.la ../libgf2x.la
mul2k.$(OBJEXT): tuning_undefs_2.h


LOWLEVEL+=tune_mul3k$(EXEEXT)
tune_mul3k_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=3
tune_mul3k_SOURCES=mul3k.c tuning_undefs_3.h
tune_mul3k_LDADD=libtuneup-s3.la libtiming.la ../libgf2x.la
mul3k.$(OBJEXT): tuning_undefs_3.h


LOWLEVEL+=tune_mul4k$(EXEEXT)
tune_mul4k_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=4
tune_mul4k_SOURCES=mul4k.c tuning_undefs_4.h
tune_mul4k_LDADD=libtuneup-s4.la libtiming.la ../libgf2x.la
mul4k.$(OBJEXT): tuning_undefs_4.h


######################################################################
if GF2X_SSE2_AVAILABLE
if GF2X_64BIT_SOURCES
LOWLEVEL+=tune_mul2t$(EXEEXT)
tune_mul2t_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=2
tune_mul2t_SOURCES=mul2t.c tuning_undefs_2.h
tune_mul2t_LDADD=libtuneup-s2.la libtiming.la ../libgf2x.la
mul2t.$(OBJEXT): tuning_undefs_2.h

endif
if GF2X_32BIT_SOURCES
LOWLEVEL+=tune_mul4t$(EXEEXT)
tune_mul4t_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=4
tune_mul4t_SOURCES=mul4t.c tuning_undefs_4.h
tune_mul4t_LDADD=libtuneup-s4.la libtiming.la ../libgf2x.la
mul4t.$(OBJEXT): tuning_undefs_4.h


LOWLEVEL+=tune_mul3t$(EXEEXT)
tune_mul3t_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=3
tune_mul3t_SOURCES=mul3t.c tuning_undefs_3.h
tune_mul3t_LDADD=libtuneup-s3.la libtiming.la ../libgf2x.la
mul3t.$(OBJEXT): tuning_undefs_3.h

endif
endif

if GF2X_PCLMUL_AVAILABLE
LOWLEVEL+=tune_mul1cl$(EXEEXT)
tune_mul1cl_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=1
tune_mul1cl_SOURCES=mul1cl.c tuning_undefs_1.h
tune_mul1cl_LDADD=libtuneup-s1.la libtiming.la ../libgf2x.la
mul1cl.$(OBJEXT): tuning_undefs_1.h


LOWLEVEL+=tune_mul2cl$(EXEEXT)
tune_mul2cl_CPPFLAGS=-I$(top_builddir) -I$(top_srcdir) -DTUNING=2
tune_mul2cl_SOURCES=mul2cl.c tuning_undefs_2.h
tune_mul2cl_LDADD=libtuneup-s2.la libtiming.la ../libgf2x.la
mul2cl.$(OBJEXT): tuning_undefs_2.h
endif


######################################################################
EXTRA_PROGRAMS+=$(LOWLEVEL)
tune-lowlevel: $(LOWLEVEL)
	cd $(top_builddir) ; $(MAKE)
	MAKE="$(MAKE)" srcdir=$(srcdir)	\
	perl $(srcdir)/tune-lowlevel.pl $(LOWLEVEL)
EXTRA_DIST+=tune-lowlevel.pl

######################################################################
noinst_HEADERS=timing.h tuning-common.h replace.h

EXTRA_PROGRAMS+=update-thresholds$(EXEEXT)
update_thresholds_SOURCES=update-thresholds.c replace.c

######################################################################
EXTRA_PROGRAMS+=tunetoom$(EXEEXT)
tunetoom_SOURCES=tunetoom.c tuning-common.c
tunetoom_LDADD=libtiming.la ../libgf2x.la

TOOM_TUNING_LIMIT=2048

tunetoom.res: tunetoom$(EXEEXT)
	./tunetoom -s 1.05 $(TOOM_TUNING_LIMIT) -o tunetoom.res

tune-toom: tunetoom.res update-thresholds$(EXEEXT)
	cd $(top_builddir) ; $(MAKE)
	cat ../gf2x/gf2x-thresholds.h > tuned_thresholds.h
	./update-thresholds -o tuned_thresholds.h < tunetoom.res
	mkdir -p ../already_tuned/tuned/
	mv -f tuned_thresholds.h ../already_tuned/tuned/gf2x-thresholds.h
	rm -f ../gf2x/gf2x-thresholds.h
	ln -sf ../already_tuned/tuned/gf2x-thresholds.h ../gf2x/
	cd $(top_builddir) ; $(MAKE)

######################################################################
EXTRA_PROGRAMS+=tunefft$(EXEEXT)
tunefft_SOURCES=tunefft.c tuning-common.c
tunefft_LDADD=libtiming.la ../libgf2x.la

FFT_TUNING_LIMIT=8000000

tunefft.res: tunefft$(EXEEXT)
	./tunefft -s 1.02 $(FFT_TUNING_LIMIT) -o tunefft.res

tune-fft: tunefft.res update-thresholds$(EXEEXT)
	cd $(top_builddir) ; $(MAKE)
	cat ../gf2x/gf2x-thresholds.h > tuned_thresholds.h
	./update-thresholds -o tuned_thresholds.h < tunefft.res
	mkdir -p ../already_tuned/tuned/
	mv -f tuned_thresholds.h ../already_tuned/tuned/gf2x-thresholds.h
	rm -f ../gf2x/gf2x-thresholds.h
	ln -sf ../already_tuned/tuned/gf2x-thresholds.h ../gf2x/
	cd $(top_builddir) ; $(MAKE)

CLEANFILES+=$(EXTRA_PROGRAMS) $(EXTRA_LTLIBRARIES) tunetoom.res tunefft.res