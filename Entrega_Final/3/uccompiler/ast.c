 /*Pedro Tiago Gomes Ramalho 2019248594
    André Rodrigues Costa Pinto 2021213497 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

extern struct symbol_list *global_symbol_table;
extern struct symbol_table_list *function_tables;

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

char *category_name[] = names;

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
            if(((node->children->next != NULL)&&(getchild(node, 0)->category == Expr))||((node->parent != NULL)&&((node->parent->category == Call)||(node->parent->category == Return)))){
                //nome da função ou declaração em que a variavel foi definida
                struct node *node_parent = node->parent;
                while ((node_parent = node_parent->parent) != NULL)
                    if((node_parent->category == FuncDeclaration) || (node_parent->category == FuncDefinition) || (node_parent->category == Declaration)) break;
                char *func_name = getchild(node_parent, 1)->token;

                struct symbol_list *symbol;
                for(symbol = global_symbol_table->next; symbol != NULL; symbol = symbol->next){
                    if(strcmp(symbol->identifier, func_name) == 0){
                        printf(" - %s", type_name(symbol->type));
                    }
                }
            }
            printf("\n");
        }else{
            printf("%s(%s)", category_name[node->category], node->token);
            if(((node->children->next != NULL)&&(getchild(node, 0)->category == Expr))||(node->parent->category == Call)||(node->parent->category == Return)){
                char *variavel_tipo = NULL;
                //nome da função ou declaração em que a variavel foi definida
                struct node *node_parent = node->parent;
                while ((node_parent = node_parent->parent) != NULL)
                    if((node_parent->category == FuncDeclaration) || (node_parent->category == FuncDefinition) || (node_parent->category == Declaration)) break;
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
                            printf(" - %s", variavel_tipo);
                            if (symbol->node != NULL){
                                printf("(");
                                if (symbol->node->children != NULL) {
                                    struct node_list *child = symbol->node->children;
                                    while((child = child->next) != NULL){
                                        if(child->next == NULL) printf("%s", type_name(category_type(child->node->children->next->node->category)));
                                        else printf("%s,", type_name(category_type(child->node->children->next->node->category)));
                                    }
                                }
                                printf(")");
                            }
                            break;
                        }
                    }
                }else printf(" - %s", variavel_tipo);

                if(variavel_tipo == NULL) printf(" - int");
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