#!/bin/sh

for i in `find . -name \*.cpp -o -name \*.h -o -name \*.g | egrep -v 'XmlPL(Lexer)|(Parser)|(ASTTypes)'`;do cat $i; done | wc -l
