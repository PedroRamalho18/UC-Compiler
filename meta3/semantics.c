#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

struct symbol_list *global_symbol_table;
struct symbol_table_list *function_tables;

void get_put_char(){
    struct node *get = malloc(sizeof(struct node));
    get->category = Void;

    struct node *put = malloc(sizeof(struct node));
    put->category = Int;

    struct node *put_paramDeclaration = malloc(sizeof(struct node));
    put_paramDeclaration->children = malloc(sizeof(struct node_list));
    addchild(put_paramDeclaration, put);
    
    struct node *get_paramDeclaration = malloc(sizeof(struct node));
    get_paramDeclaration->children = malloc(sizeof(struct node_list));
    addchild(get_paramDeclaration, get);

    struct node *put_paramList = malloc(sizeof(struct node));
    put_paramList->children = malloc(sizeof(struct node_list));
    addchild(put_paramList, put_paramDeclaration);

    struct node *get_paramList = malloc(sizeof(struct node));
    get_paramList->children = malloc(sizeof(struct node_list));
    addchild(get_paramList, get_paramDeclaration);

    insert_symbol(global_symbol_table, "putchar", integer_type, put_paramList);
    insert_symbol(global_symbol_table, "getchar", integer_type, get_paramList);
}

void check_declaration(struct node *function){
    struct node *child_0 = getchild(function, 0);
    struct node *child_1 = getchild(function, 1);
    if(search_symbol(global_symbol_table, child_1->token) == NULL) {
        insert_symbol(global_symbol_table, child_1->token, category_type(child_0->category), NULL);
    } else {
        //printf("Function %s already declared\n", child_1->token); //mudar nome do erro
        //semantic_errors++;
    }
}

void check_funcDefinition(struct node *function) {
    struct node *child_0 = getchild(function, 0);
    struct node *child_1 = getchild(function, 1);
    struct node *child_2 = getchild(function, 2);
    struct node *child_3 = getchild(function, 3);
    if(search_table(function_tables, child_1->token) == NULL) {
        if(search_symbol(global_symbol_table, child_1->token) == NULL) insert_symbol(global_symbol_table, child_1->token, category_type(child_0->category), child_2);

        //cria uma nova tabela função
        struct symbol_list *function_symbol_table = (struct symbol_list *) malloc(sizeof(struct symbol_list));
        function_symbol_table->next = NULL;
        insert_symbol(function_symbol_table, "return", category_type(child_0->category), function);
        struct node_list *param_child = child_2->children;
        while((param_child = param_child->next) != NULL){
            struct node *param = param_child->node;
            if(getchild(param, 1) != NULL){
                if(search_symbol(function_symbol_table, getchild(param, 1)->token) == NULL){
                    insert_symbol(function_symbol_table, getchild(param, 1)->token, category_type(getchild(param, 0)->category), child_2);
                } else {
                    //printf("Symbol %s already declared\n", getchild(param, 1)->token); //mudar nome do erro
                   // semantic_errors++;
                }
            }
        }
        struct node_list *body_child = child_3->children;
        while((body_child = body_child->next) != NULL){
            if(body_child->node->category == Declaration){
                struct node *declaration = body_child->node;
                if(search_symbol(function_symbol_table, getchild(declaration, 1)->token) == NULL){
                    insert_symbol(function_symbol_table, getchild(declaration, 1)->token, category_type(getchild(declaration, 0)->category), child_3);
                } else {
                    //printf("Symbol %s already declared\n", getchild(declaration, 1)->token); //mudar nome do erro
                    //semantic_errors++;
                }
            }
        }

        //adiciona a nova tabela função à struct das tabelas função
        struct symbol_table_list *new = (struct symbol_table_list*) malloc(sizeof(struct symbol_table_list));
        new->name = child_1->token;
        new->table = function_symbol_table;
        new->next = NULL;
        struct symbol_table_list *function_table = function_tables;
        while(function_table->next != NULL){
            function_table = function_table->next;
        }
        function_table->next = new;

    } else {
        //printf("Table function %s already declared\n", child_1->token); //mudar nome do erro
        //semantic_errors++;
    }
}

void check_funcDeclaration(struct node *function) {
    struct node *child_0 = getchild(function, 0);
    struct node *child_1 = getchild(function, 1);
    struct node *child_2 = getchild(function, 2);
    if(search_symbol(global_symbol_table, child_1->token) == NULL) {
        insert_symbol(global_symbol_table, child_1->token, category_type(child_0->category), child_2);
    } else {
        //printf("Function %s already declared\n", child_1->token); //mudar nome do erro
        //semantic_errors++;
    }
}

// semantic analysis begins here, with the AST root node
int check_program(struct node *program) {
    global_symbol_table = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    global_symbol_table->next = NULL;

    function_tables = (struct symbol_table_list *) malloc(sizeof(struct symbol_table_list));
    function_tables->next = NULL;

    get_put_char();
    if (program == NULL) return semantic_errors;
    struct node_list *child = program->children;
    while((child = child->next) != NULL){
        switch(child->node->category){
            case FuncDefinition:
                check_funcDefinition(child->node);
                break;
            case FuncDeclaration:
                check_funcDeclaration(child->node);
                break;
            case Declaration:
                check_declaration(child->node);
                break;
            default: break;
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

struct symbol_table_list *search_table(struct symbol_table_list *tables, char *identifier) {
    struct symbol_table_list *table;
    for(table = tables->next; table != NULL; table = table->next){
        if(strcmp(getchild(table->table->next->node, 1)->token, identifier) == 0) return table;
    }
    return NULL;
}

void show_symbol_table(){
    printf("===== Global Symbol Table =====\n");
    struct symbol_list *symbol;
    for(symbol = global_symbol_table->next; symbol != NULL; symbol = symbol->next) {
        printf("%s\t%s", symbol->identifier, type_name(symbol->type));
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
        printf("\n");
    }

    for(symbol = global_symbol_table->next; symbol != NULL; symbol = symbol->next) {
        struct symbol_table_list *table;
        for(table = function_tables->next; table != NULL; table = table->next) {
            char *nome_func = table->name;
            if(strcmp(symbol->identifier, nome_func) == 0){
                printf("\n");
                struct symbol_list *simbolo;
                for(simbolo = table->table->next; simbolo != NULL; simbolo = simbolo->next) {
                    switch (simbolo->node->category){
                    case FuncDefinition:
                        printf("===== Function %s Symbol Table =====\n", nome_func);
                        printf("%s\t%s\n", simbolo->identifier, type_name(simbolo->type));
                        break;
                    case FuncBody:
                        printf("%s\t%s\n", simbolo->identifier, type_name(simbolo->type));
                        break;
                    case ParamList:
                        printf("%s\t%s\tparam\n", simbolo->identifier, type_name(simbolo->type));
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
}
