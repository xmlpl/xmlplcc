SUBDIRS = ParserTests\
	EnvironmentTests\
	TypeValidationTests\
	RuntimeTests\
	DOMTests\
	CompilerTests\
	ImportTests\
	NameTests\
	XMLTests\
	PathTests\
	SequenceTests\
	BugTests\
	RedirectTests\
	libs

EXTRA_DIST = Makefile.common testHarness
MOSTLYCLEANFILES = test.log

check: all
	./testHarness 2>&1 | tee test.log

TH_LINKS = runTest resetTest viewTest initTest

maintainer-clean-generic:
	rm -f $(TH_LINKS)

all: th_links

th_links: testHarness
	for i in $(TH_LINKS); do ln -sf $< $$i; done


include Makefile.common
