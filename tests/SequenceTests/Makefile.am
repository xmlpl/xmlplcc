include ../Makefile.common

SYMLINKED_TESTS =\
	SequenceIterationTest\
	SequenceItemAssignTest\
	NullInSequenceTest\
	SequenceExprTest\
	CommaAssignTest\
	InvalidCommaAssign

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../compilerTest $$i; done
