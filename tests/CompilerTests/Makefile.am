include ../Makefile.common

SYMLINKED_TESTS =\
	SimpleIOTest\
	SimpleIO2Test\
	SimpleIO3Test\
	MainTest\
	MainArgsTest\
	NativeTest\
	ConstantsTest\
	FunctionCallTest\
	ContextStreamTest\
	VariableDeclTest\
	AssignmentTest\
	AssignOpTest\
	BinaryExprTest\
	ExceptionTest\
	IfTest\
	WhileTest\
	ForTest\
	IntegerSwitchTest\
	StringSwitchTest\
	DefaultCaseTest\
	VarInitTest\
	ContextRefTest\
	SampleCodeTest\
	ReturnTest\
	BuilderTargetTest\
	FuncCallWOTarget\
	CastingTargetTest\
	CastTest\
	VoidAppendTest\
	PredContextCallTest\
	CallByReferenceTest\
	BadCallByReferenceTest\
	VarNullInitTest\
	SeqResizeNullTest

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../compilerTest $$i; done
