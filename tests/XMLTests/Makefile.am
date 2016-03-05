include ../Makefile.common

SYMLINKED_TESTS =\
	ElementTest\
	CommentTest\
	PITest\
	ElementExprTest\
	ElemStmtTest\
	CommentExprTest\
	PIExprTest\
	AssignXMLExprTest

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../compilerTest $$i; done
