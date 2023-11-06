#ifndef _AST_H
#define _AST_H

enum category { program, FunctionsAndDeclarations, FunctionDefinition, FunctionBody, DeclarationsAndStatements, FunctionDeclaration, FunctionDeclarator, ParameterList, ParameterDeclaration, Declaration, Declarations, TypeSpec, Declarator, Statement, Statements, Expr, ExprList, RESERVED, NATURAL, IDENTIFIER, DECIMAL, CHRLIT, CHAR, ELSE, WHILE, IF, INT, SHORT, DOUBLE, RETURN, VOID, BITWISEAND, BITWISEOR, BITWISEXOR, AND, ASSIGN, MUL, COMMA, DIV, EQ, GE, GT, LBRACE, LE, LPAR, LT, MINUS, MOD, NE, NOT, OR, PLUS, RBRACE, RPAR, SEMI, IGNORE};

struct node {
    enum category category;
    char *token;
    struct node_list *children;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};



struct node *newnode(enum category category, char *token);
void addchild(struct node *parent, struct node *child);

#endif
