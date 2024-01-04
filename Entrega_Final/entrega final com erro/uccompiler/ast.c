 /*Pedro Tiago Gomes Ramalho 2019248594
    André Rodrigues Costa Pinto 2021213497 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

extern struct symbol_list *global_symbol_table;
extern struct symbol_table_list *function_tables;
char *category_name[] = names;

// create a node of a given category with a given lexical symbol
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    new->brother = NULL;
    new->parent = NULL;
    return new;
}

// append a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) {
    if(parent == NULL || child == NULL)return;
    child->parent = parent;
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *children = parent->children;
    while(children->next != NULL)
        children = children->next;
    children->next = new;
    if(child->brother != NULL){
        addchild(parent,child->brother);
    }
}

void addbrother(struct node *existing_brother, struct node *new_brother) {
    if(existing_brother == NULL || new_brother == NULL) return;

    struct node *current = existing_brother;
    while(current->brother !=NULL){
        current=current->brother;
    }
    current->brother = new_brother;
}

// get a pointer to a specific child, numbered 0, 1, 2, ...
struct node *getchild(struct node *parent, int position) {
    struct node_list *children = parent->children;
    while((children = children->next) != NULL)
        if(position-- == 0)
            return children->node;
    return NULL;
}

char *getnodeType(struct node *node){
    char *variavel_tipo = NULL;
    //verifica se é decimal natural chrlit ou identifier
    if(node->category != Identifier){
        //printf("\n\n%s\n\n", category_name[node->category]);
        switch (node->category){
            case Natural:
                variavel_tipo = "int";
                break;
            
            case Decimal:
                variavel_tipo = "double";
                break;
            
            case ChrLit:
                variavel_tipo = "int";
                break;
            
            default:
                //printf("\n\ndefal\n\n");
                variavel_tipo = "undef";
                break;
        }
        return variavel_tipo;
    }else{
        //nome da função ou declaração em que a variavel foi definida
        struct node *node_parent = node;
        while ((node_parent = node_parent->parent) != NULL)
            if((node_parent->category == FuncDeclaration) || (node_parent->category == FuncDefinition)) break;
        char *func_name = getchild(node_parent, 1)->token;

        //percorre as tabelas de simbolos até encontrar a variavel
        struct symbol_table_list *table;
        for(table = function_tables->next; table != NULL; table = table->next) {
            if(strcmp(func_name, table->name) == 0){
                struct symbol_list *simbolo;
                for(simbolo = table->table->next; simbolo != NULL; simbolo = simbolo->next)
                    if(strcmp(simbolo->identifier, node->token) == 0){
                        variavel_tipo = type_name(simbolo->type);
                        break;
                    }
            }
        }
        if(variavel_tipo == NULL){
            struct symbol_list *symbol;
            for(symbol = global_symbol_table->next; symbol != NULL; symbol = symbol->next){
                if(strcmp(symbol->identifier, node->token) == 0){
                    variavel_tipo = type_name(symbol->type);
                    if (symbol->node != NULL){
                        char *params_variavel = (char*) malloc(sizeof(char)*100);
                        strcat(params_variavel, variavel_tipo);
                        strcat(params_variavel, "(");
                        if (symbol->node->children != NULL) {
                            struct node_list *child = symbol->node->children;
                            while((child = child->next) != NULL){
                                if(child->next == NULL) strcat(params_variavel, type_name(category_type(child->node->children->next->node->category)));
                                else{
                                    strcat(params_variavel, type_name(category_type(child->node->children->next->node->category)));
                                    strcat(params_variavel, ",");
                                }
                            }
                        }
                        strcat(params_variavel, ")");
                        return params_variavel;
                    }
                }
            }
        }else return variavel_tipo;
        if(variavel_tipo == NULL) return "undef";
        return variavel_tipo;
    }
}

// get number of children of a specific node
int countchildren(struct node *node) {
    int cont = 0;
    struct node_list *children = node->children;
    while((children = children->next) != NULL)
        cont++;
    return cont;
}

// traverse the AST and print its content
void show(struct node *node, int depth) {
    if(node->category != Expr){
        int i;
        for(i = 0; i < depth; i++)
            printf("..");
        if(node->token == NULL)
            printf("%s\n", category_name[node->category]);
        else
            printf("%s(%s)\n", category_name[node->category], node->token);
        struct node_list *child = node->children;
        while((child = child->next) != NULL)
            show(child->node, depth+1);
    }
}

void show_all(struct node *node, int depth) {
    if(node->category != Expr){
        int i;
        for(i = 0; i < depth; i++)
            printf("..");
        if(node->token == NULL){
            printf("%s", category_name[node->category]);
            if((node->children->next != NULL)&&(getchild(node, 0)->category == Expr)){
                char *variavel_tipo = "undef";

                switch (node->category){
                    case Mul:
                    case Sub:
                    case Div:
                    case Add:
                        //compara o tipo do segundo e o terceiro filho pois o primeiro filho é nó Expr
                        char *chid1 = getnodeType(getchild(node, 1));
                        char *child2 = getnodeType(getchild(node, 2));
                        if((strcmp(chid1, "double") != 0)||(strcmp(chid1, "int") != 0)||(strcmp(chid1, "short") != 0)||(strcmp(chid1, "char") != 0)) chid1 = "undef";
                        if((strcmp(child2, "double") != 0)||(strcmp(child2, "int") != 0)||(strcmp(child2, "short") != 0)||(strcmp(child2, "char") != 0)) child2 = "undef";
                        if((strcmp(chid1, "undef") == 0)||(strcmp(child2, "undef") == 0)){
                            //printf("\n\n1\n\n");
                            variavel_tipo = "undef";
                        }else if((strcmp(chid1, "void") == 0)||(strcmp(child2, "void") == 0)){
                            variavel_tipo = "undef";
                        }else if(strcmp(chid1, child2) == 0){
                            variavel_tipo = chid1;
                        }else if((strcmp(chid1, "double") == 0)||(strcmp(child2, "double") == 0)){
                            variavel_tipo = "double";
                        }else if((strcmp(chid1, "int") == 0)||(strcmp(child2, "int") == 0)){
                            variavel_tipo = "int";
                        }else if((strcmp(chid1, "short") == 0)||(strcmp(child2, "short") == 0)){
                            variavel_tipo = "short";
                        }else if((strcmp(chid1, "char") == 0)||(strcmp(child2, "char") == 0)){
                            variavel_tipo = "char";
                        }
                        break;

                    case Comma:
                        variavel_tipo = getnodeType(getchild(node, countchildren(node)-1));
                        for(int i=0; i<strlen(variavel_tipo); i++){
                            if(variavel_tipo[i] == '('){
                                variavel_tipo[i] = '\0';
                                break;
                            }
                        }
                        if(strcmp(variavel_tipo, "void")==0) variavel_tipo = "undef";
                        break;
                    case Store:
                    case Call:
                        variavel_tipo = getnodeType(getchild(node, 1));
                        for(int i=0; i<strlen(variavel_tipo); i++){
                            if(variavel_tipo[i] == '('){
                                variavel_tipo[i] = '\0';
                                break;
                            }
                        }
                        if(strcmp(variavel_tipo, "void")==0) variavel_tipo = "undef";
                        break;

                    case Plus:
                    case Minus:
                    case Not:
                    case Eq:
                    case Ne:
                    case Le:
                    case Ge:
                    case Lt:
                    case Gt:
                        variavel_tipo = "int";
                        break;
                    default:
                        break;
                }
                printf(" - %s", variavel_tipo);
            }
            printf("\n");
        }else{
            printf("%s(%s)", category_name[node->category], node->token);
            if((node->children->next != NULL)&&(getchild(node, 0)->category == Expr)){
                printf(" - %s", getnodeType(node));

            }
            printf("\n");
        }
        struct node_list *child = node->children;
        while((child = child->next) != NULL)
            show_all(child->node, depth+1);
    }
}

// free the AST
void deallocate(struct node *node) {
    if(node != NULL) {
        struct node_list *child = node->children;
        while(child != NULL) {
            deallocate(child->node);
            struct node_list *tmp = child;
            child = child->next;
            free(tmp);
        }
        if(node->token != NULL)
            free(node->token);
        free(node);
    }
}
