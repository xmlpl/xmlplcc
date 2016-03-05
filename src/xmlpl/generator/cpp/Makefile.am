noinst_LTLIBRARIES = libxmlplCPP.la

libxmlplCPP_la_SOURCES :=\
	FunctionizeInfo.h\
	CppCodeGenerator.h\
	CppCodeGenerator.cpp\
	CppCodeGeneratorBuiltins.cpp\
	CppCodeGeneratorUtils.cpp\
	CppLibraryImporter.h\
	CppLibraryImporter.cpp\
	CppBuilder.h\
	CppBuilder.cpp\
	CppLanguage.h\
	CppLanguage.cpp\
	md5.h\
	md5.c

libxmlplCPP_la_CXXFLAGS =\
	-I$(top_builddir)\
	-I$(top_builddir)/src\
	@libxmlpl_cpp_runtime_CFLAGS@\
  @antlr_CFLAGS@\
  @BasicUtils_CFLAGS@

libxmlplCPP_la_CFLAGS =\
	-I$(top_builddir)
