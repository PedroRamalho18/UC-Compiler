#!/bin/sh
rm -f uccompiler lex.yy.c y.tab.c y.tab.h
yacc -d -v -t -g -Wcounterexamples --report=all uccompiler.y 
lex uccompiler.l
cc -o uccompiler lex.yy.c y.tab.c ast.c semantics.c -g -Wall -Wno-unused-function