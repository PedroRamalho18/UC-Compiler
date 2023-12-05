#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

struct symbol_list *symbol_table;

void check_declaration(struct node *function){

}

void check_funcDefinition(struct node *function) {
    struct node *child_0 = getchild(function, 0);
    struct node *child_1 = getchild(function, 1);
    struct node *child_2 = getchild(function, 2);
    if(search_symbol(symbol_table, child_1->token) == NULL) {
        insert_symbol(symbol_table, child_1->token, category_type(child_0->category), child_2);
    } else {
        printf("Function %s already declared\n", child_1->token);
        semantic_errors++;
    }
    //check_parameters(getchild(function, 1));
    //check_expression(getchild(function, 2));
}

void check_funcDeclaration(struct node *function) {
    
}

// semantic analysis begins here, with the AST root node
int check_program(struct node *program) {
    symbol_table = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    symbol_table->next = NULL;
    if (program == NULL) return semantic_errors;
    struct node_list *child = program->children;
    while((child = child->next) != NULL){
        switch(child->node->category){
            case FuncDefinition: check_funcDefinition(child->node);
            case FuncDeclaration: check_funcDeclaration(child->node);
            case Declaration: check_declaration(child->node);
            default: continue;
        }
    }
    return semantic_errors;
}

// insert a new symbol in the list, unless it is already there
struct symbol_list *insert_symbol(struct symbol_list *table, char *identifier, enum type type, struct node *node) {
    struct symbol_list *new = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    new->identifier = strdup(identifier);
    new->type = type;
    new->node = node;
    new->next = NULL;
    struct symbol_list *symbol = table;
    while(symbol != NULL) {
        if(symbol->next == NULL) {
            symbol->next = new;    /* insert new symbol at the tail of the list */
            break;
        } else if(strcmp(symbol->next->identifier, identifier) == 0) {
            free(new);
            return NULL;           /* return NULL if symbol is already inserted */
        }
        symbol = symbol->next;
    }
    return new;
}

// look up a symbol by its identifier
struct symbol_list *search_symbol(struct symbol_list *table, char *identifier) {
    struct symbol_list *symbol;
    for(symbol = table->next; symbol != NULL; symbol = symbol->next)
        if(strcmp(symbol->identifier, identifier) == 0)
            return symbol;
    return NULL;
}

void show_symbol_table() {
    printf("===== Global Symbol Table =====\n");
    struct symbol_list *symbol;
    for(symbol = symbol_table->next; symbol != NULL; symbol = symbol->next) {
        printf("%s %s(", symbol->identifier, type_name(symbol->type));
        if (symbol->node->children != NULL) {
            struct node_list *child = symbol->node->children;
            while((child = child->next) != NULL){
                if(child->next == NULL) printf("%s", type_name(category_type(child->node->children->next->node->category)));
                else printf("%s, ", type_name(category_type(child->node->children->next->node->category)));
            }
        }
        printf(")\n");
    }
}