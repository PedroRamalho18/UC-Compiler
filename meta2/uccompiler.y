 /*Pedro Tiago Gomes Ramalho 2019248594
    André Rodrigues Costa Pinto 2021213497 */
%{
#include "ast.h"
#include <stdio.h>

int yylex();
void yyerror(const char *);
struct node *program;

extern char *yytext;
%}

%token CHAR DOUBLE INT SHORT ELSE WHILE IF RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI error
%token<token> IDENTIFIER NATURAL DECIMAL CHRLIT RESERVED
%type<node> program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration Declarations TypeSpec Declarator Statement Statements Expr ExprList

%left COMMA  
%right ASSIGN
%left OR 
%left AND 
%left BITWISEOR 
%left BITWISEXOR 
%left BITWISEAND 
%left EQ NE      
%left LT LE GE GT  
%left PLUS MINUS     
%left MUL DIV MOD 
%right NOT
%left LPAR RPAR   

%nonassoc ELSE

%union{
    char *token;
    struct node *node;
}

%%
program: FunctionsAndDeclarations {;} 
    ;

FunctionsAndDeclarations: FunctionDefinition {;}
    | FunctionDeclaration {;}
    | Declaration {;}
    | FunctionsAndDeclarations FunctionDefinition {;}
    | FunctionsAndDeclarations FunctionDeclaration {;}
    | FunctionsAndDeclarations Declaration {;}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {;}
    ;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {;}
    | LBRACE RBRACE {;}
    ;

DeclarationsAndStatements: DeclarationsAndStatements Statement {;}
    | DeclarationsAndStatements Declaration {;}
    | Statement {;}
    | Declaration {;}
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {;}
    ;

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {;}
    ;

ParameterList: ParameterDeclaration {;}
    | ParameterList COMMA ParameterDeclaration  {;}
    ;

ParameterDeclaration: TypeSpec IDENTIFIER {;}
    | TypeSpec {;}
    ;

Declaration: error SEMI {;} 
    | TypeSpec Declarations SEMI {;}
    ;

Declarations: Declarator {;}
    | Declarations COMMA Declarator {;}
    ;

TypeSpec: CHAR {;}
    | INT {;}
    | VOID {;}
    | SHORT {;}
    | DOUBLE {;}
    ;

Declarator: IDENTIFIER {;}
    | IDENTIFIER ASSIGN Expr {;}
    ;

Statement: LBRACE error RBRACE {;}
    | SEMI {;}
    | Expr SEMI {;}
    | LBRACE RBRACE {;}
    | LBRACE Statements RBRACE {;}
    | IF LPAR Expr RPAR StatementError {;}
    | IF LPAR Expr RPAR StatementError ELSE StatementError {;}
    | WHILE LPAR Expr RPAR StatementError {;}
    | RETURN SEMI {;}
    | RETURN Expr SEMI {;}
    ;

StatementError: error SEMI {;}
    | Statement {;}

Statements: StatementError {;}
    | Statements StatementError {;}
    ;

Expr: IDENTIFIER LPAR error RPAR {;}
    | LPAR error RPAR {;}
    | IDENTIFIER {;}
    | NATURAL {;}
    | CHRLIT {;}
    | DECIMAL {;}
    | LPAR Expr RPAR {;}
    | Expr ASSIGN Expr {;}
    | Expr COMMA Expr {;}
    | Expr PLUS Expr {;}
    | Expr MINUS Expr {;}
    | Expr MUL Expr {;}
    | Expr DIV Expr {;}
    | Expr MOD Expr {;}
    | Expr OR Expr {;}
    | Expr AND Expr {;}
    | Expr BITWISEOR Expr {;}
    | Expr BITWISEXOR Expr {;}
    | Expr BITWISEAND Expr {;}
    | Expr EQ Expr {;}
    | Expr NE Expr {;}
    | Expr LE Expr {;}
    | Expr GE Expr {;}
    | Expr LT Expr {;}
    | Expr GT Expr {;}
    | MINUS Expr {;}
    | PLUS Expr {;}
    | NOT Expr {;}
    | IDENTIFIER LPAR RPAR {;} 
    | IDENTIFIER LPAR ExprList RPAR {;}
    ;

ExprList: COMMA Expr {;}
    | ExprList COMMA Expr {;}
    ;


%%