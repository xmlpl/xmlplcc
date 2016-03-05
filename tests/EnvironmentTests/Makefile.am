include ../Makefile.common

SYMLINKED_TESTS =\
	VarDeclTest\
	DupVarDeclTest\
	VarRefTest\
	BadVarRefTest\
	VarDeclShadowTest\
	XMLScopeTest\
	FuncDeclTest\
	FuncOverloadTest\
	DupFuncTest\
        DupFunc2Test\
	DupFuncArgsTest\
	FuncArgRefTest\
	FuncArgShadowTest\
	FuncCallTest\
	FuncOnlyReturnTest\
	FuncUndeclTest\
	NotAFuncTest\
	OverloadedCallTest\
	NoMatchingCallTest\
	AmbiguousCallTest\
	CastableCallTest\
	FuncExtendTest\
	FuncForwardDeclTest

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../prettyXMLParser $$i; done
