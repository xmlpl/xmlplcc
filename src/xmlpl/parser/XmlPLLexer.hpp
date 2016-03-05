#ifndef INC_XmlPLLexer_hpp_
#define INC_XmlPLLexer_hpp_

#include <antlr/config.hpp>
/* $ANTLR 2.7.3 (20050127-10): "XmlPL.g" -> "XmlPLLexer.hpp"$ */
#include <antlr/CommonToken.hpp>
#include <antlr/InputBuffer.hpp>
#include <antlr/BitSet.hpp>
#include "XmlPLLexerTokenTypes.hpp"
#include <antlr/CharScanner.hpp>
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

#line 32 "XmlPLLexer.hpp"
class CUSTOM_API XmlPLLexer : public ANTLR_USE_NAMESPACE(antlr)CharScanner, public XmlPLLexerTokenTypes
{
#line 88 "XmlPL.g"

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
#line 36 "XmlPLLexer.hpp"
private:
	void initLiterals();
public:
	bool getCaseSensitiveLiterals() const
	{
		return true;
	}
public:
#if 0
// constructor creation turned of with 'noConstructor' option
	XmlPLLexer(ANTLR_USE_NAMESPACE(std)istream& in);
	XmlPLLexer(ANTLR_USE_NAMESPACE(antlr)InputBuffer& ib);
	XmlPLLexer(const ANTLR_USE_NAMESPACE(antlr)LexerSharedInputState& state);
// constructor creation turned of with 'noConstructor' option
#endif
	ANTLR_USE_NAMESPACE(antlr)RefToken nextToken();
	public: void mXML_COMMENT_CHARS(bool _createToken);
	public: void mXML_PI_CHARS(bool _createToken);
	public: void mNATIVE_DATA(bool _createToken);
	protected: void mLETTER(bool _createToken);
	protected: void mDIGIT(bool _createToken);
	protected: void mHEX(bool _createToken);
	protected: void mSTR_ESC(bool _createToken);
	protected: void mHEX_CODE(bool _createToken);
	protected: void mOCT_CODE(bool _createToken);
	protected: void mUNICODE(bool _createToken);
	protected: void mREG_ESC(bool _createToken);
	protected: void mHEX_WORD(bool _createToken);
	protected: void mHEX_BYTE(bool _createToken);
	public: void mSTRING(bool _createToken);
	public: void mREGEX(bool _createToken);
	public: void mINTEGER(bool _createToken);
	public: void mS(bool _createToken);
	public: void mCOMMENT(bool _createToken);
	public: void mSINGLE_COMMENT(bool _createToken);
	public: void mEND_ELEM_SHORT(bool _createToken);
	public: void mEND_ELEM(bool _createToken);
	public: void mSTART_XML_COMM(bool _createToken);
	public: void mEND_XML_COMM(bool _createToken);
	public: void mSTART_PI(bool _createToken);
	public: void mEND_PI(bool _createToken);
	public: void mSEMI(bool _createToken);
	public: void mOCB(bool _createToken);
	public: void mCCB(bool _createToken);
	public: void mDOT(bool _createToken);
	public: void mDOTDOT(bool _createToken);
	public: void mASSIGN(bool _createToken);
	public: void mADD_ASSIGN(bool _createToken);
	public: void mSUB_ASSIGN(bool _createToken);
	public: void mMUL_ASSIGN(bool _createToken);
	public: void mDIV_ASSIGN(bool _createToken);
	public: void mMOD_ASSIGN(bool _createToken);
	public: void mCOMMA_ASSIGN(bool _createToken);
	public: void mCOMMA(bool _createToken);
	public: void mPLUS(bool _createToken);
	public: void mMINUS(bool _createToken);
	public: void mSTAR(bool _createToken);
	public: void mMOD(bool _createToken);
	public: void mBOR(bool _createToken);
	public: void mBAND(bool _createToken);
	public: void mBXOR(bool _createToken);
	public: void mBSL(bool _createToken);
	public: void mBSR(bool _createToken);
	public: void mBCOMP(bool _createToken);
	public: void mNOT(bool _createToken);
	public: void mOR(bool _createToken);
	public: void mAND(bool _createToken);
	public: void mFS(bool _createToken);
	public: void mFSFS(bool _createToken);
	public: void mLESS(bool _createToken);
	public: void mGT(bool _createToken);
	public: void mLTE(bool _createToken);
	public: void mGTE(bool _createToken);
	public: void mEQ(bool _createToken);
	public: void mNE(bool _createToken);
	public: void mINC(bool _createToken);
	public: void mDEC(bool _createToken);
	public: void mCOLON(bool _createToken);
	public: void mOPAREN(bool _createToken);
	public: void mCPAREN(bool _createToken);
	public: void mOSB(bool _createToken);
	public: void mCSB(bool _createToken);
	public: void mAT(bool _createToken);
	public: void mQUESTION(bool _createToken);
	public: void mDOLLAR(bool _createToken);
	public: void mNAME(bool _createToken);
private:
	
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
};

#endif /*INC_XmlPLLexer_hpp_*/
