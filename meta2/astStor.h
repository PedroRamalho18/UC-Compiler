#ifndef _AST_H
#define _AST_H


enum category { Program, Declaration, FuncDeclaration, FuncDefinition, ParamList, FuncBody, ParamDeclaration, Statements, StatList, If, While, Return, Or, And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Store, Comma, Call, BitWiseAnd, BitWiseXor, BitWiseOr, Terminais, Char, ChrLit, Identifier, Int, Short, Natural, Double, Decimal, Void};

struct node {
    enum category category;
    char *token;
    int token_line, token_column;
    struct node_list *children;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};

struct node *newnode(enum category category, char *token);
void addchild(struct node *parent, struct node *child);
struct node *getchild(struct node *parent, int position);
int countchildren(struct node *node);
void show(struct node *root, int depth);
void deallocate(struct node *root);

#endif