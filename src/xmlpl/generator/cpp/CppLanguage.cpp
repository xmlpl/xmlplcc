#include "CppLanguage.h"

#include "CppCodeGenerator.h"
#include "CppLibraryImporter.h"
#include "CppBuilder.h"

#include <xmlpl/parser/environment/Environment.h>

#include <BasicUtils/BasicException.h>

using namespace xmlpl;
using namespace std;

CodeGenerator *CppLanguage::createCodeGenerator(std::ostream &out,
						const std::string sourceFile) {
  return new CppCodeGenerator(out, sourceFile);
}

LibraryImporter *CppLanguage::getLibraryImporter() {
  if (!libraryImporter) libraryImporter = new CppLibraryImporter;
  return libraryImporter;
}

Builder *CppLanguage::getBuilder() {
  if (!builder) builder = new CppBuilder;
  return builder;
}

void CppLanguage::declareBuiltins(Environment *env) {
  CppCodeGenerator::declareBuiltins(env);
}
