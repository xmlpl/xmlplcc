#!/bin/sh

echo "#ifndef ASTVISITOR_H"
echo "#define ASTVISITOR_H"
echo
echo "#include <BasicUtils/BasicException.h>"
echo
for i in $@; do
    echo "class $i;"
done
echo
echo "class ASTVisitor {"
echo "public:"
echo "  virtual ~ASTVisitor() {}"
for i in $@; do
    echo "  virtual void visitAST($i *) {THROW(\"Not Supported!\");}"
done
echo "};"
echo "#endif // ASTVISITOR_H"
