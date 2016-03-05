include ../Makefile.common

SYMLINKED_TESTS =\
  ForeachXPathReturnTest\
  ForeachXPathContinueTest\
  ForeachXPathBreakTest\
  SwitchQNameTest\
  AttributeCompareTest\
  ParentedAppendTest\
  DoubleFilterTest\
  ParseSegFaultTest\
	ForeachSubExprTest

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../compilerTest $$i; done
