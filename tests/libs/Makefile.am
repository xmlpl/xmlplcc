XMLPLCC=@top_srcdir@/src/xmlpl/xmlplcc

lib_XMLPLCC =\
	libhello-0.0.1.la\
	libhello-0.0.2.la\
	libhello-0.0.3.la\
	libhello-0.0.4.la\
	libhello2-0.0.1.la\
	libbyref-0.0.1.la

CLEANFILES = $(lib_XMLPLCC)

all: $(lib_XMLPLCC)

lib%.la: %.xpl $(XMLPLCC)
	$(XMLPLCC) -l -L -rpath -L `pwd`/test $<
	$(LIBTOOL) --mode=install $(INSTALL) -D $@ `pwd`/test/$@

clean-local:
	rm -f *.o *.cpp test/*
