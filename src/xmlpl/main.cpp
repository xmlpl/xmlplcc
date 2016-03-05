#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicSignalCatch.h>

#include <getopt.h>
#include <unistd.h>

#include <string>
#include <list>
#include <iostream>
#include <fstream>

#include "xmlplcc.h"
#include "Options.h"
#include "Utils.h"
#include "ErrorHandler.h"

#include "generator/cpp/CppLanguage.h"

// Removes conflict with the VERSION token type
#ifdef VERSION
#undef VERSION
#endif
#include "../../config.h"

using namespace std;
using namespace xmlpl;

typedef enum {FIRST_OPT = 256,
	      NO_LINE_INFO,
	      SAVE_TEMPS,
	      LANGUAGE,
	      DEBUGFLAG,
	      DUMP_CORES
} long_opts;

static const struct option longopts[] = {
  {"version", 0, 0, 'V'},
  {"help", 0, 0, 'H'},
  {"no-line-info", 0, 0, NO_LINE_INFO},
  {"save-temps", 0, 0, SAVE_TEMPS},
  {"lang", 1, 0, LANGUAGE},
  {"debug", 1, 0, DEBUGFLAG},
  {"dump-cores", 0, 0, DUMP_CORES},
  {0, 0, 0, 0}
};

void printHelpString(string opt, string help) {
  cout << "  " << opt;
  for (int i = opt.length(); i < 22; i++) cout << ' ';
  cout << ' ' << help << endl;
}

void PrintUsage(bool error) {
  cout << "Usage: xmlplcc [options] input.xpl" << endl
       << "Options:" << endl;
  printHelpString("--help", "Display this information");
  printHelpString("--version", "Display version and exit");
  printHelpString("-X", "Do not compile, generate XML syntax tree and exit.");
  printHelpString("-S", "Do not build, compile to target language and exit.");
  printHelpString("-l", "Build a library instead of a standalone executable.");
  printHelpString("-o outfile", "Output to specfied file");
  printHelpString("--no-line-info", "Don't print line and column numbers.");
  printHelpString("-c", "Leave stack trace core files.");
  printHelpString("--save-temps", "Save tempary files.");
  printHelpString("-t", "Print full stack trace on exceptions.");
  printHelpString("-v", "Increase verbosity level.");
  printHelpString("-B <compile arg>", "Pass argument on to compiler.");
  printHelpString("-L <link arg>", "Pass argument on to linker.");
  printHelpString("-i", "Ignore errors.");
  printHelpString("--lang <language>", "Set target language.");
  printHelpString("--debug <flag>", "Turn on debug flag.");
  printHelpString("-g", "Build in debug mode.");
  printHelpString("--dump-cores", "Dump core files on parse errors");
  cout << endl;

  if (error) exit(1);
  exit(1);
}

void PrintVersion() {
  cout << "xmlplcc " << PACKAGE_VERSION << endl
       << "Copyright (C) 2004,2005,2006,2007 Joseph Coffland" << endl
       << "This is free software; see the source for copying conditions.  There is NO" << endl
       << "warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE."
       << endl << endl;

  exit(0);
}

typedef enum {XML_T, SOURCE_T, BINARY_T} target_t;

int main(int argc, char *argv[]) {
  ErrorHandler *errorHandler = ErrorHandler::getInstance();
  Options *options = Options::getInstance();

  try {
    Language *lang = new CppLanguage;
    Language::add(lang);
    options->setLanguage(lang);

    target_t target = BINARY_T;
    string outfile;
    bool ignoreErrors = false;
    list<string> compileArgs;
    list<string> linkArgs;

    int c;
    while ((c = getopt_long(argc, argv, "co:tXSlB:L:vig",
			    longopts, 0)) != -1) {
      switch (c) {
      case 'H': PrintUsage(false);
      case 'X': target = XML_T; break;
      case 'S': target = SOURCE_T; break;
      case 'l': options->setBuildLibrary(true); break;
      case 'V': PrintVersion();
      case 'o': outfile = optarg; break;
      case 't':
	BasicDebugger::initStackTrace(argv[0]);
	if (!options->getVerbosity())
	  options->increaseVerbosity();
	break;
      case 'c': BasicDebugger::leaveCores = true; break;
      case 'v': options->increaseVerbosity(); break;
      case 'B': compileArgs.push_back(optarg); break;
      case 'L': linkArgs.push_back(optarg); break;
      case 'i': ignoreErrors = true; break;
      case 'g':
	options->setDebugMode(true);
	compileArgs.push_back("-g");
	break;
      case LANGUAGE: options->setLanguage(Language::get(optarg)); break;
      case NO_LINE_INFO: options->setUseLineInfo(false); break;
      case SAVE_TEMPS: options->setSaveTemps(true); break;
      case DEBUGFLAG: ErrorHandler::getInstance()->setDebugFlags(optarg);
	break;
      case DUMP_CORES: options->setDumpCore(true); break;
      case '?':
      default: PrintUsage(true);
      }
    }

    if (argc == optind) PrintUsage(true);

    if (optind + 1 < argc) {
      string errStr = "Too many arguments on command line:";
      for (int i = optind + 1; i < argc; i++)
	errStr = errStr + " " + argv[i];

      ErrorHandler::error(errStr);

      PrintUsage(true);
    }

    

    // Open Input
    istream *in;
    ifstream input;
    const char *inputFilename = argv[optind];

    if (string("-") == inputFilename) {
      if (target == BINARY_T) {
	ErrorHandler::error("cannot compile to binary from stardard input!");
	return 1;
      }

      in = &cin;
      inputFilename = "";

    } else {
      input.open(inputFilename, ios::in);
      if (!input.is_open()) {
	ErrorHandler::error(string("cannot open file '") + inputFilename +
			    "' for input!");
	return 1;
      }
      
      in = &input;
    }

    // Parse
    errorHandler->setFilename(inputFilename);
    RefXmlPLAST tree;


    BasicSignalCatch<SIGSEGV> sigSegCatch;
    
    if (options->getDumpCore() || !SIGNALED(sigSegCatch))
      tree = parseXmlPL(*in, inputFilename);
    else THROW("Fatal error during parse");

    // Close Input
    if (input.is_open()) input.close();    

    // Check for errors
    if (!ignoreErrors && errorHandler->getErrors())
      throw BasicException("input contains errors");

    // Postprocess tree
    if (options->getDumpCore() || !SIGNALED(sigSegCatch))
      tree = postprocessXmlPL(tree);
    else THROW("Fatal error post processing tree");

    // Check for errors
    if (!ignoreErrors && errorHandler->getErrors())
      throw BasicException("input contains errors");

    // Open Output
    ostream *out = &cout;
    ofstream output;
    string outputFilename;

    if (target == BINARY_T)
      outputFilename = Utils::changeSuffix(inputFilename, "cpp");
    else outputFilename = outfile;

    if (outputFilename != "-") {
      if (outputFilename == "") {
	if (target == XML_T)
	  outputFilename = Utils::changeSuffix(inputFilename, "xml");
	else outputFilename = Utils::changeSuffix(inputFilename, "cpp");
      }
      
      output.open(outputFilename.c_str(), ios::out | ios::trunc);
      if (!output.is_open()) {
	ErrorHandler::error(string("cannot open file '") + outputFilename +
			    "' for output!");
	return 1;
      }
      
      out = &output;
    }

    if (options->getDumpCore() || !SIGNALED(sigSegCatch)) {
      switch (target) {
      case XML_T: outputXmlPLXML(tree, *out); break;
      case SOURCE_T:
      case BINARY_T:
	// Compile to target Language
	CodeGenerator *codeGen =
	  options->getLanguage()->createCodeGenerator(*out, inputFilename);
	  
	tree->visit(codeGen);
	break;
      }
      
    } else THROW("Fatal error generating code");
    
    // Close Output
    if (output.is_open()) output.close();

    // Build
    if (options->getDumpCore() || !SIGNALED(sigSegCatch)) {
      if (target == BINARY_T) {
	Builder *builder = options->getLanguage()->getBuilder();
	
	if (options->getBuildLibrary())
	  builder->buildLibrary(outputFilename, outfile, compileArgs,
				linkArgs);
	else
	  builder->buildStandalone(outputFilename, outfile, compileArgs,
				   linkArgs);
	
	if (!options->getSaveTemps()) unlink(outputFilename.c_str());
      }
      
    } else THROW("Fatal error during build");
      
    return 0;

  } catch (const BasicException &e) {
    const BasicFileLocation &location = e.getLocation();
    string msg = e.getMessage();

    if (location.getFilename() != "")
      errorHandler->setFilename(location.getFilename());

    if (location.getFunction() != "")
      msg = location.getFunction() + ": " + msg;

    int line = location.getLine();
    if (line == -1) line = 0;
    int column = location.getCol();
    if (column == -1) column = 0;

    ErrorHandler::error(msg, Location(line, column));

    if (options->getVerbosity()) cerr << e << endl;
  }

  return 1;
}
