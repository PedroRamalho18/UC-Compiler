%{
#include "ast.h"
#include <stdio.h>

int yylex();
void yyerror(const char *);

struct node *node;
struct node *program;
struct node* aux;
struct node* aux1;

extern char *yytext;

int stat_check = 0;
int error_check = 0;
%}

%token CHAR DOUBLE INT SHORT ELSE WHILE IF RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI error
%token<token> IDENTIFIER NATURAL DECIMAL CHRLIT RESERVED
%type<node> Program FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration Declarations TypeSpec Declarator Statement Statements StatementError Expr ExprList ExprCall

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
    | FunctionsAndDeclarations FunctionDefinition {$$=$1;addbrother($$,$2);}
    | FunctionsAndDeclarations FunctionDeclaration {$$=$1;addbrother($$,$2);}
    | FunctionsAndDeclarations Declaration {$$=$1;addbrother($$,$2);}
    ;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$ = newnode(FuncDefinition, NULL); addchild($$,$1); addchild($$,$2); addchild($$,$3);}
    ;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {$$ = newnode(FuncBody, NULL); addchild($$, $2);}
    | LBRACE RBRACE {$$ = newnode(FuncBody, NULL);}
    ;

DeclarationsAndStatements: DeclarationsAndStatements Statement {$$=$1; addbrother($$,$2);}
    | DeclarationsAndStatements Declaration {$$=$1; addbrother($$,$2);}
    | Statement {$$ = $1;}
    | Declaration {$$ = $1;}
    ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$ = newnode(FuncDeclaration, NULL); addchild($$, $1); addchild($$, $2);}
    ;

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {$$ = newnode(Identifier, $1); aux=newnode(ParamList,NULL); addchild(aux,$3); addbrother($$,aux);
    }
    ;

ParameterList: ParameterDeclaration {$$=$1;}
    | ParameterList COMMA ParameterDeclaration  {$$=$1; addbrother($$, $3);}
    ;

ParameterDeclaration: TypeSpec IDENTIFIER {$$ = newnode(ParamDeclaration, NULL); addchild($$, $1); addchild($$, newnode(Identifier, $2));}
    | TypeSpec {$$ = newnode(ParamDeclaration, NULL); addchild($$, $1);}
    ;

Declaration: error SEMI {$$=newnode(Error,NULL); error_check=1;} 
    | TypeSpec Declarations SEMI {
                                    $$ = $2;
                                    aux = $$;
                                    while(aux != NULL){
                                        aux->children->next->node->category = $1->category;
                                        aux = aux->brother;
                                    }
                                }
    ;

Declarations: Declarator {$$ = $1;}
    | Declarations COMMA Declarator {$$=$1; addbrother($$, $3);}
    ;

TypeSpec: CHAR {$$=newnode(Char,NULL);}
    | INT {$$=newnode(Int,NULL);}
    | VOID {$$=newnode(Void,NULL);}
    | SHORT {$$=newnode(Short,NULL);}
    | DOUBLE {$$=newnode(Double,NULL);}
    ;

Declarator: IDENTIFIER {$$ = newnode(Declaration, NULL); addchild($$, newnode(Null, NULL)); addchild($$, newnode(Identifier, $1));}   
    | IDENTIFIER ASSIGN ExprList {$$ = newnode(Declaration, NULL); addchild($$, newnode(Null, NULL)); addchild($$, newnode(Identifier, $1)); addchild($$, $3);}  
    ;

Statement: LBRACE error RBRACE {$$=newnode(Error,NULL); error_check=1;}
    | SEMI {$$ = NULL;}
    | ExprList SEMI {$$ = $1;}
    | LBRACE RBRACE {$$ = NULL;}
    | LBRACE Statements RBRACE {
                        if(stat_check == 1){
						    $$=newnode(StatList, NULL);
						    addchild($$,$2);
                        }
					    else{
						    $$ = $2;
				    	}
                    }
    | IF LPAR ExprList RPAR StatementError {
        $$ = newnode(If, NULL); addchild($$, $3);
        if($5 == NULL){
            aux = newnode(Null,NULL);
            addchild($$,aux);
        }else{
            addchild($$, $5);
        }
        addchild($$, newnode(Null,NULL));
    }
    | IF LPAR ExprList RPAR StatementError ELSE StatementError {
        $$ = newnode(If, NULL); addchild($$, $3);
        if($5 == NULL){
            addchild($$,newnode(Null,NULL));
        }else{
            addchild($$,$5);
        }

        if($7 == NULL){
            addchild($$,newnode(Null,NULL));
        }else{
            addchild($$,$7);
        }
    }
    | WHILE LPAR ExprList RPAR StatementError {
        $$ = newnode(While, NULL); addchild($$, $3);
        if($5 == NULL){
            addchild($$, newnode(Null,NULL));
        }else{
            addchild($$, $5);
        }
    }
    | RETURN SEMI {$$=newnode(Return, NULL); addchild($$, newnode(Null,NULL));}
    | RETURN ExprList SEMI {$$=newnode(Return, NULL); addchild($$, $2);}
    ;

StatementError: error SEMI {$$=newnode(Error,NULL); error_check=1;}
    | Statement {$$ = $1;}

Statements: StatementError {$$ = $1; stat_check = 0;}
    | Statements StatementError {$$=$1; addbrother($$,$2); stat_check = 1;}
    ;

ExprList: Expr {$$ = $1;}
    | ExprList COMMA Expr {$$ = newnode(Comma, NULL); addchild($$, $1); addchild($$, $3);}
    ;

ExprCall: ExprCall COMMA Expr {$$ = $1; addbrother($$, $3);}
    | Expr {$$ = $1;}
    ;

Expr: IDENTIFIER LPAR error RPAR {$$=newnode(Error,NULL); error_check=1;}
    | LPAR error RPAR {$$=newnode(Error,NULL); error_check=1;}
    | IDENTIFIER {$$ = newnode(Identifier,$1);}
    | NATURAL {$$ = newnode(Natural,$1);}
    | CHRLIT {$$ = newnode(ChrLit,$1);}
    | DECIMAL {$$ = newnode(Decimal,$1);}
    | LPAR ExprList RPAR {$$ = $2;}
    | Expr ASSIGN Expr {$$ = newnode(Store, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr PLUS Expr {$$ = newnode(Add, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr MINUS Expr {$$ = newnode(Sub, NULL); addchild($$, $1); addchild($$, $3);}
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
    | Expr LE Expr {$$ = newnode(Le, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GE Expr {$$ = newnode(Ge, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LT Expr {$$ = newnode(Lt, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GT Expr {$$ = newnode(Gt, NULL); addchild($$, $1); addchild($$, $3);}
    | MINUS Expr %prec NOT {$$ = newnode(Minus, NULL); addchild($$, $2);}
    | PLUS Expr %prec NOT {$$ = newnode(Plus, NULL); addchild($$, $2);}
    | NOT Expr {$$ = newnode(Not, NULL); addchild($$, $2);}
    | IDENTIFIER LPAR RPAR {$$ = newnode(Call, NULL); addchild($$, newnode(Identifier, $1));}
    | IDENTIFIER LPAR ExprCall RPAR {$$ = newnode(Call, NULL); addchild($$, newnode(Identifier, $1)); addchild($$, $3);}
    ;
%%