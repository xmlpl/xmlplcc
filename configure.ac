# Disable caching
define([AC_CACHE_LOAD], )
define([AC_CACHE_SAVE], )

# Init
AC_PREREQ(2.59)
AC_INIT([xmlplcc], 0.1.5, bugs@xmlpl.org)
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_AUX_DIR(./config)

AM_INIT_AUTOMAKE([nostdinc])
AM_CONFIG_HEADER(config.h)


# Flags
AC_COMPILE_FLAGS


# Tools
AC_PROG_CC
AC_PROG_CPP
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_LANG_CPLUSPLUS
AC_PROG_CXX
AC_PROG_CXXCPP
AC_PROG_INSTALL
AC_LIBTOOL_DLOPEN
AM_PROG_LIBTOOL
AC_PROG_YACC
AM_PROG_LEX


# Headers
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])


# Typedefs, structures, and compiler characteristics
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE


# Standard library functions
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([strchr strdup])


# Test install -C option
touch install.test
if $INSTALL -C install.test install.test2 >/dev/null 2>/dev/null; then
  INSTALL="${INSTALL} -C"
elif $INSTALL -p install.test install.test2 >/dev/null 2>/dev/null; then
  INSTALL="${INSTALL} -p"
fi
rm -f install.test install.test2



# getopt
AC_CHECK_HEADERS(getopt.h)
AC_CHECK_FUNC(getopt_long, , [AC_MSG_ERROR([Cannot find required function getopt_long])])


# BasicUtils
AC_CHECK_CONFIG(BasicUtils, 0.1.9, , [AC_MSG_ERROR([Required library BasicUtils not found!])])
AC_CHECK_LIB(BasicUtils, main, [true], [
  AC_MSG_ERROR([Could not link required library BasicUtils!])],
  $BasicUtils_LIBS)




# Antlr
AC_CHECK_CONFIG(antlr, 2.7.4, , [AC_MSG_ERROR([Required library antlr not found!])])
AC_CHECK_LIB(antlr, main, [true], [
  AC_MSG_ERROR([Could not link required library antlr!])],
  [$antlr_LIBS])


# libxmlpl-cpp-runtime
AC_CHECK_CONFIG(libxmlpl_cpp_runtime, $VERSION, , [AC_MSG_ERROR([Required library libxmlpl_cpp_runtime not found!])])
AC_CHECK_LIB(xmlpl_cpp_runtime, main, [true], [
  AC_MSG_ERROR([Could not link required library libxmlpl_cpp_runtime!])],
  [$libxmlpl_cpp_runtime_LIBS])



# Create Makefiles
AC_OUTPUT([Makefile
	  src/Makefile
	  src/xmlpl/Makefile
	  src/xmlpl/parser/Makefile
	  src/xmlpl/parser/ast/Makefile
	  src/xmlpl/parser/environment/Makefile
	  src/xmlpl/generator/Makefile
	  src/xmlpl/generator/cpp/Makefile
          tests/Makefile
          tests/prettyXMLParser
	  tests/compilerTest
          tests/ParserTests/Makefile
          tests/EnvironmentTests/Makefile
          tests/TypeValidationTests/Makefile
          tests/DOMTests/Makefile
          tests/RuntimeTests/Makefile
          tests/CompilerTests/Makefile
          tests/ImportTests/Makefile
          tests/NameTests/Makefile
          tests/XMLTests/Makefile
          tests/PathTests/Makefile
          tests/SequenceTests/Makefile
          tests/BugTests/Makefile
          tests/RedirectTests/Makefile
	  tests/libs/Makefile
          scripts/Makefile
          scripts/xmlplcc-config
	  ], [
          chmod +x scripts/xmlplcc-config tests/prettyXMLParser tests/compilerTest
          ]
         )

echo
echo
echo "   Everything seems to be ok."
echo "Now run 'make' and 'make install'."
echo
echo
