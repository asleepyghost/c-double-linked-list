#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include "node.h"

typedef struct {
    int node_count;
    Node *entry;
} ListHead;

ListHead* init_list_head();

void add_node_to_end_of_list(ListHead *list_head, Node* node);
void insert_into_list(ListHead *list_head, Node* node, int position);
void print_list(ListHead *list_head);
void remove_node_at(ListHead *list_head, int position);

#endif