/* START definitions section -- C code delimited by %{ ... %} and token declarations */

%{

#include "ast.h"

int yylex(void);
void yyerror(char *);

struct node *program;

%}

%token INTEGER DOUBLE IF THEN ELSE
%token<token> IDENTIFIER NATURAL DECIMAL
%type<node> program parameters parameter arguments expression

%left LOW
%left '+' '-'
%left '*' '/'

%union{
    char *token;
    struct node *node;
}

/* START grammar rules section -- BNF grammar */

%%
FunctionsAndDeclarations −→(FunctionDefinition | FunctionDeclaration | Declaration) {Func-
tionDefinition | FunctionDeclaration | Declaration}
FunctionDefinition −→TypeSpec FunctionDeclarator FunctionBody
FunctionBody −→LBRACE [DeclarationsAndStatements] RBRACE
DeclarationsAndStatements −→Statement DeclarationsAndStatements | Declaration Declarati-
onsAndStatements | Statement | Declaration
FunctionDeclaration −→TypeSpec FunctionDeclarator SEMI
FunctionDeclarator −→IDENTIFIER LPAR ParameterList RPAR
ParameterList −→ParameterDeclaration {COMMA ParameterDeclaration}
ParameterDeclaration −→TypeSpec [IDENTIFIER]
Declaration −→TypeSpec Declarator {COMMA Declarator} SEMI
TypeSpec −→CHAR | INT | VOID | SHORT | DOUBLE
Declarator −→IDENTIFIER [ASSIGN Expr]
Statement −→[Expr] SEMI
Statement −→LBRACE {Statement} RBRACE
Statement −→IF LPAR Expr RPAR Statement [ELSE Statement]
Statement −→WHILE LPAR Expr RPAR Statement
Statement −→RETURN [Expr] SEMI
Expr −→Expr (ASSIGN | COMMA) Expr
Expr −→Expr (PLUS | MINUS | MUL | DIV | MOD) Expr
Expr −→Expr (OR | AND | BITWISEAND | BITWISEOR | BITWISEXOR) Expr
Expr −→Expr (EQ | NE | LE | GE | LT | GT) Expr
Expr −→(PLUS | MINUS | NOT) Expr
Expr −→IDENTIFIER LPAR [Expr {COMMA Expr}] RPAR
Expr −→IDENTIFIER | NATURAL | CHRLIT | DECIMAL | LPAR Expr RPAR

program: IDENTIFIER '(' parameters ')' '=' expression
                                    { $$ = program = newnode(Program, NULL);
                                      struct node *function = newnode(Function, NULL);
                                      addchild(function, newnode(Identifier, $1));
                                      addchild(function, $3);
                                      addchild(function, $6);
                                      addchild($$, function); }
    ;

parameters: parameter               { /* ... */ }
    | parameters ',' parameter      { /* ... */ }
    ;

parameter: INTEGER IDENTIFIER       { /* ... */ }
    | DOUBLE IDENTIFIER             { /* ... */ }
    ;

arguments: expression               { /* ... */ }
    | arguments ',' expression      { /* ... */ }
    ;

expression: IDENTIFIER              { /* ... */ }
    | NATURAL                       { /* ... */ }
    | DECIMAL                       { /* ... */ }
    | IDENTIFIER '(' arguments ')'  { /* ... */ }
    | IF expression THEN expression ELSE expression  %prec LOW
                                    { /* ... */ }
    | expression '+' expression     { /* ... */ }
    | expression '-' expression     { /* ... */ }
    | expression '*' expression     { /* ... */ }
    | expression '/' expression     { /* ... */ }
    | '(' expression ')'            { /* ... */ }  
    ;

%%

/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
