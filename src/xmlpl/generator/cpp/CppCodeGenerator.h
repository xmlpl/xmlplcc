#ifndef CPPCODEGENERATOR_H
#define CPPCODEGENERATOR_H

#include "FunctionizeInfo.h"

#include <xmlpl/CodeGenerator.h>
#include <xmlpl/cpp/runtime/TypeID.h>
#include <xmlpl/parser/TargetTypeFlags.h>

#include <vector>
#include <map>
#include <string>

class Environment;

namespace xmlpl {
  class CppCodeGenerator : public CodeGenerator, public TargetTypeFlags {
    // Tab
    int tabLevel;
    
    // Main
    const FunctionDecl *mainFunc;

    // Package
    std::string namespaceStr;
    std::string namespaceHash;
    bool isNamespaceOn;
    xmlpl::Version version;

    // Context
    std::vector<std::string> contextStack;
    std::vector<std::string> rawContextStack;
   
    // Functionize
    typedef std::map<XmlPLAST *, FunctionizeInfo *> functionizeMap_t;
    functionizeMap_t functionizeMap;
    typedef enum {
      FUNCTIONIZE_DECL, FUNCTIONIZE_CALL, FUNCTIONIZE_IN_DECL
    } functionizeMode_t;
    functionizeMode_t functionizeMode;
    unsigned int nextFunctionizeId;
    
  public:
    CppCodeGenerator(std::ostream &out, const std::string sourceFile) :
      CodeGenerator(out, sourceFile), tabLevel(0), mainFunc(0),
      isNamespaceOn(false), nextFunctionizeId(0) {}

    virtual ~CppCodeGenerator() {}

    virtual void genHeader();
    virtual void genStandalone(Program *program);
    virtual void genLibrary(Program *program);

    virtual void visitAST(Argument *argument);
    virtual void visitAST(ArrayExpr *arrayExpr);
    virtual void visitAST(Assignment *assignment);
    virtual void visitAST(BinaryExpr *binaryExpr);
    virtual void visitAST(BlockStmt *blockStmt);
    virtual void visitAST(BreakStmt *breakStmt);
    virtual void visitAST(Cast *cast);
    virtual void visitAST(CaseStmt *caseStmt);
    virtual void visitAST(Constant *constant);
    virtual void visitAST(ContinueStmt *continueStmt);
    virtual void visitAST(DefaultCase *defaultCase);
    virtual void visitAST(Empty *empty);
    virtual void visitAST(ExpressionStmt *ExpressionStmt);
    virtual void visitAST(FilterExpr *filterExpr);
    virtual void visitAST(ForStmt *forStmt);
    virtual void visitAST(ForeachStmt *foreachStmt);
    virtual void visitAST(FunctionCall *functionCall);
    virtual void visitAST(FunctionDecl *functionDecl);
    virtual void visitAST(IfStmt *ifStmt);
    virtual void visitAST(ImportDecl *importDecl);
    virtual void visitAST(IntPredicate *intPredicate);
    virtual void visitAST(NameTest *nameTest);
    virtual void visitAST(NativeBlock *nativeBlock);
    virtual void visitAST(PackageDecl *packageDecl);
    virtual void visitAST(PathExpr *pathExpr);
    virtual void visitAST(Predicates *predicates);
    virtual void visitAST(Program *program);
    virtual void visitAST(RedirectStmt *redirectStmt);
    virtual void visitAST(ReturnStmt *returnStmt);
    virtual void visitAST(SequenceExpr *sequenceExpr);
    virtual void visitAST(Step *step);
    virtual void visitAST(SwitchStmt *switchStmt);
    virtual void visitAST(ThrowStmt *throwStmt);
    virtual void visitAST(TryStmt *tryStmt);
    virtual void visitAST(TypeTest *typeTest);
    virtual void visitAST(UnaryExpr *unaryExpr);
    virtual void visitAST(VariableDecl *variableDecl);
    virtual void visitAST(VariableRef *variableRef);
    virtual void visitAST(WhileStmt *whileStmt);
    virtual void visitAST(XMLAttr *xmlAttr);
    virtual void visitAST(XMLComment *xmlComment);
    virtual void visitAST(XMLElement *xmlElement);
    virtual void visitAST(XMLPI *xmlPI);
    virtual void visitAST(XMLQName *xmlQName);

    void sequenceSizeBuiltin(FunctionCall *);
    void sequenceResizeBuiltin(FunctionCall *);
    void stringLengthBuiltin(FunctionCall *);
    void prefixBuiltin(FunctionCall *);
    void qnameBuiltin1(FunctionCall *);
    void qnameBuiltin2(FunctionCall *);

    static void declareBuiltins(Environment *env);

    static void printBoxComment(std::ostream &s, const std::string c,
				unsigned width = 80);
    static std::string getTargetName(unsigned int type);
    static std::string getTypeCPPName(unsigned int type);
    static std::string getTypeName(unsigned int type);
    std::string getCPPName(const Name &name, const std::string prefix = "");
    static std::string getCPPNameStr(const std::string name);
    static std::string getCPPString(const std::string str);
    static std::string hashNamespace(const std::string ns);

    void namespaceOn();
    void namespaceOff();

    void pushContext(const std::string &context,
		     const std::string rawContext = "") {
      contextStack.push_back(context);
      rawContextStack.push_back(rawContext);
    }
    void popContext() {contextStack.pop_back();}
    std::string getContext();
    std::string getRawContext();

    void visitChildren(const XmlPLAST *ast) {
      for (XmlPLAST *child = ast->getChild(); child; child = child->getNext())
	child->visit(this);
    }
    void throwException(const std::string &msg, const XmlPLAST *ast);

    void tabUp() {tabLevel++;}
    void tabDown() {tabLevel--;}
    void setTabLevel(const int tabLevel) {this->tabLevel = tabLevel;}

  protected:
    void emitExpr(XmlPLAST *expr);
    void emitContext(const TargetType &targetType, unsigned int contextType);

    void funcDeclPreprocess(XmlPLAST *ast);
    void genFuncDecl(EnvEntryRef entry, bool ecall = false);
    bool functionize(XmlPLAST *ast);
  };

  class Tab {
  public:
    const int level;
    Tab(const int level) : level(level) {}
  };
  
  inline std::ostream &operator<<(std::ostream &s, const Tab &t) {
    for (int i = 0; i < t.level; i++)
      s << "  ";
    return s;
  }
  
#define TAB Tab(tabLevel)  
};
#endif // CPPCODEGENERATOR_H
