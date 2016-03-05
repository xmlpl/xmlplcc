include ../Makefile.common

SYMLINKED_TESTS =\
	RedirectTest\
	RedirectNodeTest

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../compilerTest $$i; done
