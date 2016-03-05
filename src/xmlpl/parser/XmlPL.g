header {
#include <antlr/SemanticException.hpp>
#include <iostream>
#include <algorithm>

#include <stdlib.h>

#include <xmlpl/parser/ast/XmlPLAST.h>
#include <xmlpl/parser/ast/XmlPLASTTypes.h>

#include <xmlpl/parser/environment/Type.h>
#include <xmlpl/parser/environment/Environment.h>
#include <xmlpl/ErrorHandler.h>
#include <xmlpl/Options.h>

using namespace std;
using namespace antlr;
using namespace xmlpl;
}

options {
  language="Cpp";
}


// ****************************************************************************
//                                    Lexer 
// ****************************************************************************
class XmlPLLexer extends Lexer;
options {
  k = 3;
  charVocabulary = '\3'..'\377' | '\u1000'..'\u1fff';
  noConstructors = true;
  testLiterals = false;
}
tokens {
    PROGRAM<AST=Program>;

    // Declarations
    PACKAGE_DECL; VERSION_RANGE; VERSION_OR;
    TYPE; ARGUMENT; VAR_DECL; FUNC_DECL; IMPORT_DECL;
   
    // Statements
    EXPR_STMT<AST=ExpressionStmt>; BREAK; CONTINUE; RETURN;

    IF; FOREACH; FOR; EMPTY<AST=Empty>; WHILE; SWITCH; CASE;
    DEFAULT; TRY; THROW; REDIRECT;

    NATIVE<AST=NativeBlock>; BLOCK<AST=BlockStmt>;

    // Expressions
    ASSIGN<AST=Assignment>; ADD_ASSIGN<AST=Assignment>;
    SUB_ASSIGN<AST=Assignment>; MUL_ASSIGN<AST=Assignment>;
    DIV_ASSIGN<AST=Assignment>; MOD_ASSIGN<AST=Assignment>;
    COMMA_ASSIGN<AST=Assignment>;

    SEQUENCE_EXPR<AST=SequenceExpr>;

    BIN_EXPR; OR<AST=BinaryExpr>; AND<AST=BinaryExpr>;
    BOR<AST=BinaryExpr>; BXOR<AST=BinaryExpr>; BAND<AST=BinaryExpr>;
    NE<AST=BinaryExpr>; EQ<AST=BinaryExpr>;
    GT<AST=BinaryExpr>; LTE<AST=BinaryExpr>; GTE<AST=BinaryExpr>;
    BSL<AST=BinaryExpr>; BSR<AST=BinaryExpr>;
    MOD<AST=BinaryExpr>;

    UNARY_EXPR; NOT<AST=UnaryExpr>; INC<AST=UnaryExpr>; DEC<AST=UnaryExpr>;
    BCOMP<AST=UnaryExpr>;

    ISA_EXPR;

    // PATH
    PATH<AST=PathExpr>; PREDICATES<AST=Predicates>;
    INT_PREDICATE<AST=IntPredicate>;
    STEP; NAME_TEST; TYPE_TEST;

    FILTER_EXPR<AST=FilterExpr>; ARRAY_EXPR<AST=ArrayExpr>; FCALL;
    VAR_REF<AST=VariableRef>;
    
    CONSTANT; INTEGER<AST=Constant>; REAL<AST=Constant>; VERSION;
    STRING<AST=Constant>; REGEX;

    // XML
    XML_QNAME; XML_ELEM; XML_ATTR; XML_COM; XML_PI;
    XML_COMMENT_CHARS<AST=Constant>; XML_PI_CHARS<AST=Constant>;

    CAST;
}
{
public:
    XmlPLLexer(ANTLR_USE_NAMESPACE(std)istream &in) :
      ANTLR_USE_NAMESPACE(antlr)
        CharScanner(new ANTLR_USE_NAMESPACE(antlr)CharBuffer(in), true) {
      initLiterals();
      initModeStack();
    }

    ~XmlPLLexer() {freeModeStack();}

    virtual void reportError(const RecognitionException &ex) {
      ErrorHandler::error(ex.getMessage(), Location(ex.getLine(),
                ex.getColumn()));
    }

    virtual void reportError(const ANTLR_USE_NAMESPACE(std)string &s) {
      ErrorHandler::error(s, Location(getLine(), getColumn()));
    }

    virtual void reportWarning(const ANTLR_USE_NAMESPACE(std)string &s) {
      ErrorHandler::warning(s, Location(getLine(), getColumn()));
    }

protected:
    int hexCharToInt(char c) {
      if ('0' <= c && c <= '9') return c - '0';
      if ('a' <= c && c <= 'f') return c - 'a' + 10;
      return c - 'A' + 10;
    }

    bool isNameChar(char c) {
      if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') ||
          ('0' <= c && c <= '9') || c == '_' || c == '.' || c == '-')
        return true;

      return false;
    }

    static const char L_NORM    = 0;
    static const char L_XCOM    = 1;
    static const char L_XPI1    = 2;
    static const char L_XPI2    = 3;
    static const char L_NATIVE  = 4;

    char *modeStack;
    int stackPtr;
    int stackSize;

    char mode() {return modeStack[stackPtr];}

    void pushMode(char mode) {
      stackPtr++;
      if (stackSize == stackPtr) {
        stackSize *= 2;
        modeStack = (char *)realloc(modeStack, sizeof(char) * stackSize);
      }

      modeStack[stackPtr] = mode;
    }

    void popMode() {if (stackPtr > 0) stackPtr--;}

    void initModeStack() {
      stackSize = 64;
      modeStack = (char *)malloc(sizeof(char) * stackSize);
      modeStack[0] = L_NORM;
      stackPtr = 0;
    }

    void freeModeStack() {
      if (modeStack) free(modeStack);
      modeStack = 0;
      stackPtr = -1;
      stackSize = 0;
    }
}

XML_COMMENT_CHARS
: {mode() == L_XCOM && ( LA(1) != '(' || LA(2) == '(')}?
( {LA(2) == '('}? "(("
| {LA(2) == ')'}? "))"
| {LA(2) != '-'}? '-'
| '\r' '\n' {newline();} 
| '\n'      {newline();}
| ~('-' | '(' | ')' | '\n' | '\r')
)+;

XML_PI_CHARS
: {mode() == L_XPI2 && ( LA(1) != '(' || LA(2) == ')')}?
( {LA(2) == '('}? "(("
| {LA(2) == ')'}? "))"
| {LA(2) != '>'}? '?'
| '\r' '\n' {newline();} 
| '\n'      {newline();}
| ~('?' | '(' | ')' | '\n' | '\r')
)+;

NATIVE_DATA
: {mode() == L_NATIVE}?
{int x = 0;}
({mode() == L_NATIVE}?
  ( '_' {if (x == 0 || x == 1 || x == 8 || x == 9) x++;
         else if (x != 2) x = 0;}
  | 'n' {if (x == 2) x++; else x = 0;}
  | 'a' {if (x == 3) x++; else x = 0;}
  | 't' {if (x == 4) x++; else x = 0;}
  | 'i' {if (x == 5) x++; else x = 0;}
  | 'v' {if (x == 6) x++; else x = 0;}
  | 'e' {if (x == 7) x++; else x = 0;}
  | '\r' '\n' {newline(); x = 0;}
  | '\n'      {newline(); x = 0;}
  |  ~('\n' | '\r' | '_' | 'n' | 'a' | 't' | 'i' | 'v' | 'e') {x = 0;}
  ) {if (x == 10) popMode();}
)+ {
  int len = getText().length();
  if (len >= 10)
  setText(getText().substr(0, len - 10));
};

protected
LETTER: 'a' .. 'z' | 'A' .. 'Z' ;
protected
DIGIT: '0' .. '9' ;
protected
HEX: DIGIT | 'a' .. 'f' | 'A' .. 'F' ;

protected
STR_ESC
: '\\'!
( 'n'  {$setText("\n");}
| 't'  {$setText("\t");}
| '\\' {$setText("\\");}
| '"'  {$setText("\"");}
| HEX_CODE
| OCT_CODE
| UNICODE
| ~('n' | 't' | '\\' | '\"' | 'x' | '0'..'9' | 'u' | 'U')
)
;

protected
REG_ESC
: '\\'!
( 'n'  {$setText("\n");}
| 't'  {$setText("\t");}
| '\'' {$setText("'");}
| HEX_CODE
| OCT_CODE
| UNICODE
| ~('n' | 't' | '\'' | 'x' | '0'..'9' | 'u' | 'U')
)
;

// Unicode
protected
UNICODE
: 'u' h:HEX_WORD {
  unsigned long c = strtol(h->getText().c_str(), 0, 16);

  if (0x80 <= c && c <= 0x7ff) {
    char buf[3];
    buf[0] = 0xc0 | ((c >> 6) & 0x1f);
    buf[1] = 0x80 | (c & 0x3f);
    buf[2] = 0;
    $setText(buf);

  } else if (0x800 <= c && c <= 0xffff) {
    char buf[4];
    buf[0] = 0xe0 | ((c >> 12) & 0x0f);
    buf[1] = 0x80 | ((c >> 6) & 0x3f);
    buf[2] = 0x80 | (c & 0x3f);
    buf[3] = 0;
    $setText(buf);

  } else
    reportError(string("Invalid unicode escape \\u") + $getText);
}
| 'U' h1:HEX_WORD h2:HEX_WORD {
  //unsigned long c1 = strtol(h1->getText().c_str(), 0, 16);
  //unsigned long c2 = strtol(h2->getText().c_str(), 0, 16);

  reportError(string("Unicode escape \\u") + $getText +
              " not yet supported");
}
;

protected
HEX_WORD: HEX_BYTE HEX_BYTE ;

protected
HEX_BYTE: HEX HEX ;

// Hex character codes
protected
HEX_CODE
: 'x' h1:HEX h2:HEX {
  int x = hexCharToInt(h1->getText()[0]) * 16 +
  hexCharToInt(h2->getText()[0]);
  $setText(x);
}
;

// Octal character codes
protected
OCT_CODE: o1:'0'..'3'
(options {warnWhenFollowAmbig = false;}: o2:'0'..'7'
  (options {warnWhenFollowAmbig = false;}: o3:'0'..'7')?
)? {
  int o = o1 - '0';
  if (o2) o = (o * 8) + o2 - '0';
  if (o3) o = (o * 8) + o3 - '0';            

  $setText(o);
}
| o4:'4'..'7'
(options {warnWhenFollowAmbig = false;}: o5:'0'..'7')? {
  int o = o4 - '0';
  if (o5) o = (o * 8) + o5 - '0';

  $setText(o);
}
;

// TODO Uni-code support

STRING: '"'! ( ~('"' | '\\' | '\n' | '\r') | STR_ESC )* '"'! ;
REGEX: '\''! ( ~('\'' | '\\' | '\n' | '\r') | REG_ESC )* '\''! ;

// TODO check for numeric overflow
INTEGER
: (DIGIT)+ ('.' (DIGIT)+ {$setType(REAL);}
  ('.' (DIGIT)+ {$setType(VERSION);})?)?
| {LA(2) == 'x'}? '0' 'x' (HEX)+
| {LA(2) == 'b'}? '0' 'b' ('0' | '1')+
;

S:
( ' '
| '\t' 
| '\r' '\n' {newline();} 
| '\n'      {newline();}
)
{$setType(Token::SKIP);}
;

COMMENT
: "(:"
( {LA(2) != ')'}? ':'
| '\r' '\n' {newline();}
| '\n'      {newline();}
| ~(':' | '\n' | '\r' )
)* ":)"
{$setType(Token::SKIP);}
;

SINGLE_COMMENT
: "::" (~('\n' | '\r'))*
{$setType(Token::SKIP);}
;

END_ELEM_SHORT: "/>" ;
END_ELEM: "</" ;

START_XML_COMM: "<!--" {pushMode(L_XCOM);} ;
END_XML_COMM: "-->" {if (mode() == L_XCOM) popMode();} ;

START_PI: "<?" {pushMode(L_XPI1);} ;
END_PI: "?>" {if (mode() == L_XPI2) popMode();} ;

SEMI: ';' ;
OCB: '{' ;
CCB: '}' ;
DOT: '.' ;
DOTDOT: ".." ;
ASSIGN: '=' ;
ADD_ASSIGN: "+=" ;
SUB_ASSIGN: "-=" ;
MUL_ASSIGN: "*=" ;
DIV_ASSIGN: "/=" ;
MOD_ASSIGN: "%=" ;
COMMA_ASSIGN: ",=" ;

COMMA: ',' ;
PLUS: '+' ;
MINUS: '-' ;
STAR: '*' ;
MOD: '%' ;
BOR: '|' ;
BAND: '&' ;
BXOR: '^' ;
BSL: "<<" ;
BSR: ">>" ;
BCOMP: '~' ;
NOT: '!' ;
OR: "||" ;
AND: "&&" ;
FS: '/' ;
FSFS: "//" ;

LESS: '<' ;
GT: '>' ;
LTE: "<=" ;
GTE: ">=" ;
EQ: "==" ;
NE: "!=" ;

INC: "++";
DEC: "--";

COLON: ':' ;
OPAREN: '(' {pushMode(L_NORM);} ;
CPAREN: ')' {popMode(); if (mode() == L_XPI1) {popMode(); pushMode(L_XPI2);}} ;
OSB: '[' ;
CSB: ']' ;
AT: '@' ;
QUESTION: '?' ;
DOLLAR: '$' ;

NAME
: (LETTER | '_') (LETTER | DIGIT | '_' | '.' | '-')*
{
  if (mode() == L_XPI1) {
    popMode();
    pushMode(L_XPI2);
  }

  $setType(testLiteralsTable(_ttype));
  if (_ttype == LITERAL___native__) pushMode(L_NATIVE);
}
;


// ****************************************************************************
//                                    Parser
// ****************************************************************************
class XmlPLParser extends Parser;
options {
  buildAST = true;
  ASTLabelType = "RefXmlPLAST";
  noConstructors = true;
}
{
public:
  XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenStream &lexer) :
    ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer, 1) {}

  virtual void reportError(const RecognitionException &ex) {
    ErrorHandler::error(ex.getMessage(), Location(ex.getLine(),
                ex.getColumn()));
  }

  virtual void reportError(const ANTLR_USE_NAMESPACE(std)string &s) {
    ErrorHandler::error(s);
  }

  virtual void reportWarning(const ANTLR_USE_NAMESPACE(std)string &s) {
    ErrorHandler::warning(s);
  }

  void addImplicitTypeTest(Step *step, XmlPLAST *test,
        const unsigned int type) {
    BinaryExpr *be = new BinaryExpr;
    be->setType(AND);

    TypeTest *typeTest = new TypeTest;
    typeTest->setTypeTest(type);
    typeTest->setLocation(step->getLocation());

    be->addChild(typeTest);
    be->addChild(test);

    step->setFirstChild(be);
  }

  bool isTypeName(const EnvRef &env, RefToken token) {
    EnvEntryRef entry = env->lookupAll(token->getText(), Location());
    return entry != 0 && entry->getEntryType() == EnvEntry::TYPE_ENTRY;
  }
}

name[const bool declaration = false] returns [Name n]
: nt:NAME
{
  if (!Name::parseName(#nt->getText(), n))
    ErrorHandler::error("invalid name", #nt->getLocation());
  if (declaration && n.getPrefix() != "")
    ErrorHandler::error("namespace not allowed in declaration");
}
;

keyword
: "__native__" | "as" | "attribute" | "boolean" | "break" | "byte"
| "case" | "catch" | "comment" | "constant" | "continue"
| "default" | "document" | "element" | "else" | "exception"
| "false" | "for" | "foreach" | "if" | "import" | "integer"
| "node" | "null" | "package" | "pi" | "prefix" | "qname" | "real"
| "redirect" | "return" | "string" | "switch" | "text" | "throw"
| "true" | "try" | "void" | "while"  ;

program[const EnvRef &env]
: (pd:packageDecl[env])? (declaration[env])* EOF!
{
  vector<EnvEntryRef> entries;
  if (Options::getInstance()->getBuildLibrary()) {
    if (#pd == 0)
      ErrorHandler::error("libraries must have a package declaration");

    // Get local symbols
    Environment::env_map_t::const_iterator it;
    for (it = env->begin(); it != env->end(); it++) {
      Environment::ns_map_t::const_iterator it2;
      it2 = it->second.find("");
      if (it2 == it->second.end()) continue;

      entries.push_back(it2->second);
    }

    // Sort symbols
    sort<vector<EnvEntryRef>::iterator, ltEnvEntry>(entries.begin(),
                    entries.end(), ltEnvEntry());
  }

  Program *p = new Program(entries);
  #program = #(p, #program);
}
;

// ********** Declarations **********
declaration[const EnvRef &env]
: importDecl[env]
| identifierDecl[env, true]
| nativeBlock
;

packageDecl![const EnvRef &env]
{Name n;}
: p:"package" n=nt:name (v:VERSION)? SEMI
{
  std::string versionStr = #v ? #v->getText() : "";
  std::string namespaceStr = n.getFullName();
  if (#v) namespaceStr += "-" + versionStr;
    env->setDefaultNamespace(namespaceStr);
  #packageDecl = new PackageDecl(namespaceStr, versionStr);
  #packageDecl->setLocation(#p->getLocation());

  Options::getInstance()->setVersion(versionStr);
}
;

importDecl[const EnvRef &env]
{Name n, as;}
: i:"import"^<AST=ImportDecl> n=nt:name!
  (ve:versionExpr)? ("as"! as=name!)? SEMI!
{
  if (as.getName() != "") {
    n.setName(as.getName());
    n.setPrefix(as.getPrefix());
  }

  const std::vector<EnvEntryRef> &entries =
  env->import(n, &*#ve, #nt->getLocation());

  if (entries.empty())
    ErrorHandler::warning("import did not find any symbols",
      #nt->getLocation());
  else {
    #i->setEntries(entries);
    n.setNamespace(entries[0]->getName().getNamespace());
  }

  #i->setName(n);
}
;

versionExpr
: versionRange (COMMA^<AST=VersionOr> versionRange)?
;

versionRange!
{int op = 0; Version v1, v2, max;}
: ((GT {op = GT;} | GTE {op = GTE;} | LESS {op = LESS;} | LTE {op = LTE;})
  v1=v1t:version | v2=v2t:version (MINUS {op = MINUS;} max=version!)?
  ) {
  VersionRange *vrange = new VersionRange;
  vrange->setOp(op);

  if (op == MINUS) {
    vrange->setVersion(v2);
    vrange->setMax(max);
    vrange->setLocation(#v2t->getLocation());

  } else if (op) {
    vrange->setVersion(v1);
    vrange->setLocation(#v1t->getLocation());

  } else {
    vrange->setVersion(v2);
    vrange->setLocation(#v2t->getLocation());
  }

  #versionRange = vrange;
}
;

version returns [Version v]
: ver:VERSION
{v = #ver->getText();}
;

identifierDecl[const EnvRef &env, bool allowFunc = false] {
  unsigned int t;
  Name n;
  args_t args;
  EnvRef extendedEnv = Environment::extend(env);
}
: (c:"constant"!)? t=type[env]! n=nt:name[true]!

  // Function Declaration
  ((
    {allowFunc}? OPAREN! (a:argumentList[extendedEnv, args])? CPAREN! {
      if (#c) #c->semanticError("cannot declare function to return constant!");

      EnvEntryRef entry;
      TargetType targetType;

      if (Type::isSequence(t)) targetType = t | TargetType::APPEND_FLAG;
      else if (t != Type::VOID_TYPE) targetType = t | TargetType::RETURN_FLAG;
      else targetType = t;

      // Declare Function
      entry = env->declareFunction(n.getName(), t, args, #nt->getLocation());

      // Create AST
      FunctionDecl *f = new FunctionDecl;
      f->setLocation(#nt->getLocation());
      f->setEntry(entry);
    }
    (s:compoundStmt[extendedEnv, targetType] | SEMI!) {
      if (entry != 0) {
        // Declare function body
        if (#s) {
          entry->declareBody(#nt->getLocation());
          f->setForwardDecl(false);
        }

        #identifierDecl = #(f, #identifierDecl);
      }
    }
  )

  // Variable Declaration
  |(
    (o:ASSIGN! e:expression[env])? SEMI! {
      EnvEntryRef entry = env->declareVariable(n.getName(), t, #c,
        #nt->getLocation());

      VariableDecl *v = new VariableDecl;
      v->setLocation(#nt->getLocation());
      v->setEntry(entry);

      if (t == Type::VOID_TYPE)
        v->semanticError("variable type cannot be void");

      if (#o) {
        #o->validateTypes(t, #e->getDataType());
        #e->setTargetType(t);
      }

      if (entry != 0) #identifierDecl = #(v, #identifierDecl);
    }
    )
  )
;

argumentList[const EnvRef &env, args_t &args]
{Arg a;}
: a=argument[env] {args.push_back(a);}
  (COMMA! a=argument[env] {args.push_back(a);})*
;

argument![const EnvRef &env] returns [Arg a]
: {unsigned int t; Name n;}
  t=type[env] (r:BAND!)? n=nt:name[true] {
    a = Arg(t, #r, n);
    Argument *arg = new Argument;
    arg->setLocation(#nt->getLocation());
    arg->setArg(a);
    arg->validate();

    // Declare arg
    env->declareVariable(n, t, false, #nt->getLocation());

    #argument = arg;
  }
;

type[const EnvRef &env] returns [unsigned int t = Type::UNKNOWN_TYPE]
: t=typeName[env] ({t != Type::VOID_TYPE}? ((b:OSB! CSB!) | i:INC | o:BSL))? {
  if (#b) t |= Type::SEQUENCE_FLAG;
  if (#i) t |= Type::ITERATOR_FLAG;
  if (#o) t |= Type::OSTREAM_FLAG;
}
;

typeName[const EnvRef &env] returns [unsigned int t = Type::UNKNOWN_TYPE]
: ( "string" | "integer" | "real" | "boolean" | "qname"
  | "prefix" | "exception" | "void") {
    if (env != 0)
      t = env->lookupType(#typeName->getText(), #typeName->getLocation());
  }
  | t=xmlType[env]
;

xmlType[const EnvRef &env] returns [unsigned int t = Type::UNKNOWN_TYPE]
: ( "node" | "document" | "element" | "attribute"
  | "text" | "comment" | "pi") {
    if (env != 0)
      t = env->lookupType(#xmlType->getText(), #xmlType->getLocation());
  }
;


// ********** Statements **********
statement[const EnvRef &env, TargetType targetType]
: (expressionStmt[env, targetType]
  | compoundStmt[env, targetType]
  | ifStmt[env, targetType]
  | foreachStmt[env, targetType]
  | forStmt[env, targetType]
  | whileStmt[env, targetType]
  | switchStmt[env, targetType]
  | breakStmt[targetType]
  | continueStmt[targetType]
  | returnStmt[env, targetType]
  | tryStmt[env, targetType]
  | throwStmt[env]
  | redirectStmt[env]
  | nativeBlock
  | emptyStmt
  ) {#statement->validate();}
;

expressionStmt[const EnvRef &env, TargetType targetType]
: s:expression[env] ({#s && #s->isXML()}? /* Empty */ | SEMI!) {
  if (#s) {
    ExpressionStmt *es = new ExpressionStmt(*#s);
    #expressionStmt = #(es, #expressionStmt);
    es->setTargetType(targetType);
  }
}
;

compoundStmt[const EnvRef &env, TargetType targetType]
: o:OCB! b:block[env->extend(env), targetType] CCB!
{#b->setLocation(#o->getLocation());}
;

block[const EnvRef &env, TargetType targetType]
: ({LA(2) != OPAREN}? identifierDecl[env] | statement[env, targetType])*
{#block = #([BLOCK], #block);}
;

ifStmt[const EnvRef &env, TargetType targetType]
: "if"^<AST=IfStmt> e:parenthesizedExpr[env] statement[env, targetType]
  (options {warnWhenFollowAmbig = false;}: "else"! statement[env, targetType])?
{if (#e) #e->setTargetType(Type::BOOLEAN_TYPE);}
;

foreachStmt[const EnvRef &env, TargetType targetType]
: "foreach"^<AST=ForeachStmt> e:parenthesizedExpr[env] {
  EnvRef extendedEnv = Environment::extend(env);
  extendedEnv->declareVariable(".", #e->getDataType() & ~Type::SEQUENCE_FLAG,
  true, #e->getLocation());
}
  s:statement[extendedEnv, targetType.setFlags(TargetType::LOOP_FLAGS)] {
    if (#e->isFilterable()) {
      #e->setNextSibling(0);

      ExpressionStmt *es = new ExpressionStmt(*#e);
      #foreachStmt = #(es, #e);
      es->setTargetType(targetType);
      #e->filterWith(#s);
      #e->setFunctionize(false);
    }
}
;

forStmt[const EnvRef &env, TargetType targetType]
: "for"^<AST=ForStmt>
  OPAREN! e1:optionalExpr[env] SEMI! e2:optionalExpr[env] SEMI!
  e3:optionalExpr[env] CPAREN!
  statement[env, targetType.setFlags(TargetType::LOOP_FLAGS)] {
    if (#e1) #e1->setTargetType(TargetType::VOID_TYPE);
    if (#e2) #e2->setTargetType(TargetType::BOOLEAN_TYPE);
    if (#e3) #e3->setTargetType(TargetType::VOID_TYPE);
  }
;

optionalExpr[const EnvRef &env]
: (e:expression[env])?
{if (!#e) #optionalExpr = #[EMPTY];}
;

whileStmt[const EnvRef &env, TargetType targetType]
: "while"^<AST=WhileStmt> e:parenthesizedExpr[env]
  statement[env, targetType.setFlags(TargetType::LOOP_FLAGS)]
{if (#e) #e->setTargetType(TargetType::BOOLEAN_TYPE);}
;

switchStmt[const EnvRef &env, TargetType targetType]
: s:"switch"^<AST=SwitchStmt> e:parenthesizedExpr[env] OCB!
  (caseStmt[env, targetType.setFlags(TargetType::BREAK_FLAG)])*
  (defaultCase[env, targetType.setFlags(TargetType::BREAK_FLAG)])? CCB!
;

caseStmt[const EnvRef &env, TargetType targetType]
: "case"^<AST=CaseStmt> (caseConstant) COLON! (statement[env, targetType])*
;

caseConstant
: i:INTEGER {#i->setDataType(Type::INTEGER_TYPE);}
| s:STRING  {#s->setDataType(Type::STRING_TYPE);}
//| OPAREN! xmlQNameTest CPAREN!
| xmlNameTest
;

defaultCase[const EnvRef &env, TargetType targetType]
: "default"^<AST=DefaultCase> COLON! (statement[env, targetType])*
;

breakStmt[TargetType targetType]
: b:"break"<AST=BreakStmt> SEMI!
{if (!targetType.hasBreak()) #b->semanticError("break not allowed here");}
;

continueStmt[TargetType targetType]
: c:"continue"<AST=ContinueStmt> SEMI! {
  if (!targetType.hasContinue())
    #c->semanticError("continue not allowed here");
}
;

returnStmt[const EnvRef &env, TargetType targetType]
: r:"return"^<AST=ReturnStmt> (e:expression[env])? SEMI! {
  if (!targetType.hasReturn() && #e)
    #r->semanticError("return statement with value not allowed here");
  if (#e) #e->setTargetType(targetType);
}
;

tryStmt[const EnvRef &env, TargetType targetType]
: "try"^<AST=TryStmt> compoundStmt[env, targetType] c:"catch"! {
  EnvRef extendedEnv = Environment::extend(env);
  extendedEnv->declareVariable("error", Type::STRING_TYPE, true,
    #c->getLocation());
  extendedEnv->declareVariable("line", Type::INTEGER_TYPE, true,
    #c->getLocation());
  extendedEnv->declareVariable("column", Type::INTEGER_TYPE, true,
    #c->getLocation());
}
  compoundStmt[extendedEnv, targetType]
;

throwStmt[const EnvRef &env]: "throw"^<AST=ThrowStmt> expression[env] SEMI! ;

redirectStmt[const EnvRef &env] {unsigned int t;}
: r:"redirect"^<AST=RedirectStmt>
  OPAREN! e:expression[env] CPAREN! {
    t = (#e->getDataType() & ~Type::OSTREAM_FLAG) |
        Type::SEQUENCE_FLAG | TargetType::APPEND_FLAG;
  } statement[env, t]
{#r->setDataType(t);}
;

nativeBlock
: "__native__"^<AST=NativeBlock> d:NATIVE_DATA! {
  if (#d) #nativeBlock->setText(#d->getText());
  else #nativeBlock->setText("");
}
;

emptyStmt!: s:SEMI {
  #emptyStmt = new Empty(*#s);
  ErrorHandler::warning(
    "Use of the empty statement is not necessary or recommended",
    #s->getLocation());
}
;

// ********** Expressions **********
expression[const EnvRef &env, bool inFuncCall = false]
: assignmentExpr[env, inFuncCall]
;

assignmentExpr![const EnvRef &env, bool inFuncCall]
: l:sequenceExpr[env, inFuncCall]
  (a:assignOp r:assignmentExpr[env, inFuncCall])? {
    if (#a) {
      #assignmentExpr = #(#a, #l, #r);
      #a->validate();
    } else #assignmentExpr = #l;
  }
;

assignOp
: ASSIGN | ADD_ASSIGN | SUB_ASSIGN | MUL_ASSIGN
| DIV_ASSIGN | MOD_ASSIGN | COMMA_ASSIGN        
;

// inFuncCall and ignoring the warning disambiguate the commas in
// function calls from commas in sequence expressions.
sequenceExpr[const EnvRef &env, bool inFuncCall]
: xmlExpr[env] (options {warnWhenFollowAmbig = false;}:
    {!inFuncCall}? COMMA! xmlExpr[env])* {
  if (#sequenceExpr && #sequenceExpr->getNext()) {
    SequenceExpr *se = new SequenceExpr();
    se->setDataType(#sequenceExpr->getDataType() | Type::SEQUENCE_FLAG);

    #sequenceExpr = #(se, #sequenceExpr);
  }
}
;

xmlExpr[const EnvRef &env]
: xmlElement[env]
| xmlComment[env]
| xmlPI[env]
| orExpr[env]
;

xmlName!
: (n:NAME | k:keyword) {
  Constant *c = new Constant(#n ? *#n : *#k);
  c->setDataType(Type::STRING_TYPE);
  #xmlName = c;
}
;

xmlNameOrExpr[const EnvRef &env]: xmlName | parenthesizedExpr[env] ;

qname[const EnvRef &env]
: (n0:xmlName | n1:parenthesizedExpr[env]) (COLON! n2:xmlNameOrExpr[env])? {
  XMLQName *q = new XMLQName;

  if (#n2) {
    if (#n0) {
      EnvEntryRef pre =
        env->lookupVariable(#n0->getText(), #n0->getLocation());
      if (pre != 0) {
        if (pre->getType() != Type::PREFIX_TYPE)
          #n0->semanticError(#n0->getText() + " is not a prefix");

        VariableRef *vref = new VariableRef;
        vref->setLocation(#n0->getLocation());
        vref->setEnvEntry(pre);

        vref->setNextSibling(&*#n2);
        #qname = vref;

      } else #n0->semanticError("must declare prefix before use");

    } else #n1->setTargetType(Type::PREFIX_TYPE);

    #n2->setTargetType(Type::STRING_TYPE);

  } else if (#n0) #n0->setTargetType(Type::QNAME_TYPE);
  else #n1->setTargetType(Type::QNAME_TYPE);

  #qname = #(q, #qname);
}
;

xmlElement[const EnvRef &env]
: x:LESS^<AST=XMLElement> n1:qname[env] (attribute[env])*
  ( s:END_ELEM_SHORT!
  | ( GT! b:block[env->extend(env), TargetType::APPEND_FLAG |
      Type::NODE_SEQ_TYPE] end:END_ELEM! (n2:qname[env]!)? GT!)
  ) {
    // TODO check that ending qnames match
    #x->setEnvDepth(env->getDepth());
    #x->validate();
  }
;

stringOrExpr[const EnvRef &env]
: s:STRING {#s->setDataType(Type::STRING_TYPE);}
| (e:parenthesizedExpr[env] {#e->setTargetType(Type::STRING_TYPE);})
;

attribute[const EnvRef &env]:
  qname[env] ASSIGN^<AST=XMLAttr> stringOrExpr[env] ;

xmlComment[const EnvRef &env]
: START_XML_COMM^<AST=XMLComment>
  ( t:XML_COMMENT_CHARS {#t->setDataType(Type::STRING_TYPE);}
  | e:parenthesizedExpr[env] {#e->setTargetType(Type::STRING_TYPE);}
  )* END_XML_COMM!
;

xmlPI[const EnvRef &env]
: pi:START_PI^<AST=XMLPI> n:xmlNameOrExpr[env] {#n->setTargetType(Type::STRING_TYPE);}
  ( t:XML_PI_CHARS {#t->setDataType(Type::STRING_TYPE);}
  | e:parenthesizedExpr[env] {#e->setTargetType(Type::STRING_TYPE);}
  )* END_PI!
;

orExpr[const EnvRef &env]: andExpr[env] (b:OR^ andExpr[env] {#b->validate();})* ;

andExpr[const EnvRef &env]: borExpr[env] (b:AND^ borExpr[env] {#b->validate();})* ;

borExpr[const EnvRef &env] : bxorExpr[env] (b:BOR^ bxorExpr[env] {#b->validate();})* ;

bxorExpr[const EnvRef &env]: bandExpr[env] (b:BXOR^ bandExpr[env] {#b->validate();})* ;

bandExpr[const EnvRef &env]: equalExpr[env] (b:BAND^ equalExpr[env] {#b->validate();})* ;

equalExpr[const EnvRef &env]
: relExpr[env] ((b1:NE^ | b2:EQ^ ) relExpr[env] {
  if (#b1) {#b1->validate(); #b1 = 0;}
  else if (#b2) {#b2->validate(); #b2 = 0;}
})*
;

relExpr[const EnvRef &env]
: shiftExpr[env] (options {warnWhenFollowAmbig = false;}:
  (b1:LESS^<AST=BinaryExpr> | b2:GT^ | b3:LTE^ | b4:GTE^)
  shiftExpr[env] {
    if (#b1) {#b1->validate(); #b1 = 0;}
    else if (#b2) {#b2->validate(); #b2 = 0;}
    else if (#b3) {#b3->validate(); #b3 = 0;}
    else if (#b4) {#b4->validate(); #b4 = 0;}
})*
;

shiftExpr[const EnvRef &env]
: addExpr[env] ((b1:BSL^ | b2:BSR^) addExpr[env] {
  if (#b1) {#b1->validate(); #b1 = 0;}
  else if (#b2) {#b2->validate(); #b2 = 0;}
})*
;

addExpr[const EnvRef &env]
: mulExpr[env] (options {warnWhenFollowAmbig = false;}:
  (b1:PLUS^<AST=BinaryExpr> | b2:MINUS^<AST=BinaryExpr>) mulExpr[env] {
    if (#b1) {#b1->validate(); #b1 = 0;}
    else if (#b2) {#b2->validate(); #b2 = 0;}
  })*
;

mulExpr[const EnvRef &env]
: unaryExpr[env] ((b1:STAR^<AST=BinaryExpr> | b2:FS^<AST=BinaryExpr> | b3:MOD^)
  unaryExpr[env] {
    if (#b1) {#b1->validate(); #b1 = 0;}
    else if (#b2) {#b2->validate(); #b2 = 0;}
    else if (#b3) {#b3->validate(); #b3 = 0;}
  })*
;

unaryExpr[const EnvRef &env]
: n:NOT^ unaryExpr[env] {#n->validate();}
| m:MINUS^<AST=UnaryExpr> unaryExpr[env] {#m->validate();}
| p:PLUS^<AST=UnaryExpr> unaryExpr[env] {#p->validate();}
| c:BCOMP^ unaryExpr[env] {#c->validate();}
| {isTypeName(env, LT(2)) && LA(3) != OPAREN}? castExpr[env]
| iterExpr[env]
;

castExpr[const EnvRef &env]
{unsigned int t;}
: c:OPAREN^<AST=Cast> t=type[env]! CPAREN! unaryExpr[env] {
  #c->setDataType(t);
  #c->validate();
}
;

iterExpr[const EnvRef &env]
: i:INC^ unaryExpr[env] {#i->validate();}
| d:DEC^ unaryExpr[env] {#d->validate();}
| pathExpr[env] (options {warnWhenFollowAmbig = false;}:
    ( i2:INC^ {#i2->setPost(true); #i2->validate();}
    | d2:DEC^ {#d2->setPost(true); #d2->validate();}
    )
  )*
;

pathExpr![const EnvRef &env]
: e:releaseExpr[env] {
  // Jump out if this is really a divide
  if (#e == 0 || !Type::get(#e->getDataType()).isPathType()) return;
}
  (options {warnWhenFollowAmbig = false;}: s:steps[env])? {
    if (#e->isFilterable()) {
      if (#s) #e->filterWith(#s);
      #pathExpr = #e;

    } else if (#s) {
      #pathExpr = #([PATH], #e);
      #pathExpr->setEnvDepth(env->getDepth());
      #pathExpr->validate();
      #pathExpr->filterWith(#s);

    } else #pathExpr = #e;
  }
;

// TODO handle descendant-or-self abreviation
steps![const EnvRef &env] {RefStep s;}
: f:FS s=abrevStep[env] (p:predicates[env, s->getDataType()]!)?
  (options {warnWhenFollowAmbig = false;}: c:steps[env])? {
    if (#p) {
      s->filterWith(#p);
      if (#c) #p->filterWith(#c);

    } else if (#c) s->filterWith(#c);

  #steps = s;
}
;

abrevStep![const EnvRef &env] returns [RefStep s]
: n:nodeTest[env] {
  // Implicit child step
  s = new Step;
  s->setLocation(#n->getLocation());
  s->setAxis(Step::CHILD_AXIS);
  s->addChild(&*#n);

  if (#n->getType() != TYPE_TEST)
  addImplicitTypeTest(s, &*#n, Type::ELEMENT_TYPE);
  s->validate();
}
| s=step[env]
;

step[const EnvRef &env] returns [RefStep s]
: ( a:AT^<AST=Step> n:nodeTest[env] {
  #a->setAxis(Step::ATTRIBUTE_AXIS);
  if (#n->getType() == TYPE_TEST)
    #n->semanticError("type test not allowed on attribute axis");
  s = #a;
}
| p:DOTDOT<AST=Step> {
  #p->setAxis(Step::PARENT_AXIS);
  #p->addChild(new Empty); // Place holder
  s = #p;
}
| q:QUESTION^<AST=Step> n2:nodeTest[env]! {
  #q->setAxis(Step::CHILD_AXIS);
  if (#n2->getType() == TYPE_TEST)
    #n2->semanticError("type test not allowed with ?");
  addImplicitTypeTest(#q, #n2, Type::PI_TYPE);
  s = #q;
}
) {#step->validate();}
;

predicates![const EnvRef &env, unsigned int contextType] {
  contextType &= ~Type::SEQUENCE_FLAG;
  unsigned int refCount = 0;
  RefXmlPLAST intPred;
  EnvRef extendedEnv = Environment::extend(env);
  EnvEntryRef entry;
  EnvEntryRef posEntry;

  RefPredicates preds;
}
: (o:OSB! {
  if (entry == 0)
    entry =
      extendedEnv->declareVariable(".", contextType, true, #o->getLocation());
  if (posEntry == 0)
    posEntry =
      extendedEnv->declareVariable("position", Type::INTEGER_TYPE, true,
                                   #o->getLocation());

} e:expression[extendedEnv] {
  if (intPred != 0) #e->semanticError("cannot filter non-sequence type");

  if (#e->getDataType() == Type::INTEGER_TYPE) {
    if (refCount < entry->getEnvRefCount())
      #e->semanticError("cannot reference '.' from integer predicate");

    intPred = #([INT_PREDICATE], #e);
    intPred->setLocation(#o->getLocation());

  } else {
    if (preds == 0) {
      preds = new Predicates;
      preds->setLocation(#o->getLocation());
    }
    preds->addChild(&*#e);
  }

  refCount = entry->getEnvRefCount();
}
  CSB!) {            
    if (preds) {
      if (intPred != 0) preds->filterWith(intPred);

      if (posEntry->getEnvRefCount()) preds->setRequiresPosition(true);
      #predicates = preds;

    } else #predicates = intPred;
  }
;

nodeTest[const EnvRef &env]
// Differentiates from type test below
: {LA(2) != OPAREN}? xmlQNameTest[env]
| typeTest[env]
| OPAREN! xmlQNameTest[env] (b:BOR^ {#b->setType(OR);} xmlQNameTest[env])* CPAREN!
;

typeTest[const EnvRef &env]
: {unsigned int type;}
  type=t:xmlType[env] OPAREN! CPAREN! {
    TypeTest *nt = new TypeTest;
    nt->setTypeTest(type);
    nt->setLocation(#t->getLocation());

    #typeTest = nt;
  }
;

xmlQNameTest[const EnvRef &env]
: n1:xmlNameTest (COLON! n2:xmlNameTest)? {
  NameTest *nt = new NameTest;
  nt->setLocation(#n1->getLocation());

  if (#n2) {
    if (#n1->getType() == CONSTANT) {
      EnvEntryRef pre = env->lookupVariable(#n1->getText(), #n1->getLocation());
      if (pre != 0) {
        if (pre->getType() != Type::PREFIX_TYPE)
          #n1->semanticError(#n1->getText() + " is not a prefix");

        VariableRef *vref = new VariableRef;
        vref->setLocation(#n1->getLocation());
        vref->setEnvEntry(pre);

        nt->addChild(vref);

      } else #n1->semanticError("must declare prefix before use");

    } else nt->setPrefix(#n1->getText());

    nt->setName(#n2->getText());

  } else nt->setName(#n1->getText());

  #xmlQNameTest = nt;
}
;

xmlNameTest: xmlName | REGEX | STAR ;


// TODO implement release expressions
releaseExpr[const EnvRef &env]: (d:DOLLAR!)? filterExpr[env] ;

filterExpr![const EnvRef &env]
{EnvEntryRef entry;}
: e:primaryExpr[env] (p:predicates[env, #e->getDataType()])? {
  if (#e && #p) {
    if (#e->isFilterable()) #e->filterWith(#p);

    else {
      if (#p->getType() == INT_PREDICATE) {
        // Make array expression
        RefXmlPLAST intPred = ((IntPredicate *)&*#p)->getChild();

        #filterExpr = #([ARRAY_EXPR], #e, intPred);
        #filterExpr->validate();

      } else {
        #filterExpr = #([FILTER_EXPR], #e);
        #filterExpr->setEnvDepth(env->getDepth());
        #filterExpr->validate();
        #filterExpr->filterWith(#p);
      }
    }
  } else #filterExpr = #e;
}
;

primaryExpr[const EnvRef &env]
: constantExpr 
| {LA(2) == OPAREN}? functionCall[env]
| varRef[env]
| parenthesizedExpr[env]
| contextStep[env]
;

contextStep![const EnvRef &env]
{RefStep s;}
: s=step[env] {
  VariableRef *vref = new VariableRef;
  vref->setLocation(s->getLocation());

  EnvEntryRef var = env->lookupVariable(".", vref->getLocation());
  vref->setEnvEntry(var);

  #contextStep = #([PATH], vref);
  #contextStep->setEnvDepth(env->getDepth());
  #contextStep->validate();
  #contextStep->filterWith(&*s);
}
;

varRef![const EnvRef &env]
: {Name n;}
  (n=nt:name | d:DOT {n = ".";}) {
    VariableRef *vref = new VariableRef;
    vref->setLocation(#nt ? #nt->getLocation() : #d->getLocation());
    vref->setEnvEntry(env->lookupVariable(n, vref->getLocation()));

    #varRef = vref;
  }
;

parenthesizedExpr[const EnvRef &env]: OPAREN! expression[env] CPAREN! ;

constantExpr
: i:INTEGER {#i->setDataType(Type::INTEGER_TYPE);}
| s:STRING  {#s->setDataType(Type::STRING_TYPE);}
| t:"true"<AST=Constant>  {#t->setDataType(Type::BOOLEAN_TYPE);}
| f:"false"<AST=Constant> {#f->setDataType(Type::BOOLEAN_TYPE);}
| n:"null"<AST=Constant>  {#n->setDataType(Type::NULL_TYPE);}
| r:REAL                  {#r->setDataType(Type::REAL_TYPE);}
;

functionCall[const EnvRef &env]
{Name n;}
: n=nt:name! OPAREN! (expression[env, true] (COMMA! expression[env, true])*)? CPAREN! {
  args_t args;
  for (XmlPLAST *expr = &*#functionCall; expr; expr = expr->getNext())
    args.push_back(Arg(expr->getDataType(), !expr->isConstant()));

  FunctionCall *f = new FunctionCall;
  f->setLocation(#nt->getLocation());

  EnvEntryRef func = env->lookupFunction(n, args, #nt->getLocation());
  f->setEnvEntry(func);

  #functionCall = #(f, #functionCall);
  #functionCall->validate();
}
;
