#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

// create a node of a given category with a given lexical symbol
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    return new;
}

// append a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) {
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *children = parent->children;
    while(children->next != NULL)
        children = children->next;
    children->next = new;
}

// append a node to the list of brothers of the given node
void addbrother(struct node *node, struct node *brother) {
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = brother;
    new->next = NULL;
    struct node_list *brothers = node->children;
    while(brothers->next != NULL)
        brothers = brothers->next;
    brothers->next = new;
}

void print_tabs(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
}

void show(struct node *node, int depth) {
    if (node == NULL) {
        return;
    }

    print_tabs(depth);
    printf("Category: %d, Token: %s\n", node->category, node->token);

    struct node_list *children = node->children;
    while (children != NULL) {
        show(children->node, depth + 1);
        children = children->next;
    }
}