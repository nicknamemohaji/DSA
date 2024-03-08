#include "structures.h"

void test_linked_list(t_node *nodes[COUNT]);

void test_linked_list(t_node *nodes[COUNT])
{
    // init
    t_list list;
    list.head = nodes[0];

    printf("add node check\n");
    for (int i=1; i<COUNT; i++)
        add_node_to_list(nodes[i], &list);
    print_list(&list);

    printf("non existent value check\n");
    t_node *node = search_list(0, &list);
    printf("node %p\n", node);
    printf("existent value check\n");
    node = search_list(nodes[COUNT / 2]->data, &list);
    printf("node %p -> data %d\n", node, node->data);

    printf("remove non existent node\n");
    printf("result: %s\n", delete_from_list((void *)0xFFFF, &list) ? "success": "false");
    printf("remove existent node\n");
    printf("result: %s\n", delete_from_list(node, &list) ? "success": "false");
    print_list(&list);

    printf("deleted node check\n");
    node = search_list(nodes[COUNT / 2]->data, &list);
    printf("node %p\n", node);
}
