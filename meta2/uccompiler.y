%{
#include "ast.h"
#include <stdio.h>

int yylex();
void yyerror(const char *);

struct node *node;
struct node *program;

extern char *yytext;
%}

%token CHAR DOUBLE INT SHORT ELSE WHILE IF RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI error
%token<token> IDENTIFIER NATURAL DECIMAL CHRLIT RESERVED
%type<node> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration Declarations TypeSpec Declarator Statement Statements StatementError Expr ExprList

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
Program: FunctionsAndDeclarations {node = newnode(Program, NULL); addchild(node, $1);} 
    ;

FunctionsAndDeclarations: FunctionDefinition {$$ = $1;}
    | FunctionDeclaration {$$ = $1;}
    | Declaration {$$ = $1;}
    | FunctionsAndDeclarations FunctionDefinition {$$=$1;addbrother($1,$2);}
    | FunctionsAndDeclarations FunctionDeclaration {$$=$1;addbrother($1,$2);}
    | FunctionsAndDeclarations Declaration {$$=$1;addbrother($1,$2);}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$ = newnode(FuncDefinition, NULL); addchild($$,$1); addbrother($1,$2); addbrother($1,$3);}
    ;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {$$ = newnode(FuncBody, NULL); addchild($$, $2);}
    | LBRACE RBRACE {$$ = newnode(FuncBody, NULL);}
    ;

DeclarationsAndStatements: DeclarationsAndStatements Statement {$$=$1; addbrother($1,$2);}
    | DeclarationsAndStatements Declaration {$$=$1; addbrother($1,$2);}
    | Statement {$$ = $1;}
    | Declaration {$$ = $1;}
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$ = newnode(FuncDeclaration, NULL); addchild($$, $1); addbrother($$, $2);}
    ;

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {$$ = newnode(Call, NULL); addchild($$, newnode(Identifier, $1)); addbrother($$, $3);}
    ;

ParameterList: ParameterDeclaration {$$=$1;}
    | ParameterList COMMA ParameterDeclaration  {$$=$1;addbrother($1,$3);}
    ;

ParameterDeclaration: TypeSpec IDENTIFIER {$$ = newnode(ParamDeclaration, NULL); addchild($$, $1); addbrother($$, newnode(Identifier, $2));}
    | TypeSpec {$$ = newnode(ParamDeclaration, NULL); addchild($$, $1);}
    ;

Declaration: error SEMI {$$=newnode(Error,NULL);} 
    | TypeSpec Declarations SEMI {$$ = newnode(Declaration, NULL); addchild($$, $1); addbrother($$, $2);}   //deve ser preciso um while
    ;

Declarations: Declarator {$$ = $1;}
    | Declarations COMMA Declarator {$$=$1;addbrother($1,$3);}
    ;

Declarator: IDENTIFIER {$$ = newnode(Declaration, NULL);addchild($$,newnode(Identifier,$1));}   //analisar melhor
    | IDENTIFIER ASSIGN ExprList {$$ = newnode(Store, NULL); addchild($$, newnode(Identifier, $1)); addchild($$, $3);}  //analisar melhor
    ;

TypeSpec: CHAR {$$=newnode(Char,NULL);}
    | INT {$$=newnode(Int,NULL);}
    | VOID {$$=newnode(Void,NULL);}
    | SHORT {$$=newnode(Short,NULL);}
    | DOUBLE {$$=newnode(Double,NULL);}
    ;

Statement: LBRACE error RBRACE {$$=newnode(Error,NULL);;}
    | SEMI {$$ = NULL;}
    | ExprList SEMI {$$ = $1;}
    | LBRACE RBRACE {$$ = NULL;}
    | LBRACE Statements RBRACE {$$ = newnode(StatList, NULL); addchild($$, $2);}
    | IF LPAR ExprList RPAR StatementError {$$ = newnode(If, NULL); addchild($$, $3); addbrother($$, $5);}  //pode ser preciso if else
    | IF LPAR ExprList RPAR StatementError ELSE StatementError {$$ = newnode(If, NULL); addchild($$, $3); addbrother($$, $5); addbrother($$, $7);}  //pode ser preciso if else
    | WHILE LPAR ExprList RPAR StatementError {$$ = newnode(While, NULL); addchild($$, $3); addbrother($$, $5);}
    | RETURN SEMI {$$=newnode(Return, NULL);}
    | RETURN ExprList SEMI {$$=newnode(Return, NULL); addchild($$, $2);}
    ;

StatementError: error SEMI {$$=newnode(Error,NULL);}
    | Statement {$$ = $1;}

Statements: StatementError {$$ = $1;}
    | Statements StatementError {addbrother($1,$2);}
    ;

Expr: IDENTIFIER LPAR error RPAR {$$=newnode(Error,NULL);}
    | LPAR error RPAR {$$=newnode(Error,NULL);}
    | IDENTIFIER {$$ = newnode(Identifier,$1);}
    | NATURAL {$$ = newnode(Natural,$1);}
    | CHRLIT {$$ = newnode(ChrLit,$1);}
    | DECIMAL {$$ = newnode(Decimal,$1);}
    | LPAR ExprList RPAR {$$ = $2;}
    | Expr ASSIGN Expr {$$ = newnode(Store, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr PLUS Expr {$$ = newnode(Plus, NULL); addchild($$, $1);}
    | Expr MINUS Expr {$$ = newnode(Minus, NULL); addchild($$, $1);}
    | Expr MUL Expr {$$ = newnode(Mul, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr DIV Expr {$$ = newnode(Div, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr MOD Expr {$$ = newnode(Mod, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr OR Expr {$$ = newnode(Or, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr AND Expr {$$ = newnode(And, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr BITWISEOR Expr {$$ = newnode(BitWiseOr, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr BITWISEXOR Expr {$$ = newnode(BitWiseXor, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr BITWISEAND Expr {$$ = newnode(BitWiseAnd, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr EQ Expr {$$ = newnode(Eq, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr NE Expr {$$ = newnode(Ne, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr LE Expr {$$ = newnode(Lt, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr GE Expr {$$ = newnode(Ge, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr LT Expr {$$ = newnode(Lt, NULL); addchild($$, $1); addbrother($$, $3);}
    | Expr GT Expr {$$ = newnode(Gt, NULL); addchild($$, $1); addbrother($$, $3);}
    | MINUS Expr {$$ = newnode(Minus, NULL); addchild($$, $2);}
    | PLUS Expr {$$ = newnode(Plus, NULL); addchild($$, $2);}
    | NOT Expr {$$ = newnode(Not, NULL); addchild($$, $2);}
    | IDENTIFIER LPAR RPAR {$$ = newnode(Call, NULL); addchild($$, newnode(Identifier, $1));}
    | IDENTIFIER LPAR ExprList RPAR {$$ = newnode(Call, NULL); addchild($$, newnode(Identifier, $1)); addbrother($$, $3);}
    ;

ExprList: Expr {$$ = $1;}
    | ExprList COMMA Expr {$$ = newnode(Comma, NULL); addchild($$, $1); addbrother($1, $3);}
    ;


%%