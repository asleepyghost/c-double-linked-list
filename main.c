#include "double_linked_list.h"
#include "common.h"

int main()
{
    ListHead *list_head = init_list_head();

    list_head->node_count = 0;

    Node *new_node = create_node("SENTINEL");

    add_node_to_end_of_list(list_head, new_node);

    Node *another_node = create_node("NODE ONE");

    add_node_to_end_of_list(list_head, another_node);

    Node *even_more_node = create_node("MIDDLE NODE");

    insert_into_list(list_head, even_more_node, 2);

    Node *even_more_more_node = create_node("FIRST MIDDLE NODE");

    insert_into_list(list_head, even_more_more_node, 2);

    printf("Before removal: \n");
    print_list(list_head);

    remove_node_at(list_head, 2);

    printf("After removal: \n");
    print_list(list_head);

    remove_node_at(list_head, 2);

    printf("After next removal: \n");
    print_list(list_head);

    Node *new_end_node = create_node("A NEW END NODE");

    add_node_to_end_of_list(list_head, new_end_node);

    printf("Now another addition at end: \n");
    print_list(list_head);

    remove_node_at(list_head, list_head->node_count);

    printf("Now a removal at the end: \n");
    print_list(list_head);

    remove_node_at(list_head, 1);

    printf("Now a removal at the start: \n");
    print_list(list_head);

    return 0;
}