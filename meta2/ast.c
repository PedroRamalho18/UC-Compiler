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
    new->brother = NULL;
    return new;
}

// append a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) {
     if(parent == NULL || child == NULL)return;
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    //new->child = NULL;
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


char *category_name[] = names;

// traverse the AST and print its content
void show(struct node *node, int depth) {
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
