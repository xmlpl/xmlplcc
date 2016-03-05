#include "Utils.h"

#include "Options.h"
#include "ErrorHandler.h"

#include "parser/ast/XmlPLAST.h"
#include "parser/ast/Cast.h"
#include "parser/environment/Environment.h"

#include <BasicUtils/BasicException.h>
#include <BasicUtils/BasicProcess.h>
#include <BasicUtils/BasicPipe.h>

#include <stdlib.h>

using namespace xmlpl;
using namespace std;

string Utils::removeSuffix(string filename) {
  string::size_type pos = filename.find_last_of('.');
  if (pos == string::npos) return filename;
  return filename.substr(0, pos);
}

string Utils::changeSuffix(string filename, string suffix) {
  return removeSuffix(filename) + "." + suffix;
}

void Utils::argsFromCommand(list<string> &args) {
  BasicProcess proc;
  string command = args.front();
  
  BasicPipe *argsPipe = proc.getChildPipe(BasicProcess::FROM_CHILD, 1);
  proc.exec(args);
  
  istream *argStream = argsPipe->getOutStream();
  args.clear();
  
  string arg;
  while (true) {
    *argStream >> arg;
    if (argStream->eof()) break;
    
    args.push_back(arg);
  }
  
  proc.wait();
  if (proc.getReturnCode())
    throw BasicException(command + " returned an error!  " +
			 "Make sure it can be found on your PATH.");
}

void Utils::runCommand(list<string> &args) {
  if (Options::getInstance()->getVerbosity() > 0) {
    cout << "@";
    for (list<string>::iterator it = args.begin(); it != args.end(); it++)
      cout << " " << *it;
    cout << endl;
  }
  
  BasicProcess proc;
  proc.exec(args);
  proc.wait();

  if (proc.getReturnCode())
    throw BasicException(args.front() + " returned an error");
}

string Utils::getEnvVar(const string var, const string defaultValue) {
  const char *value = getenv(var.c_str());

  if (!value || strcmp(value, "") == 0) return defaultValue;
  return value;
}
