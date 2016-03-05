include ../Makefile.common

SYMLINKED_TESTS =\
	ImportSingleTest\
	ImportFuncArgsTest\
	ImportAsTest\
	ImportVariableTest\
	ImportAsNameClashTest\
	AmbigiousRefTest\
	NonExistantSymbol\
	SameNSError\
	ImportVersionTest\
	VersionRangeTest\
	ImportWithTarget\
	ImportConstantTest\
	ImportCallByRefTest

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../compilerTest $$i; done
