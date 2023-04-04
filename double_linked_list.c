#include "double_linked_list.h"

ListHead *init_list_head()
{
    ListHead *list_head = malloc(sizeof(ListHead));

    return list_head;
}

Node *find_end_node(Node *node)
{
    if (NULL == node->next)
    {
        return node;
    }

    return find_end_node(node->next);
}

void add_node_to_end_of_list(ListHead *list_head, Node *node)
{
    Node *start_node = list_head->entry;
    list_head->node_count++;

    if (NULL == start_node)
    {
        list_head->entry = node;
        return;
    }

    Node *end_node = find_end_node(start_node);

    node->previous = end_node;
    end_node->next = node;
}

Node *get_node_at(ListHead *list_head, int pos)
{
    Node *current_node = list_head->entry;
    int current_position = 1;

    while (current_position != pos)
    {
        current_node = current_node->next;
        current_position++;
    }

    return current_node;
}

void insert_into_list(ListHead *list_head, Node *node_to_insert, int position)
{
    int current_node_count = list_head->node_count;

    // If we try to go more than the places available, just stick it on the end.
    if (position > current_node_count)
    {
        add_node_to_end_of_list(list_head, node_to_insert);
        return;
    }

    Node *current_node = get_node_at(list_head, position);

    Node *old_previous = current_node->previous;

    current_node->previous = node_to_insert;
    old_previous->next = node_to_insert;

    node_to_insert->next = current_node;
    node_to_insert->previous = old_previous;

    list_head->node_count++;
}

void remove_node_at(ListHead *list_head, int position)
{
    if (position > list_head->node_count)
    {
        printf("Warning, you tried to remove a node from a position where a node doesn't exist.");
        return;
    }

    Node *node_to_remove = get_node_at(list_head, position);

    Node *previous_node = node_to_remove->previous;
    Node *next_node = node_to_remove->next;

    // I don't like that I have to remember to call free three times here, refactor this.

    // We are at end of list, so
    if (NULL == next_node)
    {
        previous_node->next = NULL;
        free(node_to_remove);
        return;
    }

    // We are at start of list, so
    if (NULL == previous_node)
    {
        next_node->previous = NULL;
        // update list head
        list_head->entry = next_node;
        free(node_to_remove);
        return;
    }

    previous_node->next = next_node;
    next_node->previous = previous_node;

    free(node_to_remove);

    list_head->node_count--;
}

void free_list_head(ListHead *list_head)
{
    // Free everything inside the list first?
    free(list_head);
}

void print_list(ListHead *list_head)
{
    Node *node = list_head->entry;
    int stop = false;
    int count = 0;

    printf("Node count: %d\n", list_head->node_count);

    while (stop != true)
    {
        printf("Node %d --> %s\n", count, node->value);

        if (node->next == NULL)
        {
            stop = 0;
            break;
        }

        node = node->next;
        count++;
    }
}