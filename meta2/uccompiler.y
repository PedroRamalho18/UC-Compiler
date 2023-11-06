%{
#include <stdio.h>
%}

%token TYPE CHAR INT VOID SHORT DOUBLE IDENTIFIER NATURAL CHRLIT DECIMAL
%left ','         /* Define a precedência do operador COMMA (à esquerda) */
%left EQ NE       /* Define precedência e associatividade dos operadores relacionais */
%left '<' '>' LE GE
%left '+' '-'     /* Define precedência e associatividade dos operadores de adição/subtração */
%left '*' '/' '%' /* Define precedência e associatividade dos operadores de multiplicação/divisão */
%left OR          /* Define precedência e associatividade do operador OR */
%left AND         /* Define precedência e associatividade do operador AND */
%left '|'         /* Define precedência e associatividade do operador BITWISEOR */
%left '^'         /* Define precedência e associatividade do operador BITWISEXOR */
%left '&'         /* Define precedência e associatividade do operador BITWISEAND */
%right UNARY      /* Define precedência do operador unário (à direita) */
%left LPAR RPAR   /* Define precedência dos parênteses */

%%

Program: FunctionsAndDeclarations { /* Código aqui */ }

FunctionsAndDeclarations: FunctionDefinition { /* Código aqui */ }
                      | FunctionDeclaration { /* Código aqui */ }
                      | Declaration { /* Código aqui */ }
                      | FunctionsAndDeclarations FunctionDefinition { /* Código aqui */ }
                      | FunctionsAndDeclarations FunctionDeclaration { /* Código aqui */ }
                      | FunctionsAndDeclarations Declaration { /* Código aqui */ }

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody { /* Código aqui */ }

FunctionBody: LBRACE DeclarationsAndStatements RBRACE { /* Código aqui */ }

DeclarationsAndStatements: Statement DeclarationsAndStatements { /* Código aqui */ }
                       | Declaration DeclarationsAndStatements { /* Código aqui */ }
                       | Statement { /* Código aqui */ }
                       | Declaration { /* Código aqui */ }

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI { /* Código aqui */ }

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR { /* Código aqui */ }

ParameterList: ParameterDeclaration { ',' ParameterDeclaration } { /* Código aqui */ }

ParameterDeclaration: TypeSpec [IDENTIFIER] { /* Código aqui */ }

Declaration: TypeSpec Declarator { ',' Declarator } SEMI { /* Código aqui */ }

TypeSpec: CHAR | INT | VOID | SHORT | DOUBLE { /* Código aqui */ }

Declarator: IDENTIFIER [ASSIGN Expr] { /* Código aqui */ }

Statement: [Expr] SEMI { /* Código aqui */ }
         | LBRACE Statements RBRACE { /* Código aqui */ }
         | IF LPAR Expr RPAR Statement [ELSE Statement] { /* Código aqui */ }
         | WHILE LPAR Expr RPAR Statement { /* Código aqui */ }
         | RETURN [Expr] SEMI { /* Código aqui */ }

Statements: Statement Statements { /* Código aqui */ }
          | Statement { /* Código aqui */ }

Expr: Expr '=' Expr { /* Código aqui */ }
    | Expr ',' Expr { /* Código aqui */ }
    | Expr '+' Expr { /* Código aqui */ }
    | Expr '-' Expr { /* Código aqui */ }
    | Expr '*' Expr { /* Código aqui */ }
    | Expr '/' Expr { /* Código aqui */ }
    | Expr '%' Expr { /* Código aqui */ }
    | Expr OR Expr { /* Código aqui */ }
    | Expr AND Expr { /* Código aqui */ }
    | Expr '|' Expr { /* Código aqui */ }
    | Expr '^' Expr { /* Código aqui */ }
    | Expr '&' Expr { /* Código aqui */ }
    | UNARY Expr { /* Código aqui */ }
    | IDENTIFIER LPAR [Expr { ',' Expr }] RPAR { /* Código aqui */ }
    | IDENTIFIER { /* Código aqui */ }
    | NATURAL { /* Código aqui */ }
    | CHRLIT { /* Código aqui */ }
    | DECIMAL { /* Código aqui */ }
    | LPAR Expr RPAR { /* Código aqui */ }

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
