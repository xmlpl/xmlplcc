/* $ANTLR 2.7.3 (20050127-10): "XmlPL.g" -> "XmlPLParser.cpp"$ */
#include "XmlPLParser.hpp"
#include <antlr/NoViableAltException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/ASTFactory.hpp>
#line 1 "XmlPL.g"
#line 8 "XmlPLParser.cpp"
#if 0
// constructor creation turned of with 'noConstructor' option
XmlPLParser::XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,k)
{
}

XmlPLParser::XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,1)
{
}

XmlPLParser::XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,k)
{
}

XmlPLParser::XmlPLParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,1)
{
}

XmlPLParser::XmlPLParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(state,1)
{
}

// constructor creation turned of with 'noConstructor' option
#endif
Name  XmlPLParser::name(
	const bool declaration
) {
#line 469 "XmlPL.g"
	Name n;
#line 43 "XmlPLParser.cpp"
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST name_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  nt = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST nt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		nt = LT(1);
		nt_AST = astFactory->create(nt);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(nt_AST));
		match(NAME);
#line 471 "XmlPL.g"
		
		if (!Name::parseName(nt_AST->getText(), n))
		ErrorHandler::error("invalid name", nt_AST->getLocation());
		if (declaration && n.getPrefix() != "")
		ErrorHandler::error("namespace not allowed in declaration");
		
#line 62 "XmlPLParser.cpp"
		name_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_0);
	}
	returnAST = name_AST;
	return n;
}

void XmlPLParser::keyword() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST keyword_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case LITERAL___native__:
		{
			RefXmlPLAST tmp1_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp1_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp1_AST));
			match(LITERAL___native__);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_as:
		{
			RefXmlPLAST tmp2_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp2_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp2_AST));
			match(LITERAL_as);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_attribute:
		{
			RefXmlPLAST tmp3_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp3_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp3_AST));
			match(LITERAL_attribute);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_boolean:
		{
			RefXmlPLAST tmp4_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp4_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp4_AST));
			match(LITERAL_boolean);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_break:
		{
			RefXmlPLAST tmp5_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp5_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp5_AST));
			match(LITERAL_break);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_byte:
		{
			RefXmlPLAST tmp6_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp6_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp6_AST));
			match(LITERAL_byte);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_case:
		{
			RefXmlPLAST tmp7_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp7_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp7_AST));
			match(LITERAL_case);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_catch:
		{
			RefXmlPLAST tmp8_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp8_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp8_AST));
			match(LITERAL_catch);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_comment:
		{
			RefXmlPLAST tmp9_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp9_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp9_AST));
			match(LITERAL_comment);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_constant:
		{
			RefXmlPLAST tmp10_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp10_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp10_AST));
			match(LITERAL_constant);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_continue:
		{
			RefXmlPLAST tmp11_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp11_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp11_AST));
			match(LITERAL_continue);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_default:
		{
			RefXmlPLAST tmp12_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp12_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp12_AST));
			match(LITERAL_default);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_document:
		{
			RefXmlPLAST tmp13_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp13_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp13_AST));
			match(LITERAL_document);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_element:
		{
			RefXmlPLAST tmp14_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp14_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp14_AST));
			match(LITERAL_element);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_else:
		{
			RefXmlPLAST tmp15_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp15_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp15_AST));
			match(LITERAL_else);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_exception:
		{
			RefXmlPLAST tmp16_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp16_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp16_AST));
			match(LITERAL_exception);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_false:
		{
			RefXmlPLAST tmp17_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp17_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp17_AST));
			match(LITERAL_false);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_for:
		{
			RefXmlPLAST tmp18_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp18_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp18_AST));
			match(LITERAL_for);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_foreach:
		{
			RefXmlPLAST tmp19_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp19_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp19_AST));
			match(LITERAL_foreach);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_if:
		{
			RefXmlPLAST tmp20_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp20_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp20_AST));
			match(LITERAL_if);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_import:
		{
			RefXmlPLAST tmp21_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp21_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp21_AST));
			match(LITERAL_import);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_integer:
		{
			RefXmlPLAST tmp22_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp22_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp22_AST));
			match(LITERAL_integer);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_node:
		{
			RefXmlPLAST tmp23_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp23_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp23_AST));
			match(LITERAL_node);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_null:
		{
			RefXmlPLAST tmp24_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp24_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp24_AST));
			match(LITERAL_null);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_package:
		{
			RefXmlPLAST tmp25_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp25_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp25_AST));
			match(LITERAL_package);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_pi:
		{
			RefXmlPLAST tmp26_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp26_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp26_AST));
			match(LITERAL_pi);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_prefix:
		{
			RefXmlPLAST tmp27_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp27_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp27_AST));
			match(LITERAL_prefix);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_qname:
		{
			RefXmlPLAST tmp28_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp28_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp28_AST));
			match(LITERAL_qname);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_real:
		{
			RefXmlPLAST tmp29_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp29_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp29_AST));
			match(LITERAL_real);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_redirect:
		{
			RefXmlPLAST tmp30_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp30_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp30_AST));
			match(LITERAL_redirect);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_return:
		{
			RefXmlPLAST tmp31_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp31_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp31_AST));
			match(LITERAL_return);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_string:
		{
			RefXmlPLAST tmp32_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp32_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp32_AST));
			match(LITERAL_string);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_switch:
		{
			RefXmlPLAST tmp33_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp33_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp33_AST));
			match(LITERAL_switch);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_text:
		{
			RefXmlPLAST tmp34_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp34_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp34_AST));
			match(LITERAL_text);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_throw:
		{
			RefXmlPLAST tmp35_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp35_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp35_AST));
			match(LITERAL_throw);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_true:
		{
			RefXmlPLAST tmp36_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp36_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp36_AST));
			match(LITERAL_true);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_try:
		{
			RefXmlPLAST tmp37_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp37_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp37_AST));
			match(LITERAL_try);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_void:
		{
			RefXmlPLAST tmp38_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp38_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp38_AST));
			match(LITERAL_void);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_while:
		{
			RefXmlPLAST tmp39_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp39_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp39_AST));
			match(LITERAL_while);
			keyword_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_1);
	}
	returnAST = keyword_AST;
}

void XmlPLParser::program(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST program_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST pd_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_package:
		{
			packageDecl(env);
			pd_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
		case LITERAL___native__:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_exception:
		case LITERAL_import:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_string:
		case LITERAL_text:
		case LITERAL_void:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_2.member(LA(1)))) {
				declaration(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop121;
			}
			
		}
		_loop121:;
		} // ( ... )*
		match(ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE);
		program_AST = RefXmlPLAST(currentAST.root);
#line 490 "XmlPL.g"
		
		vector<EnvEntryRef> entries;
		if (Options::getInstance()->getBuildLibrary()) {
		if (pd_AST == 0)
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
		program_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(p))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(program_AST))));
		
#line 532 "XmlPLParser.cpp"
		currentAST.root = program_AST;
		if ( program_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			program_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = program_AST->getFirstChild();
		else
			currentAST.child = program_AST;
		currentAST.advanceChildToEnd();
		program_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_3);
	}
	returnAST = program_AST;
}

void XmlPLParser::packageDecl(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST packageDecl_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  p = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST p_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST nt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  v = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST v_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 523 "XmlPL.g"
	Name n;
#line 563 "XmlPLParser.cpp"
	
	try {      // for error handling
		p = LT(1);
		p_AST = astFactory->create(p);
		match(LITERAL_package);
		n=name();
		nt_AST = returnAST;
		{
		switch ( LA(1)) {
		case VERSION:
		{
			v = LT(1);
			v_AST = astFactory->create(v);
			match(VERSION);
			break;
		}
		case SEMI:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		RefXmlPLAST tmp41_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
		tmp41_AST = astFactory->create(LT(1));
		match(SEMI);
		packageDecl_AST = RefXmlPLAST(currentAST.root);
#line 526 "XmlPL.g"
		
		std::string versionStr = v_AST ? v_AST->getText() : "";
		std::string namespaceStr = n.getFullName();
		if (v_AST) namespaceStr += "-" + versionStr;
		env->setDefaultNamespace(namespaceStr);
		packageDecl_AST = new PackageDecl(namespaceStr, versionStr);
		packageDecl_AST->setLocation(p_AST->getLocation());
		
		Options::getInstance()->setVersion(versionStr);
		
#line 605 "XmlPLParser.cpp"
		currentAST.root = packageDecl_AST;
		if ( packageDecl_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			packageDecl_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = packageDecl_AST->getFirstChild();
		else
			currentAST.child = packageDecl_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_4);
	}
	returnAST = packageDecl_AST;
}

void XmlPLParser::declaration(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST declaration_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case LITERAL_import:
		{
			importDecl(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			declaration_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_exception:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_string:
		case LITERAL_text:
		case LITERAL_void:
		{
			identifierDecl(env, true);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			declaration_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL___native__:
		{
			nativeBlock();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			declaration_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_4);
	}
	returnAST = declaration_AST;
}

void XmlPLParser::importDecl(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST importDecl_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  i = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefImportDecl i_AST = RefImportDecl(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST nt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST ve_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 538 "XmlPL.g"
	Name n, as;
#line 693 "XmlPLParser.cpp"
	
	try {      // for error handling
		i = LT(1);
		i_AST = astFactory->create(i);
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(i_AST));
		match(LITERAL_import);
		n=name();
		nt_AST = returnAST;
		{
		switch ( LA(1)) {
		case GT:
		case LTE:
		case GTE:
		case VERSION:
		case LESS:
		{
			versionExpr();
			ve_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case SEMI:
		case LITERAL_as:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case LITERAL_as:
		{
			match(LITERAL_as);
			as=name();
			break;
		}
		case SEMI:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(SEMI);
#line 542 "XmlPL.g"
		
		if (as.getName() != "") {
		n.setName(as.getName());
		n.setPrefix(as.getPrefix());
		}
		
		const std::vector<EnvEntryRef> &entries =
		env->import(n, &*ve_AST, nt_AST->getLocation());
		
		if (entries.empty())
		ErrorHandler::warning("import did not find any symbols",
		nt_AST->getLocation());
		else {
		i_AST->setEntries(entries);
		n.setNamespace(entries[0]->getName().getNamespace());
		}
		
		i_AST->setName(n);
		
#line 765 "XmlPLParser.cpp"
		importDecl_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_4);
	}
	returnAST = importDecl_AST;
}

void XmlPLParser::identifierDecl(
	const EnvRef &env, bool allowFunc
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST identifierDecl_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  c = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST c_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST nt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST a_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST s_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  o = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefAssignment o_AST = RefAssignment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 598 "XmlPL.g"
	
	unsigned int t;
	Name n;
	args_t args;
	EnvRef extendedEnv = Environment::extend(env);
	
#line 797 "XmlPLParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_constant:
		{
			c = LT(1);
			c_AST = astFactory->create(c);
			match(LITERAL_constant);
			break;
		}
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_comment:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_exception:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_string:
		case LITERAL_text:
		case LITERAL_void:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		t=type(env);
		n=name(true);
		nt_AST = returnAST;
		{
		switch ( LA(1)) {
		case OPAREN:
		{
			{
			if (!(allowFunc))
				throw ANTLR_USE_NAMESPACE(antlr)SemanticException("allowFunc");
			match(OPAREN);
			{
			switch ( LA(1)) {
			case LITERAL_attribute:
			case LITERAL_boolean:
			case LITERAL_comment:
			case LITERAL_document:
			case LITERAL_element:
			case LITERAL_exception:
			case LITERAL_integer:
			case LITERAL_node:
			case LITERAL_pi:
			case LITERAL_prefix:
			case LITERAL_qname:
			case LITERAL_real:
			case LITERAL_string:
			case LITERAL_text:
			case LITERAL_void:
			{
				argumentList(extendedEnv, args);
				a_AST = returnAST;
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				break;
			}
			case CPAREN:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(CPAREN);
#line 608 "XmlPL.g"
			
			if (c_AST) c_AST->semanticError("cannot declare function to return constant!");
			
			EnvEntryRef entry;
			TargetType targetType;
			
			if (Type::isSequence(t)) targetType = t | TargetType::APPEND_FLAG;
			else if (t != Type::VOID_TYPE) targetType = t | TargetType::RETURN_FLAG;
			else targetType = t;
			
			// Declare Function
			entry = env->declareFunction(n.getName(), t, args, nt_AST->getLocation());
			
			// Create AST
			FunctionDecl *f = new FunctionDecl;
			f->setLocation(nt_AST->getLocation());
			f->setEntry(entry);
			
#line 897 "XmlPLParser.cpp"
			{
			switch ( LA(1)) {
			case OCB:
			{
				compoundStmt(extendedEnv, targetType);
				s_AST = returnAST;
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				break;
			}
			case SEMI:
			{
				match(SEMI);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			identifierDecl_AST = RefXmlPLAST(currentAST.root);
#line 626 "XmlPL.g"
			
			if (entry != 0) {
			// Declare function body
			if (s_AST) {
			entry->declareBody(nt_AST->getLocation());
			f->setForwardDecl(false);
			}
			
			identifierDecl_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(f))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(identifierDecl_AST))));
			}
			
#line 931 "XmlPLParser.cpp"
			currentAST.root = identifierDecl_AST;
			if ( identifierDecl_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
				identifierDecl_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
				  currentAST.child = identifierDecl_AST->getFirstChild();
			else
				currentAST.child = identifierDecl_AST;
			currentAST.advanceChildToEnd();
			}
			break;
		}
		case ASSIGN:
		case SEMI:
		{
			{
			{
			switch ( LA(1)) {
			case ASSIGN:
			{
				o = LT(1);
				o_AST = astFactory->create(o);
				match(ASSIGN);
				expression(env);
				e_AST = returnAST;
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				break;
			}
			case SEMI:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(SEMI);
			identifierDecl_AST = RefXmlPLAST(currentAST.root);
#line 641 "XmlPL.g"
			
			EnvEntryRef entry = env->declareVariable(n.getName(), t, c_AST,
			nt_AST->getLocation());
			
			VariableDecl *v = new VariableDecl;
			v->setLocation(nt_AST->getLocation());
			v->setEntry(entry);
			
			if (t == Type::VOID_TYPE)
			v->semanticError("variable type cannot be void");
			
			if (o_AST) {
			o_AST->validateTypes(t, e_AST->getDataType());
			e_AST->setTargetType(t);
			}
			
			if (entry != 0) identifierDecl_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(v))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(identifierDecl_AST))));
			
#line 989 "XmlPLParser.cpp"
			currentAST.root = identifierDecl_AST;
			if ( identifierDecl_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
				identifierDecl_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
				  currentAST.child = identifierDecl_AST->getFirstChild();
			else
				currentAST.child = identifierDecl_AST;
			currentAST.advanceChildToEnd();
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		identifierDecl_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_5);
	}
	returnAST = identifierDecl_AST;
}

void XmlPLParser::nativeBlock() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST nativeBlock_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  d = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST d_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefNativeBlock tmp48_AST = RefNativeBlock(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp48_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp48_AST));
		match(LITERAL___native__);
		d = LT(1);
		d_AST = astFactory->create(d);
		match(NATIVE_DATA);
		nativeBlock_AST = RefXmlPLAST(currentAST.root);
#line 864 "XmlPL.g"
		
		if (d_AST) nativeBlock_AST->setText(d_AST->getText());
		else nativeBlock_AST->setText("");
		
#line 1037 "XmlPLParser.cpp"
		nativeBlock_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_6);
	}
	returnAST = nativeBlock_AST;
}

void XmlPLParser::versionExpr() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST versionExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		versionRange();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{
		switch ( LA(1)) {
		case COMMA:
		{
			RefVersionOr tmp49_AST = RefVersionOr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
			tmp49_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp49_AST));
			match(COMMA);
			versionRange();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case SEMI:
		case LITERAL_as:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		versionExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_7);
	}
	returnAST = versionExpr_AST;
}

void XmlPLParser::versionRange() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST versionRange_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST v1t_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST v2t_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 567 "XmlPL.g"
	int op = 0; Version v1, v2, max;
#line 1097 "XmlPLParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case GT:
		case LTE:
		case GTE:
		case LESS:
		{
			{
			switch ( LA(1)) {
			case GT:
			{
				RefBinaryExpr tmp50_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
				tmp50_AST = astFactory->create(LT(1));
				match(GT);
#line 569 "XmlPL.g"
				op = GT;
#line 1116 "XmlPLParser.cpp"
				break;
			}
			case GTE:
			{
				RefBinaryExpr tmp51_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
				tmp51_AST = astFactory->create(LT(1));
				match(GTE);
#line 569 "XmlPL.g"
				op = GTE;
#line 1126 "XmlPLParser.cpp"
				break;
			}
			case LESS:
			{
				RefXmlPLAST tmp52_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp52_AST = astFactory->create(LT(1));
				match(LESS);
#line 569 "XmlPL.g"
				op = LESS;
#line 1136 "XmlPLParser.cpp"
				break;
			}
			case LTE:
			{
				RefBinaryExpr tmp53_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
				tmp53_AST = astFactory->create(LT(1));
				match(LTE);
#line 569 "XmlPL.g"
				op = LTE;
#line 1146 "XmlPLParser.cpp"
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			v1=version();
			v1t_AST = returnAST;
			break;
		}
		case VERSION:
		{
			v2=version();
			v2t_AST = returnAST;
			{
			switch ( LA(1)) {
			case MINUS:
			{
				RefXmlPLAST tmp54_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp54_AST = astFactory->create(LT(1));
				match(MINUS);
#line 570 "XmlPL.g"
				op = MINUS;
#line 1172 "XmlPLParser.cpp"
				max=version();
				break;
			}
			case SEMI:
			case COMMA:
			case LITERAL_as:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		versionRange_AST = RefXmlPLAST(currentAST.root);
#line 571 "XmlPL.g"
		
		VersionRange *vrange = new VersionRange;
		vrange->setOp(op);
		
		if (op == MINUS) {
		vrange->setVersion(v2);
		vrange->setMax(max);
		vrange->setLocation(v2t_AST->getLocation());
		
		} else if (op) {
		vrange->setVersion(v1);
		vrange->setLocation(v1t_AST->getLocation());
		
		} else {
		vrange->setVersion(v2);
		vrange->setLocation(v2t_AST->getLocation());
		}
		
		versionRange_AST = vrange;
		
#line 1218 "XmlPLParser.cpp"
		currentAST.root = versionRange_AST;
		if ( versionRange_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			versionRange_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = versionRange_AST->getFirstChild();
		else
			currentAST.child = versionRange_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_8);
	}
	returnAST = versionRange_AST;
}

Version  XmlPLParser::version() {
#line 593 "XmlPL.g"
	Version v;
#line 1238 "XmlPLParser.cpp"
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST version_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  ver = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST ver_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		ver = LT(1);
		ver_AST = astFactory->create(ver);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(ver_AST));
		match(VERSION);
#line 595 "XmlPL.g"
		v = ver_AST->getText();
#line 1252 "XmlPLParser.cpp"
		version_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_9);
	}
	returnAST = version_AST;
	return v;
}

unsigned int  XmlPLParser::type(
	const EnvRef &env
) {
#line 685 "XmlPL.g"
	unsigned int t = Type::UNKNOWN_TYPE;
#line 1269 "XmlPLParser.cpp"
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST type_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST b_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  i = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr i_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  o = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr o_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		t=typeName(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{
		if (((LA(1) == BSL || LA(1) == INC || LA(1) == OSB))&&(t != Type::VOID_TYPE)) {
			{
			switch ( LA(1)) {
			case OSB:
			{
				{
				b = LT(1);
				b_AST = astFactory->create(b);
				match(OSB);
				match(CSB);
				}
				break;
			}
			case INC:
			{
				i = LT(1);
				i_AST = astFactory->create(i);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(i_AST));
				match(INC);
				break;
			}
			case BSL:
			{
				o = LT(1);
				o_AST = astFactory->create(o);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(o_AST));
				match(BSL);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		else if ((LA(1) == BAND || LA(1) == CPAREN || LA(1) == NAME)) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
#line 686 "XmlPL.g"
		
		if (b_AST) t |= Type::SEQUENCE_FLAG;
		if (i_AST) t |= Type::ITERATOR_FLAG;
		if (o_AST) t |= Type::OSTREAM_FLAG;
		
#line 1333 "XmlPLParser.cpp"
		type_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_10);
	}
	returnAST = type_AST;
	return t;
}

void XmlPLParser::argumentList(
	const EnvRef &env, args_t &args
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST argumentList_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 663 "XmlPL.g"
	Arg a;
#line 1353 "XmlPLParser.cpp"
	
	try {      // for error handling
		a=argument(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 665 "XmlPL.g"
		args.push_back(a);
#line 1360 "XmlPLParser.cpp"
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == COMMA)) {
				match(COMMA);
				a=argument(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 666 "XmlPL.g"
				args.push_back(a);
#line 1369 "XmlPLParser.cpp"
			}
			else {
				goto _loop145;
			}
			
		}
		_loop145:;
		} // ( ... )*
		argumentList_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_11);
	}
	returnAST = argumentList_AST;
}

void XmlPLParser::compoundStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST compoundStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  o = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST o_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST b_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		o = LT(1);
		o_AST = astFactory->create(o);
		match(OCB);
		block(env->extend(env), targetType);
		b_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(CCB);
#line 743 "XmlPL.g"
		b_AST->setLocation(o_AST->getLocation());
#line 1408 "XmlPLParser.cpp"
		compoundStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_12);
	}
	returnAST = compoundStmt_AST;
}

void XmlPLParser::expression(
	const EnvRef &env, bool inFuncCall
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST expression_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		assignmentExpr(env, inFuncCall);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		expression_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_13);
	}
	returnAST = expression_AST;
}

Arg  XmlPLParser::argument(
	const EnvRef &env
) {
#line 669 "XmlPL.g"
	Arg a;
#line 1444 "XmlPLParser.cpp"
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST argument_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  r = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr r_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST nt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
#line 670 "XmlPL.g"
		unsigned int t; Name n;
#line 1455 "XmlPLParser.cpp"
		t=type(env);
		{
		switch ( LA(1)) {
		case BAND:
		{
			r = LT(1);
			r_AST = astFactory->create(r);
			match(BAND);
			break;
		}
		case NAME:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		n=name(true);
		nt_AST = returnAST;
		argument_AST = RefXmlPLAST(currentAST.root);
#line 671 "XmlPL.g"
		
		a = Arg(t, r_AST, n);
		Argument *arg = new Argument;
		arg->setLocation(nt_AST->getLocation());
		arg->setArg(a);
		arg->validate();
		
		// Declare arg
		env->declareVariable(n, t, false, nt_AST->getLocation());
		
		argument_AST = arg;
		
#line 1492 "XmlPLParser.cpp"
		currentAST.root = argument_AST;
		if ( argument_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			argument_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = argument_AST->getFirstChild();
		else
			currentAST.child = argument_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_14);
	}
	returnAST = argument_AST;
	return a;
}

unsigned int  XmlPLParser::typeName(
	const EnvRef &env
) {
#line 693 "XmlPL.g"
	unsigned int t = Type::UNKNOWN_TYPE;
#line 1515 "XmlPLParser.cpp"
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST typeName_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case LITERAL_boolean:
		case LITERAL_exception:
		case LITERAL_integer:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_string:
		case LITERAL_void:
		{
			{
			switch ( LA(1)) {
			case LITERAL_string:
			{
				RefXmlPLAST tmp58_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp58_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp58_AST));
				match(LITERAL_string);
				break;
			}
			case LITERAL_integer:
			{
				RefXmlPLAST tmp59_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp59_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp59_AST));
				match(LITERAL_integer);
				break;
			}
			case LITERAL_real:
			{
				RefXmlPLAST tmp60_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp60_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp60_AST));
				match(LITERAL_real);
				break;
			}
			case LITERAL_boolean:
			{
				RefXmlPLAST tmp61_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp61_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp61_AST));
				match(LITERAL_boolean);
				break;
			}
			case LITERAL_qname:
			{
				RefXmlPLAST tmp62_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp62_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp62_AST));
				match(LITERAL_qname);
				break;
			}
			case LITERAL_prefix:
			{
				RefXmlPLAST tmp63_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp63_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp63_AST));
				match(LITERAL_prefix);
				break;
			}
			case LITERAL_exception:
			{
				RefXmlPLAST tmp64_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp64_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp64_AST));
				match(LITERAL_exception);
				break;
			}
			case LITERAL_void:
			{
				RefXmlPLAST tmp65_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp65_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp65_AST));
				match(LITERAL_void);
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			typeName_AST = RefXmlPLAST(currentAST.root);
#line 695 "XmlPL.g"
			
			if (env != 0)
			t = env->lookupType(typeName_AST->getText(), typeName_AST->getLocation());
			
#line 1609 "XmlPLParser.cpp"
			typeName_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_attribute:
		case LITERAL_comment:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_node:
		case LITERAL_pi:
		case LITERAL_text:
		{
			t=xmlType(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			typeName_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_15);
	}
	returnAST = typeName_AST;
	return t;
}

unsigned int  XmlPLParser::xmlType(
	const EnvRef &env
) {
#line 702 "XmlPL.g"
	unsigned int t = Type::UNKNOWN_TYPE;
#line 1646 "XmlPLParser.cpp"
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlType_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case LITERAL_node:
		{
			RefXmlPLAST tmp66_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp66_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp66_AST));
			match(LITERAL_node);
			break;
		}
		case LITERAL_document:
		{
			RefXmlPLAST tmp67_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp67_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp67_AST));
			match(LITERAL_document);
			break;
		}
		case LITERAL_element:
		{
			RefXmlPLAST tmp68_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp68_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp68_AST));
			match(LITERAL_element);
			break;
		}
		case LITERAL_attribute:
		{
			RefXmlPLAST tmp69_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp69_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp69_AST));
			match(LITERAL_attribute);
			break;
		}
		case LITERAL_text:
		{
			RefXmlPLAST tmp70_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp70_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp70_AST));
			match(LITERAL_text);
			break;
		}
		case LITERAL_comment:
		{
			RefXmlPLAST tmp71_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp71_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp71_AST));
			match(LITERAL_comment);
			break;
		}
		case LITERAL_pi:
		{
			RefXmlPLAST tmp72_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp72_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp72_AST));
			match(LITERAL_pi);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		xmlType_AST = RefXmlPLAST(currentAST.root);
#line 704 "XmlPL.g"
		
		if (env != 0)
		t = env->lookupType(xmlType_AST->getText(), xmlType_AST->getLocation());
		
#line 1722 "XmlPLParser.cpp"
		xmlType_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_16);
	}
	returnAST = xmlType_AST;
	return t;
}

void XmlPLParser::statement(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST statement_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case START_XML_COMM:
		case START_PI:
		case DOT:
		case DOTDOT:
		case PLUS:
		case MINUS:
		case LESS:
		case OPAREN:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL_false:
		case LITERAL_null:
		case LITERAL_true:
		{
			expressionStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case OCB:
		{
			compoundStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_if:
		{
			ifStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_foreach:
		{
			foreachStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_for:
		{
			forStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_while:
		{
			whileStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_switch:
		{
			switchStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_break:
		{
			breakStmt(targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_continue:
		{
			continueStmt(targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_return:
		{
			returnStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_try:
		{
			tryStmt(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_throw:
		{
			throwStmt(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL_redirect:
		{
			redirectStmt(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LITERAL___native__:
		{
			nativeBlock();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case SEMI:
		{
			emptyStmt();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		statement_AST = RefXmlPLAST(currentAST.root);
#line 728 "XmlPL.g"
		statement_AST->validate();
#line 1864 "XmlPLParser.cpp"
		statement_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = statement_AST;
}

void XmlPLParser::expressionStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST expressionStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST s_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		expression(env);
		s_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{
		if (((_tokenSet_17.member(LA(1))))&&(s_AST && s_AST->isXML())) {
		}
		else if ((LA(1) == SEMI)) {
			match(SEMI);
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		expressionStmt_AST = RefXmlPLAST(currentAST.root);
#line 732 "XmlPL.g"
		
		if (s_AST) {
		ExpressionStmt *es = new ExpressionStmt(*s_AST);
		expressionStmt_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(es))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(expressionStmt_AST))));
		es->setTargetType(targetType);
		}
		
#line 1907 "XmlPLParser.cpp"
		currentAST.root = expressionStmt_AST;
		if ( expressionStmt_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			expressionStmt_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = expressionStmt_AST->getFirstChild();
		else
			currentAST.child = expressionStmt_AST;
		currentAST.advanceChildToEnd();
		expressionStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = expressionStmt_AST;
}

void XmlPLParser::ifStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST ifStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefIfStmt tmp74_AST = RefIfStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp74_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp74_AST));
		match(LITERAL_if);
		parenthesizedExpr(env);
		e_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		statement(env, targetType);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{
		if ((LA(1) == LITERAL_else)) {
			match(LITERAL_else);
			statement(env, targetType);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		else if ((_tokenSet_17.member(LA(1)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
#line 754 "XmlPL.g"
		if (e_AST) e_AST->setTargetType(Type::BOOLEAN_TYPE);
#line 1958 "XmlPLParser.cpp"
		ifStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = ifStmt_AST;
}

void XmlPLParser::foreachStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST foreachStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST s_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefForeachStmt tmp76_AST = RefForeachStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp76_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp76_AST));
		match(LITERAL_foreach);
		parenthesizedExpr(env);
		e_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 758 "XmlPL.g"
		
		EnvRef extendedEnv = Environment::extend(env);
		extendedEnv->declareVariable(".", e_AST->getDataType() & ~Type::SEQUENCE_FLAG,
		true, e_AST->getLocation());
		
#line 1992 "XmlPLParser.cpp"
		statement(extendedEnv, targetType.setFlags(TargetType::LOOP_FLAGS));
		s_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		foreachStmt_AST = RefXmlPLAST(currentAST.root);
#line 763 "XmlPL.g"
		
		if (e_AST->isFilterable()) {
		e_AST->setNextSibling(0);
		
		ExpressionStmt *es = new ExpressionStmt(*e_AST);
		foreachStmt_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(es))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(e_AST))));
		es->setTargetType(targetType);
		e_AST->filterWith(s_AST);
		e_AST->setFunctionize(false);
		}
		
#line 2009 "XmlPLParser.cpp"
		currentAST.root = foreachStmt_AST;
		if ( foreachStmt_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			foreachStmt_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = foreachStmt_AST->getFirstChild();
		else
			currentAST.child = foreachStmt_AST;
		currentAST.advanceChildToEnd();
		foreachStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = foreachStmt_AST;
}

void XmlPLParser::forStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST forStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e1_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e2_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e3_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefForStmt tmp77_AST = RefForStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp77_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp77_AST));
		match(LITERAL_for);
		match(OPAREN);
		optionalExpr(env);
		e1_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(SEMI);
		optionalExpr(env);
		e2_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(SEMI);
		optionalExpr(env);
		e3_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(CPAREN);
		statement(env, targetType.setFlags(TargetType::LOOP_FLAGS));
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 780 "XmlPL.g"
		
		if (e1_AST) e1_AST->setTargetType(TargetType::VOID_TYPE);
		if (e2_AST) e2_AST->setTargetType(TargetType::BOOLEAN_TYPE);
		if (e3_AST) e3_AST->setTargetType(TargetType::VOID_TYPE);
		
#line 2063 "XmlPLParser.cpp"
		forStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = forStmt_AST;
}

void XmlPLParser::whileStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST whileStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefWhileStmt tmp82_AST = RefWhileStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp82_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp82_AST));
		match(LITERAL_while);
		parenthesizedExpr(env);
		e_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		statement(env, targetType.setFlags(TargetType::LOOP_FLAGS));
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 795 "XmlPL.g"
		if (e_AST) e_AST->setTargetType(TargetType::BOOLEAN_TYPE);
#line 2094 "XmlPLParser.cpp"
		whileStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = whileStmt_AST;
}

void XmlPLParser::switchStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST switchStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  s = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefSwitchStmt s_AST = RefSwitchStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		s = LT(1);
		s_AST = astFactory->create(s);
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(s_AST));
		match(LITERAL_switch);
		parenthesizedExpr(env);
		e_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(OCB);
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == LITERAL_case)) {
				caseStmt(env, targetType.setFlags(TargetType::BREAK_FLAG));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop173;
			}
			
		}
		_loop173:;
		} // ( ... )*
		{
		switch ( LA(1)) {
		case LITERAL_default:
		{
			defaultCase(env, targetType.setFlags(TargetType::BREAK_FLAG));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case CCB:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(CCB);
		switchStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = switchStmt_AST;
}

void XmlPLParser::breakStmt(
	TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST breakStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBreakStmt b_AST = RefBreakStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		b = LT(1);
		b_AST = astFactory->create(b);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b_AST));
		match(LITERAL_break);
		match(SEMI);
#line 821 "XmlPL.g"
		if (!targetType.hasBreak()) b_AST->semanticError("break not allowed here");
#line 2183 "XmlPLParser.cpp"
		breakStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = breakStmt_AST;
}

void XmlPLParser::continueStmt(
	TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST continueStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  c = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefContinueStmt c_AST = RefContinueStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		c = LT(1);
		c_AST = astFactory->create(c);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(c_AST));
		match(LITERAL_continue);
		match(SEMI);
#line 825 "XmlPL.g"
		
		if (!targetType.hasContinue())
		c_AST->semanticError("continue not allowed here");
		
#line 2214 "XmlPLParser.cpp"
		continueStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = continueStmt_AST;
}

void XmlPLParser::returnStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST returnStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  r = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefReturnStmt r_AST = RefReturnStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		r = LT(1);
		r_AST = astFactory->create(r);
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(r_AST));
		match(LITERAL_return);
		{
		switch ( LA(1)) {
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case START_XML_COMM:
		case START_PI:
		case DOT:
		case DOTDOT:
		case PLUS:
		case MINUS:
		case LESS:
		case OPAREN:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL_false:
		case LITERAL_null:
		case LITERAL_true:
		{
			expression(env);
			e_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case SEMI:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(SEMI);
#line 832 "XmlPL.g"
		
		if (!targetType.hasReturn() && e_AST)
		r_AST->semanticError("return statement with value not allowed here");
		if (e_AST) e_AST->setTargetType(targetType);
		
#line 2287 "XmlPLParser.cpp"
		returnStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = returnStmt_AST;
}

void XmlPLParser::tryStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST tryStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  c = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST c_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefTryStmt tmp88_AST = RefTryStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp88_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp88_AST));
		match(LITERAL_try);
		compoundStmt(env, targetType);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		c = LT(1);
		c_AST = astFactory->create(c);
		match(LITERAL_catch);
#line 840 "XmlPL.g"
		
		EnvRef extendedEnv = Environment::extend(env);
		extendedEnv->declareVariable("error", Type::STRING_TYPE, true,
		c_AST->getLocation());
		extendedEnv->declareVariable("line", Type::INTEGER_TYPE, true,
		c_AST->getLocation());
		extendedEnv->declareVariable("column", Type::INTEGER_TYPE, true,
		c_AST->getLocation());
		
#line 2327 "XmlPLParser.cpp"
		compoundStmt(extendedEnv, targetType);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		tryStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = tryStmt_AST;
}

void XmlPLParser::throwStmt(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST throwStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefThrowStmt tmp89_AST = RefThrowStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp89_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp89_AST));
		match(LITERAL_throw);
		expression(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(SEMI);
		throwStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = throwStmt_AST;
}

void XmlPLParser::redirectStmt(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST redirectStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  r = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefRedirectStmt r_AST = RefRedirectStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 854 "XmlPL.g"
	unsigned int t;
#line 2376 "XmlPLParser.cpp"
	
	try {      // for error handling
		r = LT(1);
		r_AST = astFactory->create(r);
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(r_AST));
		match(LITERAL_redirect);
		match(OPAREN);
		expression(env);
		e_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(CPAREN);
#line 856 "XmlPL.g"
		
		t = (e_AST->getDataType() & ~Type::OSTREAM_FLAG) |
		Type::SEQUENCE_FLAG | TargetType::APPEND_FLAG;
		
#line 2393 "XmlPLParser.cpp"
		statement(env, t);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 860 "XmlPL.g"
		r_AST->setDataType(t);
#line 2398 "XmlPLParser.cpp"
		redirectStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = redirectStmt_AST;
}

void XmlPLParser::emptyStmt() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST emptyStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  s = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST s_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		s = LT(1);
		s_AST = astFactory->create(s);
		match(SEMI);
		emptyStmt_AST = RefXmlPLAST(currentAST.root);
#line 870 "XmlPL.g"
		
		emptyStmt_AST = new Empty(*s_AST);
		ErrorHandler::warning(
		"Use of the empty statement is not necessary or recommended",
		s_AST->getLocation());
		
#line 2428 "XmlPLParser.cpp"
		currentAST.root = emptyStmt_AST;
		if ( emptyStmt_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			emptyStmt_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = emptyStmt_AST->getFirstChild();
		else
			currentAST.child = emptyStmt_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_17);
	}
	returnAST = emptyStmt_AST;
}

void XmlPLParser::block(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST block_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			if (((_tokenSet_18.member(LA(1))))&&(LA(2) != OPAREN)) {
				identifierDecl(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else if ((_tokenSet_19.member(LA(1)))) {
				statement(env, targetType);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop163;
			}
			
		}
		_loop163:;
		} // ( ... )*
		block_AST = RefXmlPLAST(currentAST.root);
#line 748 "XmlPL.g"
		block_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(BLOCK)))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(block_AST))));
#line 2473 "XmlPLParser.cpp"
		currentAST.root = block_AST;
		if ( block_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			block_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = block_AST->getFirstChild();
		else
			currentAST.child = block_AST;
		currentAST.advanceChildToEnd();
		block_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_20);
	}
	returnAST = block_AST;
}

void XmlPLParser::parenthesizedExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST parenthesizedExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		match(OPAREN);
		expression(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(CPAREN);
		parenthesizedExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_21);
	}
	returnAST = parenthesizedExpr_AST;
}

void XmlPLParser::optionalExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST optionalExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case START_XML_COMM:
		case START_PI:
		case DOT:
		case DOTDOT:
		case PLUS:
		case MINUS:
		case LESS:
		case OPAREN:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL_false:
		case LITERAL_null:
		case LITERAL_true:
		{
			expression(env);
			e_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case SEMI:
		case CPAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		optionalExpr_AST = RefXmlPLAST(currentAST.root);
#line 789 "XmlPL.g"
		if (!e_AST) optionalExpr_AST = astFactory->create(EMPTY);
#line 2566 "XmlPLParser.cpp"
		currentAST.root = optionalExpr_AST;
		if ( optionalExpr_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			optionalExpr_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = optionalExpr_AST->getFirstChild();
		else
			currentAST.child = optionalExpr_AST;
		currentAST.advanceChildToEnd();
		optionalExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_22);
	}
	returnAST = optionalExpr_AST;
}

void XmlPLParser::caseStmt(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST caseStmt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefCaseStmt tmp95_AST = RefCaseStmt(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp95_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp95_AST));
		match(LITERAL_case);
		{
		caseConstant();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		match(COLON);
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_19.member(LA(1)))) {
				statement(env, targetType);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop178;
			}
			
		}
		_loop178:;
		} // ( ... )*
		caseStmt_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_23);
	}
	returnAST = caseStmt_AST;
}

void XmlPLParser::defaultCase(
	const EnvRef &env, TargetType targetType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST defaultCase_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefDefaultCase tmp97_AST = RefDefaultCase(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp97_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp97_AST));
		match(LITERAL_default);
		match(COLON);
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_19.member(LA(1)))) {
				statement(env, targetType);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop182;
			}
			
		}
		_loop182:;
		} // ( ... )*
		defaultCase_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_24);
	}
	returnAST = defaultCase_AST;
}

void XmlPLParser::caseConstant() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST caseConstant_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  i = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant i_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  s = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant s_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		switch ( LA(1)) {
		case INTEGER:
		{
			i = LT(1);
			i_AST = astFactory->create(i);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(i_AST));
			match(INTEGER);
#line 809 "XmlPL.g"
			i_AST->setDataType(Type::INTEGER_TYPE);
#line 2679 "XmlPLParser.cpp"
			caseConstant_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case STRING:
		{
			s = LT(1);
			s_AST = astFactory->create(s);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(s_AST));
			match(STRING);
#line 810 "XmlPL.g"
			s_AST->setDataType(Type::STRING_TYPE);
#line 2691 "XmlPLParser.cpp"
			caseConstant_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case REGEX:
		case STAR:
		case NAME:
		case LITERAL___native__:
		case LITERAL_as:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_byte:
		case LITERAL_case:
		case LITERAL_catch:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_import:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_package:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			xmlNameTest();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			caseConstant_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_25);
	}
	returnAST = caseConstant_AST;
}

void XmlPLParser::xmlNameTest() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlNameTest_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case NAME:
		case LITERAL___native__:
		case LITERAL_as:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_byte:
		case LITERAL_case:
		case LITERAL_catch:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_import:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_package:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			xmlName();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			xmlNameTest_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case REGEX:
		{
			RefXmlPLAST tmp99_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp99_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp99_AST));
			match(REGEX);
			xmlNameTest_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case STAR:
		{
			RefXmlPLAST tmp100_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp100_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp100_AST));
			match(STAR);
			xmlNameTest_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_26);
	}
	returnAST = xmlNameTest_AST;
}

void XmlPLParser::assignmentExpr(
	const EnvRef &env, bool inFuncCall
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST assignmentExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST l_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST a_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST r_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		sequenceExpr(env, inFuncCall);
		l_AST = returnAST;
		{
		switch ( LA(1)) {
		case ASSIGN:
		case ADD_ASSIGN:
		case SUB_ASSIGN:
		case MUL_ASSIGN:
		case DIV_ASSIGN:
		case MOD_ASSIGN:
		case COMMA_ASSIGN:
		{
			assignOp();
			a_AST = returnAST;
			assignmentExpr(env, inFuncCall);
			r_AST = returnAST;
			break;
		}
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case END_ELEM:
		case START_XML_COMM:
		case START_PI:
		case SEMI:
		case OCB:
		case CCB:
		case DOT:
		case DOTDOT:
		case COMMA:
		case PLUS:
		case MINUS:
		case LESS:
		case OPAREN:
		case CPAREN:
		case CSB:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL___native__:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_case:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		assignmentExpr_AST = RefXmlPLAST(currentAST.root);
#line 885 "XmlPL.g"
		
		if (a_AST) {
		assignmentExpr_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(a_AST))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(l_AST))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(r_AST))));
		a_AST->validate();
		} else assignmentExpr_AST = l_AST;
		
#line 2948 "XmlPLParser.cpp"
		currentAST.root = assignmentExpr_AST;
		if ( assignmentExpr_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			assignmentExpr_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = assignmentExpr_AST->getFirstChild();
		else
			currentAST.child = assignmentExpr_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_13);
	}
	returnAST = assignmentExpr_AST;
}

void XmlPLParser::sequenceExpr(
	const EnvRef &env, bool inFuncCall
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST sequenceExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		xmlExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if (((LA(1) == COMMA))&&(!inFuncCall)) {
				match(COMMA);
				xmlExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop198;
			}
			
		}
		_loop198:;
		} // ( ... )*
		sequenceExpr_AST = RefXmlPLAST(currentAST.root);
#line 902 "XmlPL.g"
		
		if (sequenceExpr_AST && sequenceExpr_AST->getNext()) {
		SequenceExpr *se = new SequenceExpr();
		se->setDataType(sequenceExpr_AST->getDataType() | Type::SEQUENCE_FLAG);
		
		sequenceExpr_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(se))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(sequenceExpr_AST))));
		}
		
#line 2999 "XmlPLParser.cpp"
		currentAST.root = sequenceExpr_AST;
		if ( sequenceExpr_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			sequenceExpr_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = sequenceExpr_AST->getFirstChild();
		else
			currentAST.child = sequenceExpr_AST;
		currentAST.advanceChildToEnd();
		sequenceExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_27);
	}
	returnAST = sequenceExpr_AST;
}

void XmlPLParser::assignOp() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST assignOp_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case ASSIGN:
		{
			RefAssignment tmp102_AST = RefAssignment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
			tmp102_AST = astFactory->create(LT(1),30);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp102_AST));
			match(ASSIGN);
			assignOp_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case ADD_ASSIGN:
		{
			RefAssignment tmp103_AST = RefAssignment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
			tmp103_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp103_AST));
			match(ADD_ASSIGN);
			assignOp_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case SUB_ASSIGN:
		{
			RefAssignment tmp104_AST = RefAssignment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
			tmp104_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp104_AST));
			match(SUB_ASSIGN);
			assignOp_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case MUL_ASSIGN:
		{
			RefAssignment tmp105_AST = RefAssignment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
			tmp105_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp105_AST));
			match(MUL_ASSIGN);
			assignOp_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case DIV_ASSIGN:
		{
			RefAssignment tmp106_AST = RefAssignment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
			tmp106_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp106_AST));
			match(DIV_ASSIGN);
			assignOp_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case MOD_ASSIGN:
		{
			RefAssignment tmp107_AST = RefAssignment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
			tmp107_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp107_AST));
			match(MOD_ASSIGN);
			assignOp_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case COMMA_ASSIGN:
		{
			RefAssignment tmp108_AST = RefAssignment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
			tmp108_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp108_AST));
			match(COMMA_ASSIGN);
			assignOp_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_28);
	}
	returnAST = assignOp_AST;
}

void XmlPLParser::xmlExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case LESS:
		{
			xmlElement(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			xmlExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case START_XML_COMM:
		{
			xmlComment(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			xmlExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case START_PI:
		{
			xmlPI(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			xmlExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case DOT:
		case DOTDOT:
		case PLUS:
		case MINUS:
		case OPAREN:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL_false:
		case LITERAL_null:
		case LITERAL_true:
		{
			orExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			xmlExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_27);
	}
	returnAST = xmlExpr_AST;
}

void XmlPLParser::xmlElement(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlElement_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  x = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXMLElement x_AST = RefXMLElement(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST n1_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  s = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST s_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST b_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  end = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST end_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST n2_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		x = LT(1);
		x_AST = astFactory->create(x);
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(x_AST));
		match(LESS);
		qname(env);
		n1_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_29.member(LA(1)))) {
				attribute(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop208;
			}
			
		}
		_loop208:;
		} // ( ... )*
		{
		switch ( LA(1)) {
		case END_ELEM_SHORT:
		{
			s = LT(1);
			s_AST = astFactory->create(s);
			match(END_ELEM_SHORT);
			break;
		}
		case GT:
		{
			{
			match(GT);
			block(env->extend(env), TargetType::APPEND_FLAG |
      Type::NODE_SEQ_TYPE);
			b_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			end = LT(1);
			end_AST = astFactory->create(end);
			match(END_ELEM);
			{
			switch ( LA(1)) {
			case OPAREN:
			case NAME:
			case LITERAL___native__:
			case LITERAL_as:
			case LITERAL_attribute:
			case LITERAL_boolean:
			case LITERAL_break:
			case LITERAL_byte:
			case LITERAL_case:
			case LITERAL_catch:
			case LITERAL_comment:
			case LITERAL_constant:
			case LITERAL_continue:
			case LITERAL_default:
			case LITERAL_document:
			case LITERAL_element:
			case LITERAL_else:
			case LITERAL_exception:
			case LITERAL_false:
			case LITERAL_for:
			case LITERAL_foreach:
			case LITERAL_if:
			case LITERAL_import:
			case LITERAL_integer:
			case LITERAL_node:
			case LITERAL_null:
			case LITERAL_package:
			case LITERAL_pi:
			case LITERAL_prefix:
			case LITERAL_qname:
			case LITERAL_real:
			case LITERAL_redirect:
			case LITERAL_return:
			case LITERAL_string:
			case LITERAL_switch:
			case LITERAL_text:
			case LITERAL_throw:
			case LITERAL_true:
			case LITERAL_try:
			case LITERAL_void:
			case LITERAL_while:
			{
				qname(env);
				n2_AST = returnAST;
				break;
			}
			case GT:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			match(GT);
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 966 "XmlPL.g"
		
		// TODO check that ending qnames match
		x_AST->setEnvDepth(env->getDepth());
		x_AST->validate();
		
#line 3301 "XmlPLParser.cpp"
		xmlElement_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_27);
	}
	returnAST = xmlElement_AST;
}

void XmlPLParser::xmlComment(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlComment_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  t = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant t_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefXMLComment tmp111_AST = RefXMLComment(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp111_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp111_AST));
		match(START_XML_COMM);
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case XML_COMMENT_CHARS:
			{
				t = LT(1);
				t_AST = astFactory->create(t);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(t_AST));
				match(XML_COMMENT_CHARS);
#line 983 "XmlPL.g"
				t_AST->setDataType(Type::STRING_TYPE);
#line 3338 "XmlPLParser.cpp"
				break;
			}
			case OPAREN:
			{
				parenthesizedExpr(env);
				e_AST = returnAST;
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 984 "XmlPL.g"
				e_AST->setTargetType(Type::STRING_TYPE);
#line 3348 "XmlPLParser.cpp"
				break;
			}
			default:
			{
				goto _loop217;
			}
			}
		}
		_loop217:;
		} // ( ... )*
		match(END_XML_COMM);
		xmlComment_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_27);
	}
	returnAST = xmlComment_AST;
}

void XmlPLParser::xmlPI(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlPI_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  pi = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXMLPI pi_AST = RefXMLPI(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST n_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  t = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant t_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		pi = LT(1);
		pi_AST = astFactory->create(pi);
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(pi_AST));
		match(START_PI);
		xmlNameOrExpr(env);
		n_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 989 "XmlPL.g"
		n_AST->setTargetType(Type::STRING_TYPE);
#line 3393 "XmlPLParser.cpp"
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case XML_PI_CHARS:
			{
				t = LT(1);
				t_AST = astFactory->create(t);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(t_AST));
				match(XML_PI_CHARS);
#line 990 "XmlPL.g"
				t_AST->setDataType(Type::STRING_TYPE);
#line 3405 "XmlPLParser.cpp"
				break;
			}
			case OPAREN:
			{
				parenthesizedExpr(env);
				e_AST = returnAST;
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 991 "XmlPL.g"
				e_AST->setTargetType(Type::STRING_TYPE);
#line 3415 "XmlPLParser.cpp"
				break;
			}
			default:
			{
				goto _loop220;
			}
			}
		}
		_loop220:;
		} // ( ... )*
		match(END_PI);
		xmlPI_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_27);
	}
	returnAST = xmlPI_AST;
}

void XmlPLParser::orExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST orExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		andExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == OR)) {
				b = LT(1);
				b_AST = astFactory->create(b);
				astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b_AST));
				match(OR);
				andExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 995 "XmlPL.g"
				b_AST->validate();
#line 3460 "XmlPLParser.cpp"
			}
			else {
				goto _loop223;
			}
			
		}
		_loop223:;
		} // ( ... )*
		orExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_27);
	}
	returnAST = orExpr_AST;
}

void XmlPLParser::xmlName() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlName_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  n = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST n_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST k_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case NAME:
		{
			n = LT(1);
			n_AST = astFactory->create(n);
			match(NAME);
			break;
		}
		case LITERAL___native__:
		case LITERAL_as:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_byte:
		case LITERAL_case:
		case LITERAL_catch:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_import:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_package:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			keyword();
			k_AST = returnAST;
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		xmlName_AST = RefXmlPLAST(currentAST.root);
#line 920 "XmlPL.g"
		
		Constant *c = new Constant(n_AST ? *n_AST : *k_AST);
		c->setDataType(Type::STRING_TYPE);
		xmlName_AST = c;
		
#line 3554 "XmlPLParser.cpp"
		currentAST.root = xmlName_AST;
		if ( xmlName_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			xmlName_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = xmlName_AST->getFirstChild();
		else
			currentAST.child = xmlName_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_1);
	}
	returnAST = xmlName_AST;
}

void XmlPLParser::xmlNameOrExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlNameOrExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case NAME:
		case LITERAL___native__:
		case LITERAL_as:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_byte:
		case LITERAL_case:
		case LITERAL_catch:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_import:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_package:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			xmlName();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			xmlNameOrExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case OPAREN:
		{
			parenthesizedExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			xmlNameOrExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_30);
	}
	returnAST = xmlNameOrExpr_AST;
}

void XmlPLParser::qname(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST qname_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST n0_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST n1_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST n2_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case NAME:
		case LITERAL___native__:
		case LITERAL_as:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_byte:
		case LITERAL_case:
		case LITERAL_catch:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_import:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_package:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			xmlName();
			n0_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case OPAREN:
		{
			parenthesizedExpr(env);
			n1_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		switch ( LA(1)) {
		case COLON:
		{
			match(COLON);
			xmlNameOrExpr(env);
			n2_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case ASSIGN:
		case GT:
		case END_ELEM_SHORT:
		case OPAREN:
		case NAME:
		case LITERAL___native__:
		case LITERAL_as:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_byte:
		case LITERAL_case:
		case LITERAL_catch:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_import:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_package:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		qname_AST = RefXmlPLAST(currentAST.root);
#line 930 "XmlPL.g"
		
		XMLQName *q = new XMLQName;
		
		if (n2_AST) {
		if (n0_AST) {
		EnvEntryRef pre =
		env->lookupVariable(n0_AST->getText(), n0_AST->getLocation());
		if (pre != 0) {
		if (pre->getType() != Type::PREFIX_TYPE)
		n0_AST->semanticError(n0_AST->getText() + " is not a prefix");
		
		VariableRef *vref = new VariableRef;
		vref->setLocation(n0_AST->getLocation());
		vref->setEnvEntry(pre);
		
		vref->setNextSibling(&*n2_AST);
		qname_AST = vref;
		
		} else n0_AST->semanticError("must declare prefix before use");
		
		} else n1_AST->setTargetType(Type::PREFIX_TYPE);
		
		n2_AST->setTargetType(Type::STRING_TYPE);
		
		} else if (n0_AST) n0_AST->setTargetType(Type::QNAME_TYPE);
		else n1_AST->setTargetType(Type::QNAME_TYPE);
		
		qname_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(q))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(qname_AST))));
		
#line 3813 "XmlPLParser.cpp"
		currentAST.root = qname_AST;
		if ( qname_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			qname_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = qname_AST->getFirstChild();
		else
			currentAST.child = qname_AST;
		currentAST.advanceChildToEnd();
		qname_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_31);
	}
	returnAST = qname_AST;
}

void XmlPLParser::attribute(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST attribute_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		qname(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		RefXMLAttr tmp115_AST = RefXMLAttr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
		tmp115_AST = astFactory->create(LT(1),162);
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp115_AST));
		match(ASSIGN);
		stringOrExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		attribute_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_32);
	}
	returnAST = attribute_AST;
}

void XmlPLParser::stringOrExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST stringOrExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  s = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant s_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case STRING:
		{
			s = LT(1);
			s_AST = astFactory->create(s,80);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(s_AST));
			match(STRING);
#line 974 "XmlPL.g"
			s_AST->setDataType(Type::STRING_TYPE);
#line 3877 "XmlPLParser.cpp"
			stringOrExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case OPAREN:
		{
			{
			parenthesizedExpr(env);
			e_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 975 "XmlPL.g"
			e_AST->setTargetType(Type::STRING_TYPE);
#line 3889 "XmlPLParser.cpp"
			}
			stringOrExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_32);
	}
	returnAST = stringOrExpr_AST;
}

void XmlPLParser::andExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST andExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		borExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == AND)) {
				b = LT(1);
				b_AST = astFactory->create(b);
				astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b_AST));
				match(AND);
				borExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 997 "XmlPL.g"
				b_AST->validate();
#line 3931 "XmlPLParser.cpp"
			}
			else {
				goto _loop226;
			}
			
		}
		_loop226:;
		} // ( ... )*
		andExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_33);
	}
	returnAST = andExpr_AST;
}

void XmlPLParser::borExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST borExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		bxorExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == BOR)) {
				b = LT(1);
				b_AST = astFactory->create(b);
				astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b_AST));
				match(BOR);
				bxorExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 999 "XmlPL.g"
				b_AST->validate();
#line 3973 "XmlPLParser.cpp"
			}
			else {
				goto _loop229;
			}
			
		}
		_loop229:;
		} // ( ... )*
		borExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_34);
	}
	returnAST = borExpr_AST;
}

void XmlPLParser::bxorExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST bxorExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		bandExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == BXOR)) {
				b = LT(1);
				b_AST = astFactory->create(b);
				astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b_AST));
				match(BXOR);
				bandExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1001 "XmlPL.g"
				b_AST->validate();
#line 4015 "XmlPLParser.cpp"
			}
			else {
				goto _loop232;
			}
			
		}
		_loop232:;
		} // ( ... )*
		bxorExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_35);
	}
	returnAST = bxorExpr_AST;
}

void XmlPLParser::bandExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST bandExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		equalExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == BAND)) {
				b = LT(1);
				b_AST = astFactory->create(b,42);
				astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b_AST));
				match(BAND);
				equalExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1003 "XmlPL.g"
				b_AST->validate();
#line 4057 "XmlPLParser.cpp"
			}
			else {
				goto _loop235;
			}
			
		}
		_loop235:;
		} // ( ... )*
		bandExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_36);
	}
	returnAST = bandExpr_AST;
}

void XmlPLParser::equalExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST equalExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b1_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  b2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b2_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		relExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == NE || LA(1) == EQ)) {
				{
				switch ( LA(1)) {
				case NE:
				{
					b1 = LT(1);
					b1_AST = astFactory->create(b1);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b1_AST));
					match(NE);
					break;
				}
				case EQ:
				{
					b2 = LT(1);
					b2_AST = astFactory->create(b2);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b2_AST));
					match(EQ);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				relExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1006 "XmlPL.g"
				
				if (b1_AST) {b1_AST->validate(); b1_AST = 0;}
				else if (b2_AST) {b2_AST->validate(); b2_AST = 0;}
				
#line 4124 "XmlPLParser.cpp"
			}
			else {
				goto _loop239;
			}
			
		}
		_loop239:;
		} // ( ... )*
		equalExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_37);
	}
	returnAST = equalExpr_AST;
}

void XmlPLParser::relExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST relExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b1_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  b2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b2_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  b3 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b3_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  b4 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b4_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		shiftExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((_tokenSet_38.member(LA(1)))) {
				{
				switch ( LA(1)) {
				case LESS:
				{
					b1 = LT(1);
					b1_AST = astFactory->create(b1,45);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b1_AST));
					match(LESS);
					break;
				}
				case GT:
				{
					b2 = LT(1);
					b2_AST = astFactory->create(b2,45);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b2_AST));
					match(GT);
					break;
				}
				case LTE:
				{
					b3 = LT(1);
					b3_AST = astFactory->create(b3,45);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b3_AST));
					match(LTE);
					break;
				}
				case GTE:
				{
					b4 = LT(1);
					b4_AST = astFactory->create(b4,45);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b4_AST));
					match(GTE);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				shiftExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1015 "XmlPL.g"
				
				if (b1_AST) {b1_AST->validate(); b1_AST = 0;}
				else if (b2_AST) {b2_AST->validate(); b2_AST = 0;}
				else if (b3_AST) {b3_AST->validate(); b3_AST = 0;}
				else if (b4_AST) {b4_AST->validate(); b4_AST = 0;}
				
#line 4213 "XmlPLParser.cpp"
			}
			else {
				goto _loop243;
			}
			
		}
		_loop243:;
		} // ( ... )*
		relExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_39);
	}
	returnAST = relExpr_AST;
}

void XmlPLParser::shiftExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST shiftExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b1_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  b2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b2_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		addExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == BSL || LA(1) == BSR)) {
				{
				switch ( LA(1)) {
				case BSL:
				{
					b1 = LT(1);
					b1_AST = astFactory->create(b1,45);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b1_AST));
					match(BSL);
					break;
				}
				case BSR:
				{
					b2 = LT(1);
					b2_AST = astFactory->create(b2);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b2_AST));
					match(BSR);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				addExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1024 "XmlPL.g"
				
				if (b1_AST) {b1_AST->validate(); b1_AST = 0;}
				else if (b2_AST) {b2_AST->validate(); b2_AST = 0;}
				
#line 4280 "XmlPLParser.cpp"
			}
			else {
				goto _loop247;
			}
			
		}
		_loop247:;
		} // ( ... )*
		shiftExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_40);
	}
	returnAST = shiftExpr_AST;
}

void XmlPLParser::addExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST addExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b1_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  b2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b2_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		mulExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == PLUS || LA(1) == MINUS)) {
				{
				switch ( LA(1)) {
				case PLUS:
				{
					b1 = LT(1);
					b1_AST = astFactory->create(b1);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b1_AST));
					match(PLUS);
					break;
				}
				case MINUS:
				{
					b2 = LT(1);
					b2_AST = astFactory->create(b2);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b2_AST));
					match(MINUS);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				mulExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1032 "XmlPL.g"
				
				if (b1_AST) {b1_AST->validate(); b1_AST = 0;}
				else if (b2_AST) {b2_AST->validate(); b2_AST = 0;}
				
#line 4347 "XmlPLParser.cpp"
			}
			else {
				goto _loop251;
			}
			
		}
		_loop251:;
		} // ( ... )*
		addExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_41);
	}
	returnAST = addExpr_AST;
}

void XmlPLParser::mulExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST mulExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b1 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b1_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  b2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b2_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  b3 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b3_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		unaryExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == MOD || LA(1) == STAR || LA(1) == FS)) {
				{
				switch ( LA(1)) {
				case STAR:
				{
					b1 = LT(1);
					b1_AST = astFactory->create(b1);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b1_AST));
					match(STAR);
					break;
				}
				case FS:
				{
					b2 = LT(1);
					b2_AST = astFactory->create(b2);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b2_AST));
					match(FS);
					break;
				}
				case MOD:
				{
					b3 = LT(1);
					b3_AST = astFactory->create(b3);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b3_AST));
					match(MOD);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				unaryExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1040 "XmlPL.g"
				
				if (b1_AST) {b1_AST->validate(); b1_AST = 0;}
				else if (b2_AST) {b2_AST->validate(); b2_AST = 0;}
				else if (b3_AST) {b3_AST->validate(); b3_AST = 0;}
				
#line 4425 "XmlPLParser.cpp"
			}
			else {
				goto _loop255;
			}
			
		}
		_loop255:;
		} // ( ... )*
		mulExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_41);
	}
	returnAST = mulExpr_AST;
}

void XmlPLParser::unaryExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST unaryExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  n = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr n_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  m = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr m_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  p = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr p_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  c = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr c_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		switch ( LA(1)) {
		case NOT:
		{
			n = LT(1);
			n_AST = astFactory->create(n);
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(n_AST));
			match(NOT);
			unaryExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1048 "XmlPL.g"
			n_AST->validate();
#line 4471 "XmlPLParser.cpp"
			unaryExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case MINUS:
		{
			m = LT(1);
			m_AST = astFactory->create(m,53);
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(m_AST));
			match(MINUS);
			unaryExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1049 "XmlPL.g"
			m_AST->validate();
#line 4485 "XmlPLParser.cpp"
			unaryExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case PLUS:
		{
			p = LT(1);
			p_AST = astFactory->create(p,53);
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(p_AST));
			match(PLUS);
			unaryExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1050 "XmlPL.g"
			p_AST->validate();
#line 4499 "XmlPLParser.cpp"
			unaryExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case BCOMP:
		{
			c = LT(1);
			c_AST = astFactory->create(c);
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(c_AST));
			match(BCOMP);
			unaryExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1051 "XmlPL.g"
			c_AST->validate();
#line 4513 "XmlPLParser.cpp"
			unaryExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
			if (((LA(1) == OPAREN))&&(isTypeName(env, LT(2)) && LA(3) != OPAREN)) {
				castExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				unaryExpr_AST = RefXmlPLAST(currentAST.root);
			}
			else if ((_tokenSet_42.member(LA(1)))) {
				iterExpr(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				unaryExpr_AST = RefXmlPLAST(currentAST.root);
			}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_43);
	}
	returnAST = unaryExpr_AST;
}

void XmlPLParser::castExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST castExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  c = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefCast c_AST = RefCast(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
#line 1056 "XmlPL.g"
	unsigned int t;
#line 4551 "XmlPLParser.cpp"
	
	try {      // for error handling
		c = LT(1);
		c_AST = astFactory->create(c);
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(c_AST));
		match(OPAREN);
		t=type(env);
		match(CPAREN);
		unaryExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1058 "XmlPL.g"
		
		c_AST->setDataType(t);
		c_AST->validate();
		
#line 4567 "XmlPLParser.cpp"
		castExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_43);
	}
	returnAST = castExpr_AST;
}

void XmlPLParser::iterExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST iterExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  i = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr i_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  d = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr d_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  i2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr i2_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  d2 = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefUnaryExpr d2_AST = RefUnaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		switch ( LA(1)) {
		case INC:
		{
			i = LT(1);
			i_AST = astFactory->create(i,56);
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(i_AST));
			match(INC);
			unaryExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1065 "XmlPL.g"
			i_AST->validate();
#line 4605 "XmlPLParser.cpp"
			iterExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case DEC:
		{
			d = LT(1);
			d_AST = astFactory->create(d);
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(d_AST));
			match(DEC);
			unaryExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1066 "XmlPL.g"
			d_AST->validate();
#line 4619 "XmlPLParser.cpp"
			iterExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case INTEGER:
		case REAL:
		case STRING:
		case DOT:
		case DOTDOT:
		case OPAREN:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL_false:
		case LITERAL_null:
		case LITERAL_true:
		{
			pathExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == INC || LA(1) == DEC)) {
					{
					switch ( LA(1)) {
					case INC:
					{
						i2 = LT(1);
						i2_AST = astFactory->create(i2,55);
						astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(i2_AST));
						match(INC);
#line 1068 "XmlPL.g"
						i2_AST->setPost(true); i2_AST->validate();
#line 4652 "XmlPLParser.cpp"
						break;
					}
					case DEC:
					{
						d2 = LT(1);
						d2_AST = astFactory->create(d2,55);
						astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(d2_AST));
						match(DEC);
#line 1069 "XmlPL.g"
						d2_AST->setPost(true); d2_AST->validate();
#line 4663 "XmlPLParser.cpp"
						break;
					}
					default:
					{
						throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
					}
					}
					}
				}
				else {
					goto _loop261;
				}
				
			}
			_loop261:;
			} // ( ... )*
			iterExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_43);
	}
	returnAST = iterExpr_AST;
}

void XmlPLParser::pathExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST pathExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST s_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		releaseExpr(env);
		e_AST = returnAST;
#line 1075 "XmlPL.g"
		
		// Jump out if this is really a divide
		if (e_AST == 0 || !Type::get(e_AST->getDataType()).isPathType()) return;
		
#line 4714 "XmlPLParser.cpp"
		{
		if ((LA(1) == FS)) {
			steps(env);
			s_AST = returnAST;
		}
		else if ((_tokenSet_43.member(LA(1)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		pathExpr_AST = RefXmlPLAST(currentAST.root);
#line 1079 "XmlPL.g"
		
		if (e_AST->isFilterable()) {
		if (s_AST) e_AST->filterWith(s_AST);
		pathExpr_AST = e_AST;
		
		} else if (s_AST) {
		pathExpr_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(PATH)))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(e_AST))));
		pathExpr_AST->setEnvDepth(env->getDepth());
		pathExpr_AST->validate();
		pathExpr_AST->filterWith(s_AST);
		
		} else pathExpr_AST = e_AST;
		
#line 4742 "XmlPLParser.cpp"
		currentAST.root = pathExpr_AST;
		if ( pathExpr_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			pathExpr_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = pathExpr_AST->getFirstChild();
		else
			currentAST.child = pathExpr_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_43);
	}
	returnAST = pathExpr_AST;
}

void XmlPLParser::releaseExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST releaseExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  d = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST d_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case DOLLAR:
		{
			d = LT(1);
			d_AST = astFactory->create(d);
			match(DOLLAR);
			break;
		}
		case INTEGER:
		case REAL:
		case STRING:
		case DOT:
		case DOTDOT:
		case OPAREN:
		case AT:
		case QUESTION:
		case NAME:
		case LITERAL_false:
		case LITERAL_null:
		case LITERAL_true:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		filterExpr(env);
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		releaseExpr_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_43);
	}
	returnAST = releaseExpr_AST;
}

void XmlPLParser::steps(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST steps_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  f = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST f_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST p_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST c_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 1095 "XmlPL.g"
	RefStep s;
#line 4823 "XmlPLParser.cpp"
	
	try {      // for error handling
		f = LT(1);
		f_AST = astFactory->create(f);
		match(FS);
		s=abrevStep(env);
		{
		switch ( LA(1)) {
		case OSB:
		{
			predicates(env, s->getDataType());
			p_AST = returnAST;
			break;
		}
		case ASSIGN:
		case ADD_ASSIGN:
		case SUB_ASSIGN:
		case MUL_ASSIGN:
		case DIV_ASSIGN:
		case MOD_ASSIGN:
		case COMMA_ASSIGN:
		case OR:
		case AND:
		case BOR:
		case BXOR:
		case BAND:
		case NE:
		case EQ:
		case GT:
		case LTE:
		case GTE:
		case BSL:
		case BSR:
		case MOD:
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case END_ELEM:
		case START_XML_COMM:
		case START_PI:
		case SEMI:
		case OCB:
		case CCB:
		case DOT:
		case DOTDOT:
		case COMMA:
		case PLUS:
		case MINUS:
		case STAR:
		case FS:
		case LESS:
		case OPAREN:
		case CPAREN:
		case CSB:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL___native__:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_case:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		{
		if ((LA(1) == FS)) {
			steps(env);
			c_AST = returnAST;
		}
		else if ((_tokenSet_43.member(LA(1)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		steps_AST = RefXmlPLAST(currentAST.root);
#line 1097 "XmlPL.g"
		
		if (p_AST) {
		s->filterWith(p_AST);
		if (c_AST) p_AST->filterWith(c_AST);
		
		} else if (c_AST) s->filterWith(c_AST);
		
		steps_AST = s;
		
#line 4952 "XmlPLParser.cpp"
		currentAST.root = steps_AST;
		if ( steps_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			steps_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = steps_AST->getFirstChild();
		else
			currentAST.child = steps_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_43);
	}
	returnAST = steps_AST;
}

RefStep  XmlPLParser::abrevStep(
	const EnvRef &env
) {
#line 1108 "XmlPL.g"
	RefStep s;
#line 4974 "XmlPLParser.cpp"
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST abrevStep_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST n_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case REGEX:
		case STAR:
		case OPAREN:
		case NAME:
		case LITERAL___native__:
		case LITERAL_as:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_byte:
		case LITERAL_case:
		case LITERAL_catch:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_import:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_package:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			nodeTest(env);
			n_AST = returnAST;
#line 1109 "XmlPL.g"
			
			// Implicit child step
			s = new Step;
			s->setLocation(n_AST->getLocation());
			s->setAxis(Step::CHILD_AXIS);
			s->addChild(&*n_AST);
			
			if (n_AST->getType() != TYPE_TEST)
			addImplicitTypeTest(s, &*n_AST, Type::ELEMENT_TYPE);
			s->validate();
			
#line 5040 "XmlPLParser.cpp"
			break;
		}
		case DOTDOT:
		case AT:
		case QUESTION:
		{
			s=step(env);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = abrevStep_AST;
	return s;
}

void XmlPLParser::predicates(
	const EnvRef &env, unsigned int contextType
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST predicates_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  o = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST o_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 1145 "XmlPL.g"
	
	contextType &= ~Type::SEQUENCE_FLAG;
	unsigned int refCount = 0;
	RefXmlPLAST intPred;
	EnvRef extendedEnv = Environment::extend(env);
	EnvEntryRef entry;
	EnvEntryRef posEntry;
	
	RefPredicates preds;
	
#line 5085 "XmlPLParser.cpp"
	
	try {      // for error handling
		{
		o = LT(1);
		o_AST = astFactory->create(o);
		match(OSB);
#line 1155 "XmlPL.g"
		
		if (entry == 0)
		entry =
		extendedEnv->declareVariable(".", contextType, true, o_AST->getLocation());
		if (posEntry == 0)
		posEntry =
		extendedEnv->declareVariable("position", Type::INTEGER_TYPE, true,
		o_AST->getLocation());
		
		
#line 5103 "XmlPLParser.cpp"
		expression(extendedEnv);
		e_AST = returnAST;
#line 1164 "XmlPL.g"
		
		if (intPred != 0) e_AST->semanticError("cannot filter non-sequence type");
		
		if (e_AST->getDataType() == Type::INTEGER_TYPE) {
		if (refCount < entry->getEnvRefCount())
		e_AST->semanticError("cannot reference '.' from integer predicate");
		
		intPred = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(INT_PREDICATE)))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(e_AST))));
		intPred->setLocation(o_AST->getLocation());
		
		} else {
		if (preds == 0) {
		preds = new Predicates;
		preds->setLocation(o_AST->getLocation());
		}
		preds->addChild(&*e_AST);
		}
		
		refCount = entry->getEnvRefCount();
		
#line 5127 "XmlPLParser.cpp"
		match(CSB);
		}
		predicates_AST = RefXmlPLAST(currentAST.root);
#line 1184 "XmlPL.g"
		
		if (preds) {
		if (intPred != 0) preds->filterWith(intPred);
		
		if (posEntry->getEnvRefCount()) preds->setRequiresPosition(true);
		predicates_AST = preds;
		
		} else predicates_AST = intPred;
		
#line 5141 "XmlPLParser.cpp"
		currentAST.root = predicates_AST;
		if ( predicates_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			predicates_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = predicates_AST->getFirstChild();
		else
			currentAST.child = predicates_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_43);
	}
	returnAST = predicates_AST;
}

void XmlPLParser::nodeTest(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST nodeTest_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  b = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefBinaryExpr b_AST = RefBinaryExpr(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		if (((_tokenSet_45.member(LA(1))))&&(LA(2) != OPAREN)) {
			xmlQNameTest(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			nodeTest_AST = RefXmlPLAST(currentAST.root);
		}
		else if ((_tokenSet_46.member(LA(1)))) {
			typeTest(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			nodeTest_AST = RefXmlPLAST(currentAST.root);
		}
		else if ((LA(1) == OPAREN)) {
			match(OPAREN);
			xmlQNameTest(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == BOR)) {
					b = LT(1);
					b_AST = astFactory->create(b,51);
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(b_AST));
					match(BOR);
#line 1199 "XmlPL.g"
					b_AST->setType(OR);
#line 5191 "XmlPLParser.cpp"
					xmlQNameTest(env);
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				}
				else {
					goto _loop274;
				}
				
			}
			_loop274:;
			} // ( ... )*
			match(CPAREN);
			nodeTest_AST = RefXmlPLAST(currentAST.root);
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = nodeTest_AST;
}

RefStep  XmlPLParser::step(
	const EnvRef &env
) {
#line 1123 "XmlPL.g"
	RefStep s;
#line 5223 "XmlPLParser.cpp"
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST step_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  a = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefStep a_AST = RefStep(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST n_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  p = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefStep p_AST = RefStep(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  q = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefStep q_AST = RefStep(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	RefXmlPLAST n2_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case AT:
		{
			a = LT(1);
			a_AST = astFactory->create(a);
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(a_AST));
			match(AT);
			nodeTest(env);
			n_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
#line 1124 "XmlPL.g"
			
			a_AST->setAxis(Step::ATTRIBUTE_AXIS);
			if (n_AST->getType() == TYPE_TEST)
			n_AST->semanticError("type test not allowed on attribute axis");
			s = a_AST;
			
#line 5255 "XmlPLParser.cpp"
			break;
		}
		case DOTDOT:
		{
			p = LT(1);
			p_AST = astFactory->create(p);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(p_AST));
			match(DOTDOT);
#line 1130 "XmlPL.g"
			
			p_AST->setAxis(Step::PARENT_AXIS);
			p_AST->addChild(new Empty); // Place holder
			s = p_AST;
			
#line 5270 "XmlPLParser.cpp"
			break;
		}
		case QUESTION:
		{
			q = LT(1);
			q_AST = astFactory->create(q);
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(q_AST));
			match(QUESTION);
			nodeTest(env);
			n2_AST = returnAST;
#line 1135 "XmlPL.g"
			
			q_AST->setAxis(Step::CHILD_AXIS);
			if (n2_AST->getType() == TYPE_TEST)
			n2_AST->semanticError("type test not allowed with ?");
			addImplicitTypeTest(q_AST, n2_AST, Type::PI_TYPE);
			s = q_AST;
			
#line 5289 "XmlPLParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		step_AST = RefXmlPLAST(currentAST.root);
#line 1142 "XmlPL.g"
		step_AST->validate();
#line 5301 "XmlPLParser.cpp"
		step_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = step_AST;
	return s;
}

void XmlPLParser::xmlQNameTest(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST xmlQNameTest_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST n1_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST n2_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		xmlNameTest();
		n1_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{
		switch ( LA(1)) {
		case COLON:
		{
			match(COLON);
			xmlNameTest();
			n2_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case ASSIGN:
		case ADD_ASSIGN:
		case SUB_ASSIGN:
		case MUL_ASSIGN:
		case DIV_ASSIGN:
		case MOD_ASSIGN:
		case COMMA_ASSIGN:
		case OR:
		case AND:
		case BOR:
		case BXOR:
		case BAND:
		case NE:
		case EQ:
		case GT:
		case LTE:
		case GTE:
		case BSL:
		case BSR:
		case MOD:
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case END_ELEM:
		case START_XML_COMM:
		case START_PI:
		case SEMI:
		case OCB:
		case CCB:
		case DOT:
		case DOTDOT:
		case COMMA:
		case PLUS:
		case MINUS:
		case STAR:
		case FS:
		case LESS:
		case OPAREN:
		case CPAREN:
		case OSB:
		case CSB:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL___native__:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_case:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		xmlQNameTest_AST = RefXmlPLAST(currentAST.root);
#line 1214 "XmlPL.g"
		
		NameTest *nt = new NameTest;
		nt->setLocation(n1_AST->getLocation());
		
		if (n2_AST) {
		if (n1_AST->getType() == CONSTANT) {
		EnvEntryRef pre = env->lookupVariable(n1_AST->getText(), n1_AST->getLocation());
		if (pre != 0) {
		if (pre->getType() != Type::PREFIX_TYPE)
		n1_AST->semanticError(n1_AST->getText() + " is not a prefix");
		
		VariableRef *vref = new VariableRef;
		vref->setLocation(n1_AST->getLocation());
		vref->setEnvEntry(pre);
		
		nt->addChild(vref);
		
		} else n1_AST->semanticError("must declare prefix before use");
		
		} else nt->setPrefix(n1_AST->getText());
		
		nt->setName(n2_AST->getText());
		
		} else nt->setName(n1_AST->getText());
		
		xmlQNameTest_AST = nt;
		
#line 5457 "XmlPLParser.cpp"
		currentAST.root = xmlQNameTest_AST;
		if ( xmlQNameTest_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			xmlQNameTest_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = xmlQNameTest_AST->getFirstChild();
		else
			currentAST.child = xmlQNameTest_AST;
		currentAST.advanceChildToEnd();
		xmlQNameTest_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = xmlQNameTest_AST;
}

void XmlPLParser::typeTest(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST typeTest_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST t_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
#line 1203 "XmlPL.g"
		unsigned int type;
#line 5486 "XmlPLParser.cpp"
		type=xmlType(env);
		t_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(OPAREN);
		match(CPAREN);
		typeTest_AST = RefXmlPLAST(currentAST.root);
#line 1204 "XmlPL.g"
		
		TypeTest *nt = new TypeTest;
		nt->setTypeTest(type);
		nt->setLocation(t_AST->getLocation());
		
		typeTest_AST = nt;
		
#line 5501 "XmlPLParser.cpp"
		currentAST.root = typeTest_AST;
		if ( typeTest_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			typeTest_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = typeTest_AST->getFirstChild();
		else
			currentAST.child = typeTest_AST;
		currentAST.advanceChildToEnd();
		typeTest_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = typeTest_AST;
}

void XmlPLParser::filterExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST filterExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST e_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST p_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 1249 "XmlPL.g"
	EnvEntryRef entry;
#line 5529 "XmlPLParser.cpp"
	
	try {      // for error handling
		primaryExpr(env);
		e_AST = returnAST;
		{
		switch ( LA(1)) {
		case OSB:
		{
			predicates(env, e_AST->getDataType());
			p_AST = returnAST;
			break;
		}
		case ASSIGN:
		case ADD_ASSIGN:
		case SUB_ASSIGN:
		case MUL_ASSIGN:
		case DIV_ASSIGN:
		case MOD_ASSIGN:
		case COMMA_ASSIGN:
		case OR:
		case AND:
		case BOR:
		case BXOR:
		case BAND:
		case NE:
		case EQ:
		case GT:
		case LTE:
		case GTE:
		case BSL:
		case BSR:
		case MOD:
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case END_ELEM:
		case START_XML_COMM:
		case START_PI:
		case SEMI:
		case OCB:
		case CCB:
		case DOT:
		case DOTDOT:
		case COMMA:
		case PLUS:
		case MINUS:
		case STAR:
		case FS:
		case LESS:
		case OPAREN:
		case CPAREN:
		case CSB:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL___native__:
		case LITERAL_attribute:
		case LITERAL_boolean:
		case LITERAL_break:
		case LITERAL_case:
		case LITERAL_comment:
		case LITERAL_constant:
		case LITERAL_continue:
		case LITERAL_default:
		case LITERAL_document:
		case LITERAL_element:
		case LITERAL_else:
		case LITERAL_exception:
		case LITERAL_false:
		case LITERAL_for:
		case LITERAL_foreach:
		case LITERAL_if:
		case LITERAL_integer:
		case LITERAL_node:
		case LITERAL_null:
		case LITERAL_pi:
		case LITERAL_prefix:
		case LITERAL_qname:
		case LITERAL_real:
		case LITERAL_redirect:
		case LITERAL_return:
		case LITERAL_string:
		case LITERAL_switch:
		case LITERAL_text:
		case LITERAL_throw:
		case LITERAL_true:
		case LITERAL_try:
		case LITERAL_void:
		case LITERAL_while:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		filterExpr_AST = RefXmlPLAST(currentAST.root);
#line 1251 "XmlPL.g"
		
		if (e_AST && p_AST) {
		if (e_AST->isFilterable()) e_AST->filterWith(p_AST);
		
		else {
		if (p_AST->getType() == INT_PREDICATE) {
		// Make array expression
		RefXmlPLAST intPred = ((IntPredicate *)&*p_AST)->getChild();
		
		filterExpr_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(ARRAY_EXPR)))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(e_AST))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(intPred))));
		filterExpr_AST->validate();
		
		} else {
		filterExpr_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(FILTER_EXPR)))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(e_AST))));
		filterExpr_AST->setEnvDepth(env->getDepth());
		filterExpr_AST->validate();
		filterExpr_AST->filterWith(p_AST);
		}
		}
		} else filterExpr_AST = e_AST;
		
#line 5656 "XmlPLParser.cpp"
		currentAST.root = filterExpr_AST;
		if ( filterExpr_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			filterExpr_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = filterExpr_AST->getFirstChild();
		else
			currentAST.child = filterExpr_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_43);
	}
	returnAST = filterExpr_AST;
}

void XmlPLParser::primaryExpr(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST primaryExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case INTEGER:
		case REAL:
		case STRING:
		case LITERAL_false:
		case LITERAL_null:
		case LITERAL_true:
		{
			constantExpr();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			primaryExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case OPAREN:
		{
			parenthesizedExpr(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			primaryExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case DOTDOT:
		case AT:
		case QUESTION:
		{
			contextStep(env);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			primaryExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
			if (((LA(1) == NAME))&&(LA(2) == OPAREN)) {
				functionCall(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				primaryExpr_AST = RefXmlPLAST(currentAST.root);
			}
			else if ((LA(1) == DOT || LA(1) == NAME)) {
				varRef(env);
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				primaryExpr_AST = RefXmlPLAST(currentAST.root);
			}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = primaryExpr_AST;
}

void XmlPLParser::constantExpr() {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST constantExpr_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  i = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant i_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  s = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant s_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  t = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant t_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  f = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant f_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  n = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant n_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	ANTLR_USE_NAMESPACE(antlr)RefToken  r = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefConstant r_AST = RefConstant(RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST));
	
	try {      // for error handling
		switch ( LA(1)) {
		case INTEGER:
		{
			i = LT(1);
			i_AST = astFactory->create(i,80);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(i_AST));
			match(INTEGER);
#line 1312 "XmlPL.g"
			i_AST->setDataType(Type::INTEGER_TYPE);
#line 5761 "XmlPLParser.cpp"
			constantExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case STRING:
		{
			s = LT(1);
			s_AST = astFactory->create(s,80);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(s_AST));
			match(STRING);
#line 1313 "XmlPL.g"
			s_AST->setDataType(Type::STRING_TYPE);
#line 5773 "XmlPLParser.cpp"
			constantExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_true:
		{
			t = LT(1);
			t_AST = astFactory->create(t);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(t_AST));
			match(LITERAL_true);
#line 1314 "XmlPL.g"
			t_AST->setDataType(Type::BOOLEAN_TYPE);
#line 5785 "XmlPLParser.cpp"
			constantExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_false:
		{
			f = LT(1);
			f_AST = astFactory->create(f);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(f_AST));
			match(LITERAL_false);
#line 1315 "XmlPL.g"
			f_AST->setDataType(Type::BOOLEAN_TYPE);
#line 5797 "XmlPLParser.cpp"
			constantExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case LITERAL_null:
		{
			n = LT(1);
			n_AST = astFactory->create(n);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(n_AST));
			match(LITERAL_null);
#line 1316 "XmlPL.g"
			n_AST->setDataType(Type::NULL_TYPE);
#line 5809 "XmlPLParser.cpp"
			constantExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		case REAL:
		{
			r = LT(1);
			r_AST = astFactory->create(r);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(r_AST));
			match(REAL);
#line 1317 "XmlPL.g"
			r_AST->setDataType(Type::REAL_TYPE);
#line 5821 "XmlPLParser.cpp"
			constantExpr_AST = RefXmlPLAST(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = constantExpr_AST;
}

void XmlPLParser::functionCall(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST functionCall_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST nt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 1320 "XmlPL.g"
	Name n;
#line 5848 "XmlPLParser.cpp"
	
	try {      // for error handling
		n=name();
		nt_AST = returnAST;
		match(OPAREN);
		{
		switch ( LA(1)) {
		case NOT:
		case INC:
		case DEC:
		case BCOMP:
		case INTEGER:
		case REAL:
		case STRING:
		case START_XML_COMM:
		case START_PI:
		case DOT:
		case DOTDOT:
		case PLUS:
		case MINUS:
		case LESS:
		case OPAREN:
		case AT:
		case QUESTION:
		case DOLLAR:
		case NAME:
		case LITERAL_false:
		case LITERAL_null:
		case LITERAL_true:
		{
			expression(env, true);
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == COMMA)) {
					match(COMMA);
					expression(env, true);
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				}
				else {
					goto _loop292;
				}
				
			}
			_loop292:;
			} // ( ... )*
			break;
		}
		case CPAREN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(CPAREN);
		functionCall_AST = RefXmlPLAST(currentAST.root);
#line 1322 "XmlPL.g"
		
		args_t args;
		for (XmlPLAST *expr = &*functionCall_AST; expr; expr = expr->getNext())
		args.push_back(Arg(expr->getDataType(), !expr->isConstant()));
		
		FunctionCall *f = new FunctionCall;
		f->setLocation(nt_AST->getLocation());
		
		EnvEntryRef func = env->lookupFunction(n, args, nt_AST->getLocation());
		f->setEnvEntry(func);
		
		functionCall_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(f))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(functionCall_AST))));
		functionCall_AST->validate();
		
#line 5924 "XmlPLParser.cpp"
		currentAST.root = functionCall_AST;
		if ( functionCall_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			functionCall_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = functionCall_AST->getFirstChild();
		else
			currentAST.child = functionCall_AST;
		currentAST.advanceChildToEnd();
		functionCall_AST = RefXmlPLAST(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = functionCall_AST;
}

void XmlPLParser::varRef(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST varRef_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefXmlPLAST nt_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)RefToken  d = ANTLR_USE_NAMESPACE(antlr)nullToken;
	RefXmlPLAST d_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
#line 1299 "XmlPL.g"
		Name n;
#line 5955 "XmlPLParser.cpp"
		{
		switch ( LA(1)) {
		case NAME:
		{
			n=name();
			nt_AST = returnAST;
			break;
		}
		case DOT:
		{
			d = LT(1);
			d_AST = astFactory->create(d);
			match(DOT);
#line 1300 "XmlPL.g"
			n = ".";
#line 5971 "XmlPLParser.cpp"
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		varRef_AST = RefXmlPLAST(currentAST.root);
#line 1300 "XmlPL.g"
		
		VariableRef *vref = new VariableRef;
		vref->setLocation(nt_AST ? nt_AST->getLocation() : d_AST->getLocation());
		vref->setEnvEntry(env->lookupVariable(n, vref->getLocation()));
		
		varRef_AST = vref;
		
#line 5989 "XmlPLParser.cpp"
		currentAST.root = varRef_AST;
		if ( varRef_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			varRef_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = varRef_AST->getFirstChild();
		else
			currentAST.child = varRef_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = varRef_AST;
}

void XmlPLParser::contextStep(
	const EnvRef &env
) {
	returnAST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefXmlPLAST contextStep_AST = RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 1282 "XmlPL.g"
	RefStep s;
#line 6014 "XmlPLParser.cpp"
	
	try {      // for error handling
		s=step(env);
		contextStep_AST = RefXmlPLAST(currentAST.root);
#line 1284 "XmlPL.g"
		
		VariableRef *vref = new VariableRef;
		vref->setLocation(s->getLocation());
		
		EnvEntryRef var = env->lookupVariable(".", vref->getLocation());
		vref->setEnvEntry(var);
		
		contextStep_AST = RefXmlPLAST(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(PATH)))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(vref))));
		contextStep_AST->setEnvDepth(env->getDepth());
		contextStep_AST->validate();
		contextStep_AST->filterWith(&*s);
		
#line 6032 "XmlPLParser.cpp"
		currentAST.root = contextStep_AST;
		if ( contextStep_AST!=RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			contextStep_AST->getFirstChild() != RefXmlPLAST(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = contextStep_AST->getFirstChild();
		else
			currentAST.child = contextStep_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		consume();
		consumeUntil(_tokenSet_44);
	}
	returnAST = contextStep_AST;
}

void XmlPLParser::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory )
{
	factory.registerFactory(4, "Program", Program::factory);
	factory.registerFactory(13, "ExpressionStmt", ExpressionStmt::factory);
	factory.registerFactory(20, "Empty", Empty::factory);
	factory.registerFactory(28, "NativeBlock", NativeBlock::factory);
	factory.registerFactory(29, "BlockStmt", BlockStmt::factory);
	factory.registerFactory(30, "Assignment", Assignment::factory);
	factory.registerFactory(31, "Assignment", Assignment::factory);
	factory.registerFactory(32, "Assignment", Assignment::factory);
	factory.registerFactory(33, "Assignment", Assignment::factory);
	factory.registerFactory(34, "Assignment", Assignment::factory);
	factory.registerFactory(35, "Assignment", Assignment::factory);
	factory.registerFactory(36, "Assignment", Assignment::factory);
	factory.registerFactory(37, "SequenceExpr", SequenceExpr::factory);
	factory.registerFactory(39, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(40, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(41, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(42, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(43, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(44, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(45, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(46, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(47, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(48, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(49, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(50, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(51, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(53, "UnaryExpr", UnaryExpr::factory);
	factory.registerFactory(54, "UnaryExpr", UnaryExpr::factory);
	factory.registerFactory(55, "UnaryExpr", UnaryExpr::factory);
	factory.registerFactory(56, "UnaryExpr", UnaryExpr::factory);
	factory.registerFactory(58, "PathExpr", PathExpr::factory);
	factory.registerFactory(59, "Predicates", Predicates::factory);
	factory.registerFactory(60, "IntPredicate", IntPredicate::factory);
	factory.registerFactory(64, "FilterExpr", FilterExpr::factory);
	factory.registerFactory(65, "ArrayExpr", ArrayExpr::factory);
	factory.registerFactory(67, "VariableRef", VariableRef::factory);
	factory.registerFactory(69, "Constant", Constant::factory);
	factory.registerFactory(70, "Constant", Constant::factory);
	factory.registerFactory(72, "Constant", Constant::factory);
	factory.registerFactory(79, "Constant", Constant::factory);
	factory.registerFactory(80, "Constant", Constant::factory);
	factory.registerFactory(98, "XMLComment", XMLComment::factory);
	factory.registerFactory(100, "XMLPI", XMLPI::factory);
	factory.registerFactory(106, "Step", Step::factory);
	factory.registerFactory(107, "VersionOr", VersionOr::factory);
	factory.registerFactory(108, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(109, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(110, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(111, "BinaryExpr", BinaryExpr::factory);
	factory.registerFactory(113, "XMLElement", XMLElement::factory);
	factory.registerFactory(115, "Cast", Cast::factory);
	factory.registerFactory(119, "Step", Step::factory);
	factory.registerFactory(120, "Step", Step::factory);
	factory.registerFactory(123, "NativeBlock", NativeBlock::factory);
	factory.registerFactory(127, "BreakStmt", BreakStmt::factory);
	factory.registerFactory(129, "CaseStmt", CaseStmt::factory);
	factory.registerFactory(133, "ContinueStmt", ContinueStmt::factory);
	factory.registerFactory(134, "DefaultCase", DefaultCase::factory);
	factory.registerFactory(139, "Constant", Constant::factory);
	factory.registerFactory(140, "ForStmt", ForStmt::factory);
	factory.registerFactory(141, "ForeachStmt", ForeachStmt::factory);
	factory.registerFactory(142, "IfStmt", IfStmt::factory);
	factory.registerFactory(143, "ImportDecl", ImportDecl::factory);
	factory.registerFactory(146, "Constant", Constant::factory);
	factory.registerFactory(152, "RedirectStmt", RedirectStmt::factory);
	factory.registerFactory(153, "ReturnStmt", ReturnStmt::factory);
	factory.registerFactory(155, "SwitchStmt", SwitchStmt::factory);
	factory.registerFactory(157, "ThrowStmt", ThrowStmt::factory);
	factory.registerFactory(158, "Constant", Constant::factory);
	factory.registerFactory(159, "TryStmt", TryStmt::factory);
	factory.registerFactory(161, "WhileStmt", WhileStmt::factory);
	factory.registerFactory(162, "XMLAttr", XMLAttr::factory);
	factory.setMaxNodeType(162);
}
const char* XmlPLParser::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"PROGRAM",
	"PACKAGE_DECL",
	"VERSION_RANGE",
	"VERSION_OR",
	"TYPE",
	"ARGUMENT",
	"VAR_DECL",
	"FUNC_DECL",
	"IMPORT_DECL",
	"EXPR_STMT",
	"BREAK",
	"CONTINUE",
	"RETURN",
	"IF",
	"FOREACH",
	"FOR",
	"EMPTY",
	"WHILE",
	"SWITCH",
	"CASE",
	"DEFAULT",
	"TRY",
	"THROW",
	"REDIRECT",
	"NATIVE",
	"BLOCK",
	"ASSIGN",
	"ADD_ASSIGN",
	"SUB_ASSIGN",
	"MUL_ASSIGN",
	"DIV_ASSIGN",
	"MOD_ASSIGN",
	"COMMA_ASSIGN",
	"SEQUENCE_EXPR",
	"BIN_EXPR",
	"OR",
	"AND",
	"BOR",
	"BXOR",
	"BAND",
	"NE",
	"EQ",
	"GT",
	"LTE",
	"GTE",
	"BSL",
	"BSR",
	"MOD",
	"UNARY_EXPR",
	"NOT",
	"INC",
	"DEC",
	"BCOMP",
	"ISA_EXPR",
	"PATH",
	"PREDICATES",
	"INT_PREDICATE",
	"STEP",
	"NAME_TEST",
	"TYPE_TEST",
	"FILTER_EXPR",
	"ARRAY_EXPR",
	"FCALL",
	"VAR_REF",
	"CONSTANT",
	"INTEGER",
	"REAL",
	"VERSION",
	"STRING",
	"REGEX",
	"XML_QNAME",
	"XML_ELEM",
	"XML_ATTR",
	"XML_COM",
	"XML_PI",
	"XML_COMMENT_CHARS",
	"XML_PI_CHARS",
	"CAST",
	"NATIVE_DATA",
	"LETTER",
	"DIGIT",
	"HEX",
	"STR_ESC",
	"REG_ESC",
	"UNICODE",
	"HEX_WORD",
	"HEX_BYTE",
	"HEX_CODE",
	"OCT_CODE",
	"S",
	"COMMENT",
	"SINGLE_COMMENT",
	"END_ELEM_SHORT",
	"END_ELEM",
	"START_XML_COMM",
	"END_XML_COMM",
	"START_PI",
	"END_PI",
	"SEMI",
	"OCB",
	"CCB",
	"DOT",
	"DOTDOT",
	"COMMA",
	"PLUS",
	"MINUS",
	"STAR",
	"FS",
	"FSFS",
	"LESS",
	"COLON",
	"OPAREN",
	"CPAREN",
	"OSB",
	"CSB",
	"AT",
	"QUESTION",
	"DOLLAR",
	"NAME",
	"\"__native__\"",
	"\"as\"",
	"\"attribute\"",
	"\"boolean\"",
	"\"break\"",
	"\"byte\"",
	"\"case\"",
	"\"catch\"",
	"\"comment\"",
	"\"constant\"",
	"\"continue\"",
	"\"default\"",
	"\"document\"",
	"\"element\"",
	"\"else\"",
	"\"exception\"",
	"\"false\"",
	"\"for\"",
	"\"foreach\"",
	"\"if\"",
	"\"import\"",
	"\"integer\"",
	"\"node\"",
	"\"null\"",
	"\"package\"",
	"\"pi\"",
	"\"prefix\"",
	"\"qname\"",
	"\"real\"",
	"\"redirect\"",
	"\"return\"",
	"\"string\"",
	"\"switch\"",
	"\"text\"",
	"\"throw\"",
	"\"true\"",
	"\"try\"",
	"\"void\"",
	"\"while\"",
	0
};

const unsigned long XmlPLParser::_tokenSet_0_data_[] = { 3221225472UL, 32505759UL, 480UL, 4294639574UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ GT LTE GTE BSL BSR MOD NOT INC DEC BCOMP 
// INTEGER REAL VERSION STRING END_ELEM START_XML_COMM START_PI SEMI OCB 
// CCB DOT DOTDOT COMMA PLUS MINUS STAR FS LESS OPAREN CPAREN OSB CSB AT 
// QUESTION DOLLAR NAME "__native__" "as" "attribute" "boolean" "break" 
// "case" "comment" "constant" "continue" "default" "document" "element" 
// "else" "exception" "false" "for" "foreach" "if" "integer" "node" "null" 
// "pi" "prefix" "qname" "real" "redirect" "return" "string" "switch" "text" 
// "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_0(_tokenSet_0_data_,12);
const unsigned long XmlPLParser::_tokenSet_1_data_[] = { 3221225472UL, 32505759UL, 65888UL, 4294901751UL, 4294967295UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ GT LTE GTE BSL BSR MOD NOT INC DEC BCOMP 
// INTEGER REAL STRING XML_PI_CHARS END_ELEM_SHORT END_ELEM START_XML_COMM 
// START_PI END_PI SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS STAR FS LESS 
// COLON OPAREN CPAREN OSB CSB AT QUESTION DOLLAR NAME "__native__" "as" 
// "attribute" "boolean" "break" "byte" "case" "catch" "comment" "constant" 
// "continue" "default" "document" "element" "else" "exception" "false" 
// "for" "foreach" "if" "import" "integer" "node" "null" "package" "pi" 
// "prefix" "qname" "real" "redirect" "return" "string" "switch" "text" 
// "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_1(_tokenSet_1_data_,12);
const unsigned long XmlPLParser::_tokenSet_2_data_[] = { 0UL, 0UL, 0UL, 1744830464UL, 351503768UL, 1UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// "__native__" "attribute" "boolean" "comment" "constant" "document" "element" 
// "exception" "import" "integer" "node" "pi" "prefix" "qname" "real" "string" 
// "text" "void" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_2(_tokenSet_2_data_,12);
const unsigned long XmlPLParser::_tokenSet_3_data_[] = { 2UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_3(_tokenSet_3_data_,6);
const unsigned long XmlPLParser::_tokenSet_4_data_[] = { 2UL, 0UL, 0UL, 1744830464UL, 351503768UL, 1UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF "__native__" "attribute" "boolean" "comment" "constant" "document" 
// "element" "exception" "import" "integer" "node" "pi" "prefix" "qname" 
// "real" "string" "text" "void" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_4(_tokenSet_4_data_,12);
const unsigned long XmlPLParser::_tokenSet_5_data_[] = { 2UL, 31457280UL, 352UL, 4018812886UL, 4294442424UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM START_PI 
// SEMI OCB CCB DOT DOTDOT PLUS MINUS LESS OPAREN AT QUESTION DOLLAR NAME 
// "__native__" "attribute" "boolean" "break" "comment" "constant" "continue" 
// "document" "element" "exception" "false" "for" "foreach" "if" "import" 
// "integer" "node" "null" "pi" "prefix" "qname" "real" "redirect" "return" 
// "string" "switch" "text" "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_5(_tokenSet_5_data_,12);
const unsigned long XmlPLParser::_tokenSet_6_data_[] = { 2UL, 31457280UL, 352UL, 4018812886UL, 4294443002UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM START_PI 
// SEMI OCB CCB DOT DOTDOT PLUS MINUS LESS OPAREN AT QUESTION DOLLAR NAME 
// "__native__" "attribute" "boolean" "break" "case" "comment" "constant" 
// "continue" "default" "document" "element" "else" "exception" "false" 
// "for" "foreach" "if" "import" "integer" "node" "null" "pi" "prefix" 
// "qname" "real" "redirect" "return" "string" "switch" "text" "throw" 
// "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_6(_tokenSet_6_data_,12);
const unsigned long XmlPLParser::_tokenSet_7_data_[] = { 0UL, 0UL, 0UL, 268435520UL, 0UL, 0UL, 0UL, 0UL };
// SEMI "as" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_7(_tokenSet_7_data_,8);
const unsigned long XmlPLParser::_tokenSet_8_data_[] = { 0UL, 0UL, 0UL, 268437568UL, 0UL, 0UL, 0UL, 0UL };
// SEMI COMMA "as" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_8(_tokenSet_8_data_,8);
const unsigned long XmlPLParser::_tokenSet_9_data_[] = { 0UL, 0UL, 0UL, 268445760UL, 0UL, 0UL, 0UL, 0UL };
// SEMI COMMA MINUS "as" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_9(_tokenSet_9_data_,8);
const unsigned long XmlPLParser::_tokenSet_10_data_[] = { 0UL, 2048UL, 0UL, 68157440UL, 0UL, 0UL, 0UL, 0UL };
// BAND CPAREN NAME 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_10(_tokenSet_10_data_,8);
const unsigned long XmlPLParser::_tokenSet_11_data_[] = { 0UL, 0UL, 0UL, 1048576UL, 0UL, 0UL, 0UL, 0UL };
// CPAREN 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_11(_tokenSet_11_data_,8);
const unsigned long XmlPLParser::_tokenSet_12_data_[] = { 2UL, 31457280UL, 352UL, 4018812886UL, 4294443006UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// EOF NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM START_PI 
// SEMI OCB CCB DOT DOTDOT PLUS MINUS LESS OPAREN AT QUESTION DOLLAR NAME 
// "__native__" "attribute" "boolean" "break" "case" "catch" "comment" 
// "constant" "continue" "default" "document" "element" "else" "exception" 
// "false" "for" "foreach" "if" "import" "integer" "node" "null" "pi" "prefix" 
// "qname" "real" "redirect" "return" "string" "switch" "text" "throw" 
// "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_12(_tokenSet_12_data_,12);
const unsigned long XmlPLParser::_tokenSet_13_data_[] = { 0UL, 31457280UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM START_PI 
// SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS LESS OPAREN CPAREN CSB AT QUESTION 
// DOLLAR NAME "__native__" "attribute" "boolean" "break" "case" "comment" 
// "constant" "continue" "default" "document" "element" "else" "exception" 
// "false" "for" "foreach" "if" "integer" "node" "null" "pi" "prefix" "qname" 
// "real" "redirect" "return" "string" "switch" "text" "throw" "true" "try" 
// "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_13(_tokenSet_13_data_,12);
const unsigned long XmlPLParser::_tokenSet_14_data_[] = { 0UL, 0UL, 0UL, 1050624UL, 0UL, 0UL, 0UL, 0UL };
// COMMA CPAREN 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_14(_tokenSet_14_data_,8);
const unsigned long XmlPLParser::_tokenSet_15_data_[] = { 0UL, 4327424UL, 0UL, 70254592UL, 0UL, 0UL, 0UL, 0UL };
// BAND BSL INC CPAREN OSB NAME 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_15(_tokenSet_15_data_,8);
const unsigned long XmlPLParser::_tokenSet_16_data_[] = { 0UL, 4327424UL, 0UL, 70778880UL, 0UL, 0UL, 0UL, 0UL };
// BAND BSL INC OPAREN CPAREN OSB NAME 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_16(_tokenSet_16_data_,8);
const unsigned long XmlPLParser::_tokenSet_17_data_[] = { 0UL, 31457280UL, 352UL, 4018812886UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM START_PI 
// SEMI OCB CCB DOT DOTDOT PLUS MINUS LESS OPAREN AT QUESTION DOLLAR NAME 
// "__native__" "attribute" "boolean" "break" "case" "comment" "constant" 
// "continue" "default" "document" "element" "else" "exception" "false" 
// "for" "foreach" "if" "integer" "node" "null" "pi" "prefix" "qname" "real" 
// "redirect" "return" "string" "switch" "text" "throw" "true" "try" "void" 
// "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_17(_tokenSet_17_data_,12);
const unsigned long XmlPLParser::_tokenSet_18_data_[] = { 0UL, 0UL, 0UL, 1610612736UL, 351471000UL, 1UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// "attribute" "boolean" "comment" "constant" "document" "element" "exception" 
// "integer" "node" "pi" "prefix" "qname" "real" "string" "text" "void" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_18(_tokenSet_18_data_,12);
const unsigned long XmlPLParser::_tokenSet_19_data_[] = { 0UL, 31457280UL, 352UL, 2408199892UL, 3942938656UL, 2UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NOT INC DEC BCOMP INTEGER REAL STRING START_XML_COMM START_PI SEMI OCB 
// DOT DOTDOT PLUS MINUS LESS OPAREN AT QUESTION DOLLAR NAME "__native__" 
// "break" "continue" "false" "for" "foreach" "if" "null" "redirect" "return" 
// "switch" "throw" "true" "try" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_19(_tokenSet_19_data_,12);
const unsigned long XmlPLParser::_tokenSet_20_data_[] = { 0UL, 0UL, 0UL, 258UL, 0UL, 0UL, 0UL, 0UL };
// END_ELEM CCB 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_20(_tokenSet_20_data_,8);
const unsigned long XmlPLParser::_tokenSet_21_data_[] = { 3221225472UL, 32505759UL, 98656UL, 4294901759UL, 4294967295UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ GT LTE GTE BSL BSR MOD NOT INC DEC BCOMP 
// INTEGER REAL STRING XML_COMMENT_CHARS XML_PI_CHARS END_ELEM_SHORT END_ELEM 
// START_XML_COMM END_XML_COMM START_PI END_PI SEMI OCB CCB DOT DOTDOT 
// COMMA PLUS MINUS STAR FS LESS COLON OPAREN CPAREN OSB CSB AT QUESTION 
// DOLLAR NAME "__native__" "as" "attribute" "boolean" "break" "byte" "case" 
// "catch" "comment" "constant" "continue" "default" "document" "element" 
// "else" "exception" "false" "for" "foreach" "if" "import" "integer" "node" 
// "null" "package" "pi" "prefix" "qname" "real" "redirect" "return" "string" 
// "switch" "text" "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_21(_tokenSet_21_data_,12);
const unsigned long XmlPLParser::_tokenSet_22_data_[] = { 0UL, 0UL, 0UL, 1048640UL, 0UL, 0UL, 0UL, 0UL };
// SEMI CPAREN 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_22(_tokenSet_22_data_,8);
const unsigned long XmlPLParser::_tokenSet_23_data_[] = { 0UL, 0UL, 0UL, 256UL, 66UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// CCB "case" "default" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_23(_tokenSet_23_data_,12);
const unsigned long XmlPLParser::_tokenSet_24_data_[] = { 0UL, 0UL, 0UL, 256UL, 0UL, 0UL, 0UL, 0UL };
// CCB 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_24(_tokenSet_24_data_,8);
const unsigned long XmlPLParser::_tokenSet_25_data_[] = { 0UL, 0UL, 0UL, 262144UL, 0UL, 0UL, 0UL, 0UL };
// COLON 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_25(_tokenSet_25_data_,8);
const unsigned long XmlPLParser::_tokenSet_26_data_[] = { 3221225472UL, 32505759UL, 352UL, 4026466262UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ GT LTE GTE BSL BSR MOD NOT INC DEC BCOMP 
// INTEGER REAL STRING END_ELEM START_XML_COMM START_PI SEMI OCB CCB DOT 
// DOTDOT COMMA PLUS MINUS STAR FS LESS COLON OPAREN CPAREN OSB CSB AT 
// QUESTION DOLLAR NAME "__native__" "attribute" "boolean" "break" "case" 
// "comment" "constant" "continue" "default" "document" "element" "else" 
// "exception" "false" "for" "foreach" "if" "integer" "node" "null" "pi" 
// "prefix" "qname" "real" "redirect" "return" "string" "switch" "text" 
// "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_26(_tokenSet_26_data_,12);
const unsigned long XmlPLParser::_tokenSet_27_data_[] = { 3221225472UL, 31457311UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM START_PI 
// SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS LESS OPAREN CPAREN CSB AT QUESTION 
// DOLLAR NAME "__native__" "attribute" "boolean" "break" "case" "comment" 
// "constant" "continue" "default" "document" "element" "else" "exception" 
// "false" "for" "foreach" "if" "integer" "node" "null" "pi" "prefix" "qname" 
// "real" "redirect" "return" "string" "switch" "text" "throw" "true" "try" 
// "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_27(_tokenSet_27_data_,12);
const unsigned long XmlPLParser::_tokenSet_28_data_[] = { 0UL, 31457280UL, 352UL, 126498324UL, 1074006016UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// NOT INC DEC BCOMP INTEGER REAL STRING START_XML_COMM START_PI DOT DOTDOT 
// PLUS MINUS LESS OPAREN AT QUESTION DOLLAR NAME "false" "null" "true" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_28(_tokenSet_28_data_,12);
const unsigned long XmlPLParser::_tokenSet_29_data_[] = { 0UL, 0UL, 0UL, 4228382720UL, 4294967295UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// OPAREN NAME "__native__" "as" "attribute" "boolean" "break" "byte" "case" 
// "catch" "comment" "constant" "continue" "default" "document" "element" 
// "else" "exception" "false" "for" "foreach" "if" "import" "integer" "node" 
// "null" "package" "pi" "prefix" "qname" "real" "redirect" "return" "string" 
// "switch" "text" "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_29(_tokenSet_29_data_,12);
const unsigned long XmlPLParser::_tokenSet_30_data_[] = { 1073741824UL, 16384UL, 65536UL, 4228382753UL, 4294967295UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN GT XML_PI_CHARS END_ELEM_SHORT END_PI OPAREN NAME "__native__" 
// "as" "attribute" "boolean" "break" "byte" "case" "catch" "comment" "constant" 
// "continue" "default" "document" "element" "else" "exception" "false" 
// "for" "foreach" "if" "import" "integer" "node" "null" "package" "pi" 
// "prefix" "qname" "real" "redirect" "return" "string" "switch" "text" 
// "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_30(_tokenSet_30_data_,12);
const unsigned long XmlPLParser::_tokenSet_31_data_[] = { 1073741824UL, 16384UL, 0UL, 4228382721UL, 4294967295UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN GT END_ELEM_SHORT OPAREN NAME "__native__" "as" "attribute" "boolean" 
// "break" "byte" "case" "catch" "comment" "constant" "continue" "default" 
// "document" "element" "else" "exception" "false" "for" "foreach" "if" 
// "import" "integer" "node" "null" "package" "pi" "prefix" "qname" "real" 
// "redirect" "return" "string" "switch" "text" "throw" "true" "try" "void" 
// "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_31(_tokenSet_31_data_,12);
const unsigned long XmlPLParser::_tokenSet_32_data_[] = { 0UL, 16384UL, 0UL, 4228382721UL, 4294967295UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// GT END_ELEM_SHORT OPAREN NAME "__native__" "as" "attribute" "boolean" 
// "break" "byte" "case" "catch" "comment" "constant" "continue" "default" 
// "document" "element" "else" "exception" "false" "for" "foreach" "if" 
// "import" "integer" "node" "null" "package" "pi" "prefix" "qname" "real" 
// "redirect" "return" "string" "switch" "text" "throw" "true" "try" "void" 
// "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_32(_tokenSet_32_data_,12);
const unsigned long XmlPLParser::_tokenSet_33_data_[] = { 3221225472UL, 31457439UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM START_PI 
// SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS LESS OPAREN CPAREN CSB AT QUESTION 
// DOLLAR NAME "__native__" "attribute" "boolean" "break" "case" "comment" 
// "constant" "continue" "default" "document" "element" "else" "exception" 
// "false" "for" "foreach" "if" "integer" "node" "null" "pi" "prefix" "qname" 
// "real" "redirect" "return" "string" "switch" "text" "throw" "true" "try" 
// "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_33(_tokenSet_33_data_,12);
const unsigned long XmlPLParser::_tokenSet_34_data_[] = { 3221225472UL, 31457695UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM 
// START_PI SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS LESS OPAREN CPAREN 
// CSB AT QUESTION DOLLAR NAME "__native__" "attribute" "boolean" "break" 
// "case" "comment" "constant" "continue" "default" "document" "element" 
// "else" "exception" "false" "for" "foreach" "if" "integer" "node" "null" 
// "pi" "prefix" "qname" "real" "redirect" "return" "string" "switch" "text" 
// "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_34(_tokenSet_34_data_,12);
const unsigned long XmlPLParser::_tokenSet_35_data_[] = { 3221225472UL, 31458207UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM 
// START_PI SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS LESS OPAREN CPAREN 
// CSB AT QUESTION DOLLAR NAME "__native__" "attribute" "boolean" "break" 
// "case" "comment" "constant" "continue" "default" "document" "element" 
// "else" "exception" "false" "for" "foreach" "if" "integer" "node" "null" 
// "pi" "prefix" "qname" "real" "redirect" "return" "string" "switch" "text" 
// "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_35(_tokenSet_35_data_,12);
const unsigned long XmlPLParser::_tokenSet_36_data_[] = { 3221225472UL, 31459231UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM START_XML_COMM 
// START_PI SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS LESS OPAREN CPAREN 
// CSB AT QUESTION DOLLAR NAME "__native__" "attribute" "boolean" "break" 
// "case" "comment" "constant" "continue" "default" "document" "element" 
// "else" "exception" "false" "for" "foreach" "if" "integer" "node" "null" 
// "pi" "prefix" "qname" "real" "redirect" "return" "string" "switch" "text" 
// "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_36(_tokenSet_36_data_,12);
const unsigned long XmlPLParser::_tokenSet_37_data_[] = { 3221225472UL, 31461279UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM 
// START_XML_COMM START_PI SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS LESS 
// OPAREN CPAREN CSB AT QUESTION DOLLAR NAME "__native__" "attribute" "boolean" 
// "break" "case" "comment" "constant" "continue" "default" "document" 
// "element" "else" "exception" "false" "for" "foreach" "if" "integer" 
// "node" "null" "pi" "prefix" "qname" "real" "redirect" "return" "string" 
// "switch" "text" "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_37(_tokenSet_37_data_,12);
const unsigned long XmlPLParser::_tokenSet_38_data_[] = { 0UL, 114688UL, 0UL, 131072UL, 0UL, 0UL, 0UL, 0UL };
// GT LTE GTE LESS 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_38(_tokenSet_38_data_,8);
const unsigned long XmlPLParser::_tokenSet_39_data_[] = { 3221225472UL, 31473567UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ NOT INC DEC BCOMP INTEGER REAL STRING END_ELEM 
// START_XML_COMM START_PI SEMI OCB CCB DOT DOTDOT COMMA PLUS MINUS LESS 
// OPAREN CPAREN CSB AT QUESTION DOLLAR NAME "__native__" "attribute" "boolean" 
// "break" "case" "comment" "constant" "continue" "default" "document" 
// "element" "else" "exception" "false" "for" "foreach" "if" "integer" 
// "node" "null" "pi" "prefix" "qname" "real" "redirect" "return" "string" 
// "switch" "text" "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_39(_tokenSet_39_data_,12);
const unsigned long XmlPLParser::_tokenSet_40_data_[] = { 3221225472UL, 31588255UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ GT LTE GTE NOT INC DEC BCOMP INTEGER REAL 
// STRING END_ELEM START_XML_COMM START_PI SEMI OCB CCB DOT DOTDOT COMMA 
// PLUS MINUS LESS OPAREN CPAREN CSB AT QUESTION DOLLAR NAME "__native__" 
// "attribute" "boolean" "break" "case" "comment" "constant" "continue" 
// "default" "document" "element" "else" "exception" "false" "for" "foreach" 
// "if" "integer" "node" "null" "pi" "prefix" "qname" "real" "redirect" 
// "return" "string" "switch" "text" "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_40(_tokenSet_40_data_,12);
const unsigned long XmlPLParser::_tokenSet_41_data_[] = { 3221225472UL, 31981471UL, 352UL, 4024057814UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ GT LTE GTE BSL BSR NOT INC DEC BCOMP INTEGER 
// REAL STRING END_ELEM START_XML_COMM START_PI SEMI OCB CCB DOT DOTDOT 
// COMMA PLUS MINUS LESS OPAREN CPAREN CSB AT QUESTION DOLLAR NAME "__native__" 
// "attribute" "boolean" "break" "case" "comment" "constant" "continue" 
// "default" "document" "element" "else" "exception" "false" "for" "foreach" 
// "if" "integer" "node" "null" "pi" "prefix" "qname" "real" "redirect" 
// "return" "string" "switch" "text" "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_41(_tokenSet_41_data_,12);
const unsigned long XmlPLParser::_tokenSet_42_data_[] = { 0UL, 12582912UL, 352UL, 126354944UL, 1074006016UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// INC DEC INTEGER REAL STRING DOT DOTDOT OPAREN AT QUESTION DOLLAR NAME 
// "false" "null" "true" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_42(_tokenSet_42_data_,12);
const unsigned long XmlPLParser::_tokenSet_43_data_[] = { 3221225472UL, 32505759UL, 352UL, 4024106966UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ GT LTE GTE BSL BSR MOD NOT INC DEC BCOMP 
// INTEGER REAL STRING END_ELEM START_XML_COMM START_PI SEMI OCB CCB DOT 
// DOTDOT COMMA PLUS MINUS STAR FS LESS OPAREN CPAREN CSB AT QUESTION DOLLAR 
// NAME "__native__" "attribute" "boolean" "break" "case" "comment" "constant" 
// "continue" "default" "document" "element" "else" "exception" "false" 
// "for" "foreach" "if" "integer" "node" "null" "pi" "prefix" "qname" "real" 
// "redirect" "return" "string" "switch" "text" "throw" "true" "try" "void" 
// "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_43(_tokenSet_43_data_,12);
const unsigned long XmlPLParser::_tokenSet_44_data_[] = { 3221225472UL, 32505759UL, 352UL, 4026204118UL, 4294410234UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN COMMA_ASSIGN 
// OR AND BOR BXOR BAND NE EQ GT LTE GTE BSL BSR MOD NOT INC DEC BCOMP 
// INTEGER REAL STRING END_ELEM START_XML_COMM START_PI SEMI OCB CCB DOT 
// DOTDOT COMMA PLUS MINUS STAR FS LESS OPAREN CPAREN OSB CSB AT QUESTION 
// DOLLAR NAME "__native__" "attribute" "boolean" "break" "case" "comment" 
// "constant" "continue" "default" "document" "element" "else" "exception" 
// "false" "for" "foreach" "if" "integer" "node" "null" "pi" "prefix" "qname" 
// "real" "redirect" "return" "string" "switch" "text" "throw" "true" "try" 
// "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_44(_tokenSet_44_data_,12);
const unsigned long XmlPLParser::_tokenSet_45_data_[] = { 0UL, 0UL, 512UL, 4227874816UL, 4294967295UL, 3UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// REGEX STAR NAME "__native__" "as" "attribute" "boolean" "break" "byte" 
// "case" "catch" "comment" "constant" "continue" "default" "document" 
// "element" "else" "exception" "false" "for" "foreach" "if" "import" "integer" 
// "node" "null" "package" "pi" "prefix" "qname" "real" "redirect" "return" 
// "string" "switch" "text" "throw" "true" "try" "void" "while" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_45(_tokenSet_45_data_,12);
const unsigned long XmlPLParser::_tokenSet_46_data_[] = { 0UL, 0UL, 0UL, 536870912UL, 269615496UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// "attribute" "comment" "document" "element" "node" "pi" "text" 
const ANTLR_USE_NAMESPACE(antlr)BitSet XmlPLParser::_tokenSet_46(_tokenSet_46_data_,12);


