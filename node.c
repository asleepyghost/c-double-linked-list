#include "node.h"

Node *create_node(const char *value)
{
    Node *node = malloc(sizeof(Node));

    node->next = NULL;
    node->previous = NULL;
    node->value = value;

    return node;
}

void print_node(Node *node, int number)
{
    printf("--------\n");
    printf("Node number: %d", number);
    printf("Node value: %s", node->value);
    printf("--------\n");
}
