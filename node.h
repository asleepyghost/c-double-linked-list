#ifndef NODE_H
#define NODE_H

#include "common.h"

typedef struct Node Node;

struct Node
{
    const char *value;
    Node *next;
    Node *previous;
};

Node *create_node(const char *value);
void print_node(Node *node, int number);

#endif