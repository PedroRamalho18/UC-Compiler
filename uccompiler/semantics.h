#ifndef _SEMANTICS_H
#define _SEMANTICS_H

#include "ast.h"

int check_program(struct node *program);

struct symbol_list {
	char *identifier;
	enum type type;
	struct node *node;
	struct symbol_list *next;
};

struct symbol_table_list {
	char *name;
	struct symbol_list *table;
	struct symbol_table_list *next;
};

struct symbol_list *insert_symbol(struct symbol_list *symbol_table, char *identifier, enum type type, struct node *node);
struct symbol_list *search_symbol(struct symbol_list *symbol_table, char *identifier);
struct symbol_table_list *search_table(struct symbol_table_list *table_list, char *identifier);

void show_symbol_table();

#endif