include ../Makefile.common

SYMLINKED_TESTS =\
	ChildAxisTest\
	AttributeAxisTest\
	PredicateTest\
	BooleanTargetTest\
	StringTargetTest\
	AttributeCompareTest\
	PathWithVarRefTest\
	PathIntPredTest\
	IntFilterExprTest\
	FilterExprTest\
	InvalidFilterContextRefTest\
	ForeachTest\
	NonFilterForeachTest\
	ParentAxisTest

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../compilerTest $$i; done
