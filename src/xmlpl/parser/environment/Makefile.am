EXTRA_DIST=XmlPLTypeTables.sxc

noinst_LTLIBRARIES = libxmlplEnvironment.la

libxmlplEnvironment_la_SOURCES :=\
	Environment.h\
	Environment.cpp\
	Name.h\
	Name.cpp\
	EnvEntry.h\
	EnvEntry.cpp\
	TypeEntry.h\
	TypeEntry.cpp\
	VarEntry.h\
	VarEntry.cpp\
	FuncEntry.h\
	FuncEntry.cpp\
	Type.h\
	Type.cpp\
	TypeTables.h\
	TypeTables.cpp\
	Arg.h\
	BuiltinFunctor.h\
	VersionExpression.h

libxmlplEnvironment_la_CXXFLAGS =\
	@libxmlpl_cpp_runtime_CFLAGS@\
  @antlr_CFLAGS@\
  @BasicUtils_CFLAGS@\
  -I../../..
