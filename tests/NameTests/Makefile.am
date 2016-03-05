include ../Makefile.common

SYMLINKED_TESTS =\
	MinusInNameTest\
	CreatePrefixTest\
	CreateQNameTest\
	ElemQNameTest\
	AttrQNameTest\
	PrefixNameTest\
	UndeclaredPrefixTest

MOSTLYCLEANFILES = $(SYMLINKED_TESTS)

all:
	for i in $(SYMLINKED_TESTS); do ln -fs ../compilerTest $$i; done
