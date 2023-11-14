 /*Pedro Tiago Gomes Ramalho 2019248594
    André Rodrigues Costa Pinto 2021213497 */
%{
#include "ast.h"
#include <stdio.h>

int yylex();
void yyerror(const char *);
struct node *node;
extern char *yytext;
int syntax_error=0;
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

Declaration: error SEMI {syntax_error=1;} 
    | TypeSpec Declarations SEMI {;}
    ;

Declarations: Declarator {;}
    | Declarations COMMA Declarator {;}
    ;

TypeSpec: CHAR {$$=newnode(Char,NULL);}
    | INT {$$=newnode(Int,NULL);}
    | VOID {$$=newnode(Void,NULL);}
    | SHORT {$$=newnode(Short,NULL);}
    | DOUBLE {$$=newnode(Double,NULL);}
    ;

Declarator: IDENTIFIER {;}
    | IDENTIFIER ASSIGN ExprList {;}
    ;

Statement: LBRACE error RBRACE {syntax_error=1;}
    | SEMI {;}
    | ExprList SEMI {;}
    | LBRACE RBRACE {;}
    | LBRACE Statements RBRACE {;}
    | IF LPAR ExprList RPAR StatementError {;}
    | IF LPAR ExprList RPAR StatementError ELSE StatementError {;}
    | WHILE LPAR ExprList RPAR StatementError {;}
    | RETURN SEMI {;}
    | RETURN ExprList SEMI {;}
    ;

StatementError: error SEMI {syntax_error=1;}
    | Statement {;}

Statements: StatementError {;}
    | Statements StatementError {;}
    ;

Expr: IDENTIFIER LPAR error RPAR {syntax_error=1;}
    | LPAR error RPAR {syntax_error=1;}
    | IDENTIFIER {$$ = newnode(Identifier,$1);}
    | NATURAL {$$ = newnode(Natural,$1);}
    | CHRLIT {$$ = newnode(ChrLit,$1);}
    | DECIMAL {$$ = newnode(Decimal,$1);}
    | LPAR ExprList RPAR {$$ = $2;}
    | Expr ASSIGN Expr {;}
    | Expr PLUS Expr {$$ = newnode(Plus, NULL); addchild($$, $1); addbrother($1,$3);}
    | Expr MINUS Expr {$$ = newnode(Minus, NULL); addchild($$, $1); addbrother($1,$3);}
    | Expr MUL Expr {$$ = newnode(Mul, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr DIV Expr {$$ = newnode(Div, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr MOD Expr {$$ = newnode(Mod, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr OR Expr {$$ = newnode(Or, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr AND Expr {$$ = newnode(And, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr BITWISEOR Expr {$$ = newnode(BitWiseOr, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr BITWISEXOR Expr {$$ = newnode(BitWiseXor, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr BITWISEAND Expr {$$ = newnode(BitWiseAnd, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr EQ Expr {$$ = newnode(Eq, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr NE Expr {$$ = newnode(Ne, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LE Expr {$$ = newnode(Lt, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GE Expr {$$ = newnode(Ge, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LT Expr {$$ = newnode(Lt, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GT Expr {$$ = newnode(Gt, NULL); addchild($$, $1); addchild($$, $3);}
    | MINUS Expr {$$ = newnode(Minus, NULL); addchild($$, $2);}
    | PLUS Expr {$$ = newnode(Plus, NULL); addchild($$, $2);}
    | NOT Expr {$$ = newnode(Not, NULL); addchild($$, $2);}
    | IDENTIFIER LPAR RPAR {$$ = newnode(Call, NULL); addchild($$, newnode(Identifier, $1));}
    | IDENTIFIER LPAR ExprList RPAR {$$ = newnode(Call, NULL); addchild($$, newnode(Identifier, $1)); addchild($$, $3);}
    ;

ExprList: Expr {$$ = $1;}
    | ExprList COMMA Expr {$$ = newnode(Comma, NULL); addchild($$, $1); addchild($$, $3);}
    ;


%%