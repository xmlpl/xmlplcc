SUBDIRS = ast environment

noinst_LTLIBRARIES = libxmlplParser.la

ANTLR_SOURCES =\
	XmlPLParser.cpp\
	XmlPLParser.hpp\
	XmlPLLexer.cpp\
	XmlPLLexer.hpp\
	XmlPLLexerTokenTypes.hpp

EXTRA_DIST = XmlPL.g $(ANTLR_SOURCES)

BUILT_SOURCES =\
	$(ANTLR_SOURCES)

libxmlplParser_la_SOURCES :=\
	TargetType.h\
	TargetTypeFlags.h\
	$(BUILT_SOURCES)

libxmlplParser_la_CXXFLAGS =\
	-I@antlr_PREFIX@/include\
	@libxmlpl_cpp_runtime_CFLAGS@\
  @BasicUtils_CFLAGS@\
  -I../..


# Built sources rules
XmlPLParser.cpp: XmlPL.g
	antlr $< && touch $@

XmlPLParser.hpp: XmlPLParser.cpp
XmlPLLexer.cpp: XmlPLParser.cpp
XmlPLLexer.hpp: XmlPLParser.cpp
XmlPLLexerTokenTypes.hpp: XmlPLParser.cpp

clean-built:
	rm -f $(BUILT_SOURCES) XmlPLLexerTokenTypes.txt
