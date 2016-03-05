#ifndef INC_XmlPLParser_hpp_
#define INC_XmlPLParser_hpp_

#include <antlr/config.hpp>
/* $ANTLR 2.7.3 (20050127-10): "XmlPL.g" -> "XmlPLParser.hpp"$ */
#include <antlr/TokenStream.hpp>
#include <antlr/TokenBuffer.hpp>
#include "XmlPLLexerTokenTypes.hpp"
#include <antlr/LLkParser.hpp>

#line 1 "XmlPL.g"

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

#line 32 "XmlPLParser.hpp"
class CUSTOM_API XmlPLParser : public ANTLR_USE_NAMESPACE(antlr)LLkParser, public XmlPLLexerTokenTypes
{
#line 430 "XmlPL.g"

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
#line 36 "XmlPLParser.hpp"
public:
	void initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory );
#if 0
// constructor creation turned of with 'noConstructor' option
protected:
	XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k);
public:
	XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf);
protected:
	XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k);
public:
	XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer);
	XmlPLParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state);
// constructor creation turned of with 'noConstructor' option
#endif
	int getNumTokens() const
	{
		return XmlPLParser::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return XmlPLParser::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return XmlPLParser::tokenNames;
	}
	public: Name  name(
		const bool declaration = false
	);
	public: void keyword();
	public: void program(
		const EnvRef &env
	);
	public: void packageDecl(
		const EnvRef &env
	);
	public: void declaration(
		const EnvRef &env
	);
	public: void importDecl(
		const EnvRef &env
	);
	public: void identifierDecl(
		const EnvRef &env, bool allowFunc = false
	);
	public: void nativeBlock();
	public: void versionExpr();
	public: void versionRange();
	public: Version  version();
	public: unsigned int  type(
		const EnvRef &env
	);
	public: void argumentList(
		const EnvRef &env, args_t &args
	);
	public: void compoundStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void expression(
		const EnvRef &env, bool inFuncCall = false
	);
	public: Arg  argument(
		const EnvRef &env
	);
	public: unsigned int  typeName(
		const EnvRef &env
	);
	public: unsigned int  xmlType(
		const EnvRef &env
	);
	public: void statement(
		const EnvRef &env, TargetType targetType
	);
	public: void expressionStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void ifStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void foreachStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void forStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void whileStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void switchStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void breakStmt(
		TargetType targetType
	);
	public: void continueStmt(
		TargetType targetType
	);
	public: void returnStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void tryStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void throwStmt(
		const EnvRef &env
	);
	public: void redirectStmt(
		const EnvRef &env
	);
	public: void emptyStmt();
	public: void block(
		const EnvRef &env, TargetType targetType
	);
	public: void parenthesizedExpr(
		const EnvRef &env
	);
	public: void optionalExpr(
		const EnvRef &env
	);
	public: void caseStmt(
		const EnvRef &env, TargetType targetType
	);
	public: void defaultCase(
		const EnvRef &env, TargetType targetType
	);
	public: void caseConstant();
	public: void xmlNameTest();
	public: void assignmentExpr(
		const EnvRef &env, bool inFuncCall
	);
	public: void sequenceExpr(
		const EnvRef &env, bool inFuncCall
	);
	public: void assignOp();
	public: void xmlExpr(
		const EnvRef &env
	);
	public: void xmlElement(
		const EnvRef &env
	);
	public: void xmlComment(
		const EnvRef &env
	);
	public: void xmlPI(
		const EnvRef &env
	);
	public: void orExpr(
		const EnvRef &env
	);
	public: void xmlName();
	public: void xmlNameOrExpr(
		const EnvRef &env
	);
	public: void qname(
		const EnvRef &env
	);
	public: void attribute(
		const EnvRef &env
	);
	public: void stringOrExpr(
		const EnvRef &env
	);
	public: void andExpr(
		const EnvRef &env
	);
	public: void borExpr(
		const EnvRef &env
	);
	public: void bxorExpr(
		const EnvRef &env
	);
	public: void bandExpr(
		const EnvRef &env
	);
	public: void equalExpr(
		const EnvRef &env
	);
	public: void relExpr(
		const EnvRef &env
	);
	public: void shiftExpr(
		const EnvRef &env
	);
	public: void addExpr(
		const EnvRef &env
	);
	public: void mulExpr(
		const EnvRef &env
	);
	public: void unaryExpr(
		const EnvRef &env
	);
	public: void castExpr(
		const EnvRef &env
	);
	public: void iterExpr(
		const EnvRef &env
	);
	public: void pathExpr(
		const EnvRef &env
	);
	public: void releaseExpr(
		const EnvRef &env
	);
	public: void steps(
		const EnvRef &env
	);
	public: RefStep  abrevStep(
		const EnvRef &env
	);
	public: void predicates(
		const EnvRef &env, unsigned int contextType
	);
	public: void nodeTest(
		const EnvRef &env
	);
	public: RefStep  step(
		const EnvRef &env
	);
	public: void xmlQNameTest(
		const EnvRef &env
	);
	public: void typeTest(
		const EnvRef &env
	);
	public: void filterExpr(
		const EnvRef &env
	);
	public: void primaryExpr(
		const EnvRef &env
	);
	public: void constantExpr();
	public: void functionCall(
		const EnvRef &env
	);
	public: void varRef(
		const EnvRef &env
	);
	public: void contextStep(
		const EnvRef &env
	);
public:
	ANTLR_USE_NAMESPACE(antlr)RefAST getAST()
	{
		return ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST);
	}
	
protected:
	RefXmlPLAST returnAST;
private:
	static const char* tokenNames[];
#ifndef NO_STATIC_CONSTS
	static const int NUM_TOKENS = 162;
#else
	enum {
		NUM_TOKENS = 162
	};
#endif
	
	static const unsigned long _tokenSet_0_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_0;
	static const unsigned long _tokenSet_1_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_1;
	static const unsigned long _tokenSet_2_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_2;
	static const unsigned long _tokenSet_3_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_3;
	static const unsigned long _tokenSet_4_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_4;
	static const unsigned long _tokenSet_5_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_5;
	static const unsigned long _tokenSet_6_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_6;
	static const unsigned long _tokenSet_7_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_7;
	static const unsigned long _tokenSet_8_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_8;
	static const unsigned long _tokenSet_9_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_9;
	static const unsigned long _tokenSet_10_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_10;
	static const unsigned long _tokenSet_11_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_11;
	static const unsigned long _tokenSet_12_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_12;
	static const unsigned long _tokenSet_13_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_13;
	static const unsigned long _tokenSet_14_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_14;
	static const unsigned long _tokenSet_15_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_15;
	static const unsigned long _tokenSet_16_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_16;
	static const unsigned long _tokenSet_17_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_17;
	static const unsigned long _tokenSet_18_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_18;
	static const unsigned long _tokenSet_19_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_19;
	static const unsigned long _tokenSet_20_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_20;
	static const unsigned long _tokenSet_21_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_21;
	static const unsigned long _tokenSet_22_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_22;
	static const unsigned long _tokenSet_23_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_23;
	static const unsigned long _tokenSet_24_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_24;
	static const unsigned long _tokenSet_25_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_25;
	static const unsigned long _tokenSet_26_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_26;
	static const unsigned long _tokenSet_27_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_27;
	static const unsigned long _tokenSet_28_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_28;
	static const unsigned long _tokenSet_29_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_29;
	static const unsigned long _tokenSet_30_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_30;
	static const unsigned long _tokenSet_31_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_31;
	static const unsigned long _tokenSet_32_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_32;
	static const unsigned long _tokenSet_33_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_33;
	static const unsigned long _tokenSet_34_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_34;
	static const unsigned long _tokenSet_35_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_35;
	static const unsigned long _tokenSet_36_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_36;
	static const unsigned long _tokenSet_37_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_37;
	static const unsigned long _tokenSet_38_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_38;
	static const unsigned long _tokenSet_39_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_39;
	static const unsigned long _tokenSet_40_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_40;
	static const unsigned long _tokenSet_41_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_41;
	static const unsigned long _tokenSet_42_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_42;
	static const unsigned long _tokenSet_43_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_43;
	static const unsigned long _tokenSet_44_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_44;
	static const unsigned long _tokenSet_45_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_45;
	static const unsigned long _tokenSet_46_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_46;
};

#endif /*INC_XmlPLParser_hpp_*/
