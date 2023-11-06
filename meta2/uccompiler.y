%{
#include <stdio.h>
%}

%token TYPE CHAR INT VOID SHORT DOUBLE IDENTIFIER NATURAL CHRLIT DECIMAL
%token LBRACE RBRACE LPAR RPAR LBRACE RBRACE SEMI COMMA
%token PLUS MINUS MUL DIV MOD OR AND BITWISEAND BITWISEOR BITWISEXOR
%token EQ NE LE GE LT GT ASSIGN NOT IF ELSE WHILE RETURN

%%

FunctionsAndDeclarations: (FunctionDefinition | FunctionDeclaration | Declaration) { /* Code here */ }

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody { /* Code here */ }

FunctionBody: LBRACE DeclarationsAndStatements RBRACE { /* Code here */ }

DeclarationsAndStatements: Statement DeclarationsAndStatements | Declaration DeclarationsAndStatements | Statement | Declaration { /* Code here */ }

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI { /* Code here */ }

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR { /* Code here */ }

ParameterList: ParameterDeclaration { COMMA ParameterDeclaration } { /* Code here */ }

ParameterDeclaration: TypeSpec [IDENTIFIER] { /* Code here */ }

Declaration: TypeSpec Declarator { COMMA Declarator } SEMI { /* Code here */ }

TypeSpec: CHAR | INT | VOID | SHORT | DOUBLE { /* Code here */ }

Declarator: IDENTIFIER [ASSIGN Expr] { /* Code here */ }

Statement: [Expr] SEMI { /* Code here */ }
    | LBRACE { /* Code here */ }
    | LBRACE { /* Code here */ } RBRACE { /* Code here */ }
    | IF LPAR Expr RPAR Statement [ELSE Statement] { /* Code here */ }
    | WHILE LPAR Expr RPAR Statement { /* Code here */ }
    | RETURN [Expr] SEMI { /* Code here */ }

Expr: Expr (ASSIGN | COMMA) Expr { /* Code here */ }
    | Expr (PLUS | MINUS | MUL | DIV | MOD) Expr { /* Code here */ }
    | Expr (OR | AND | BITWISEAND | BITWISEOR | BITWISEXOR) Expr { /* Code here */ }
    | Expr (EQ | NE | LE | GE | LT | GT) Expr { /* Code here */ }
    | (PLUS | MINUS | NOT) Expr { /* Code here */ }
    | IDENTIFIER LPAR [Expr { COMMA Expr }] RPAR { /* Code here */ }
    | IDENTIFIER { /* Code here */ }
    | NATURAL { /* Code here */ }
    | CHRLIT { /* Code here */ }
    | DECIMAL { /* Code here */ }
    | LPAR Expr RPAR { /* Code here */ }

%%

int main() {
    yyparse();
    return 0;
}

int yywrap() {
    return 1;
}

int yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}
