/*Pedro Tiago Gomes Ramalho 2019248594
    AndrÃ© Rodrigues Costa Pinto 2021213497 */
#ifndef _AST_H
#define _AST_H


enum category { Program, Declaration, FuncDeclaration, FuncDefinition, ParamList, FuncBody, ParamDeclaration, Statements, StatList, If, While, Return, Or, And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Store, Comma, Call, BitWiseAnd, BitWiseXor, BitWiseOr, Terminais, Char, ChrLit, Identifier, Int, Short, Natural, Double, Decimal, Void,Error,Null,AuxNode};
#define names {"Program", "Declaration", "FuncDeclaration", "FuncDefinition", "ParamList", "FuncBody", "ParamDeclaration", "Statements", "StatList", "If", "While", "Return", "Or", "And", "Eq", "Ne", "Lt", "Gt", "Le", "Ge", "Add", "Sub", "Mul", "Div", "Mod", "Not", "Minus", "Plus", "Store", "Comma", "Call", "BitWiseAnd", "BitWiseXor", "BitWiseOr", "Terminais", "Char", "ChrLit", "Identifier", "Int", "Short", "Natural", "Double", "Decimal", "Void", "Error","Null","AuxNode"}

enum type {integer_type, double_type, no_type};
#define type_name(type) (type == integer_type ? "integer" : (type == double_type ? "double" : ""))
#define category_type(category) (category == Int ? integer_type : (category == Double ? double_type : no_type))

struct node {
    enum category category;
    char *token;
    enum type type;
    struct node_list *children;
    struct node *brother;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};

struct node *newnode(enum category, char *token);
void addchild(struct node *parent, struct node *child);
void addbrother(struct node *existing_brother, struct node *new_brother);
struct node *getchild(struct node *parent, int position);
int countchildren(struct node *node);
void show(struct node *node, int depth);
void deallocate(struct node *node);

#endif