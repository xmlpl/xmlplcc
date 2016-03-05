include ../Makefile.common

SYMLINKED_TESTS =\
	InvalidAssignmentTest\
	BinaryOpTypeTest\
	UnaryOpTypeTest\
	CaseMismatchTest\
	DuplicateCaseTest\
	EmptyDefaultTest\
	InvalidExplicitCast

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../prettyXMLParser $$i; done

noinst_PROGRAMS =\
	genBinaryOpType\
	genUnaryOpType

genBinaryOpType_SOURCES = genBinaryOpType.cpp
genUnaryOpType_SOURCES = genUnaryOpType.cpp
