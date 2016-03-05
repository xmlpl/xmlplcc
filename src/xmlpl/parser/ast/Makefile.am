EXTRA_DIST =\
	createASTVisitor.sh

noinst_LTLIBRARIES = libxmlplAST.la

AST_SOURCES =\
	VariableRef.h\
	VariableRef.cpp\
	Constant.h\
	Constant.cpp\
	FunctionCall.h\
	FunctionCall.cpp\
	BinaryExpr.h\
	BinaryExpr.cpp\
	XMLQName.h\
	XMLQName.cpp\
	XMLElement.h\
	XMLElement.cpp\
	XMLAttr.h\
	XMLAttr.cpp\
	XMLComment.h\
	XMLComment.cpp\
	XMLPI.h\
	XMLPI.cpp\
	Step.h\
	Step.cpp\
	Predicates.h\
	Predicates.cpp\
	PathExpr.h\
	PathExpr.cpp\
	UnaryExpr.h\
	UnaryExpr.cpp\
	BlockStmt.h\
	BlockStmt.cpp\
	Program.h\
	Program.cpp\
	NativeBlock.h\
	NativeBlock.cpp\
	TryStmt.h\
	TryStmt.cpp\
	ThrowStmt.h\
	ThrowStmt.cpp\
	DefaultCase.h\
	DefaultCase.cpp\
	CaseStmt.h\
	CaseStmt.cpp\
	SwitchStmt.h\
	SwitchStmt.cpp\
	WhileStmt.h\
	WhileStmt.cpp\
	ForStmt.h\
	ForStmt.cpp\
	Empty.h\
	Empty.cpp\
	ForeachStmt.h\
	ForeachStmt.cpp\
	IfStmt.h\
	IfStmt.cpp\
	BreakStmt.h\
	BreakStmt.cpp\
	ContinueStmt.h\
	ContinueStmt.cpp\
	ReturnStmt.h\
	ReturnStmt.cpp\
	Argument.h\
	Argument.cpp\
	VariableDecl.h\
	VariableDecl.cpp\
	FunctionDecl.h\
	FunctionDecl.cpp\
	ExpressionStmt.h\
	ExpressionStmt.cpp\
	Assignment.h\
	Assignment.cpp\
	NameTest.h\
	NameTest.cpp\
	TypeTest.h\
	TypeTest.cpp\
	SequenceExpr.h\
	SequenceExpr.cpp\
	ImportDecl.h\
	ImportDecl.cpp\
	Cast.h\
	Cast.cpp\
	VersionRange.h\
	VersionRange.cpp\
	VersionOr.h\
	VersionOr.cpp\
	PackageDecl.h\
	PackageDecl.cpp\
	FilterExpr.h\
	FilterExpr.cpp\
	ArrayExpr.h\
	ArrayExpr.cpp\
	IntPredicate.h\
	IntPredicate.cpp\
	RedirectStmt.h\
	RedirectStmt.cpp

libxmlplAST_la_SOURCES :=\
	XmlPLAST.h\
	XmlPLAST.cpp\
	Expression.h\
	Filterable.h\
	Filterable.cpp\
	$(AST_SOURCES)

libxmlplAST_la_CXXFLAGS =\
	-I@antlr_PREFIX@/include\
	@libxmlpl_cpp_runtime_CFLAGS@\
  @BasicUtils_CFLAGS@\
	-I../../..

BUILT_SOURCES =\
	XmlPLASTTypes.h\
	ASTVisitor.h

XmlPLASTTypes.h: ASTTypes.txt
	echo -e "#ifndef XmlPLASTTYPES_H\n#define XmlPLASTTYPES_H\n" >$@;\
	for i in $(shell cat ASTTypes.txt); do\
          echo "#include \"$$i.h\"";\
        done >>$@;\
	echo -e "\n#endif // XmlPLASTTYPES_H" >>$@;\
	if [ $$? -ne 0 ]; then rm -f $@; exit 1; fi


ASTVisitor.h: ASTTypes.txt createASTVisitor.sh
	./createASTVisitor.sh $(shell cat ASTTypes.txt) >$@;\
	if [ $$? -ne 0 ]; then rm -f $@; exit 1; fi

ASTTypes.txt: Makefile.am
	@echo $(AST_SOURCES) | sed -e 's/[a-zA-Z_]*\.cpp//g;s/\.h/\n/g;s/ //g' | sort >$@;\
	if [ $$? -ne 0 ]; then rm -f $@; exit 1; fi

clean-built:
	rm -f $(BUILT_SOURCES)
