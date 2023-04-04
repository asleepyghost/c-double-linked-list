#ifndef LIST_HEAD_H
#define LIST_HEAD_H

#include "node.h"

typedef struct {
    int number_nodes;
    Node entry;
} ListHead;

#endif