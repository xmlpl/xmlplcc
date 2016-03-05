SUBDIRS = parser generator
DISTCLEANFILES = DefaultLibraryPath.h

BUILT_SOURCES = DefaultLibraryPath.h

bin_PROGRAMS = xmlplcc

xmlplcc_SOURCES :=\
	DefaultLibraryPath.h\
	ErrorHandler.h\
	ErrorHandler.cpp\
	Location.h\
	Location.cpp\
	CodeGenerator.h\
	LibraryImporter.h\
	LibraryImporter.cpp\
	Builder.h\
	Language.h\
	Language.cpp\
	Options.h\
	Options.cpp\
	xmlplcc.h\
	xmlplcc.cpp\
	Utils.h\
	Utils.cpp\
	main.cpp

xmlplcc_LDADD =\
	parser/libxmlplParser.la\
	parser/ast/libxmlplAST.la\
	parser/environment/libxmlplEnvironment.la\
	generator/cpp/libxmlplCPP.la\
	@libxmlpl_cpp_runtime_LIBS@\
	@BasicUtils_LIBS@\
	@antlr_LIBS@

xmlplcc_LDFLAGS =\
	-export-dynamic

xmlplcc_CXXFLAGS =\
  @BasicUtils_CFLAGS@\
  @antlr_CFLAGS@\
	@libxmlpl_cpp_runtime_CFLAGS@\
	-I..

DefaultLibraryPath.h: Makefile
	echo '#define DEFAULT_LIBRARY_PATH "$(libdir)/xmlpl"' >$@
