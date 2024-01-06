#include "structures.h"

void test_linked_list(t_node *nodes[COUNT]);
void test_stack(t_node *nodes[COUNT]);
void test_queue(t_node *nodes[COUNT]);
void test_map(t_node *nodes[COUNT]);
void claer_nodes(t_node *nodes[COUNT]);

int main(void)
{
    srand(time(NULL));
    // init
    t_node *nodes[COUNT];
    for (int i=0; i<COUNT; i++)
    {
        int val;
        do {
            val = rand();
        } while (val == 0);
        nodes[i] = new_node(val);
    }

    printf("\n\n------- linked list test --------\n\n");
    test_linked_list(nodes);
    claer_nodes(nodes);

    printf("\n\n------- stack test --------\n\n");
    test_stack(nodes);
    claer_nodes(nodes);

    printf("\n\n------- queue test --------\n\n");
    test_queue(nodes);
    claer_nodes(nodes);

    printf("\n\n------- map test --------\n\n");
    test_map(nodes);
    claer_nodes(nodes);

    // free
    for (int i=0; i < COUNT; i++)
    {
        free(nodes[i]);
        nodes[i] = NULL;
    }
    return (0);
}

void claer_nodes(t_node *nodes[COUNT])
{
    for (int i=0; i < COUNT; i++)
        nodes[i]->next = NULL;
}

void test_stack(t_node *nodes[COUNT])
{
    // init
    t_stack stack;
    stack.size = 0;
    stack.head = NULL;
    stack.tail = NULL;

    printf("push one node\n");
    printf("result: %s\n", stack_push(nodes[0], &stack) ? "success": "false");
    print_stack(&stack);
    printf("push other nodes\n");
    for (int i=1; i < COUNT; i++)
        printf("result: %s\n", stack_push(nodes[i], &stack) ? "success": "false");
    print_stack(&stack);

    printf("fetch top\n");
    t_node *node = stack_top(&stack);
    printf("node %p -> data %d\n", node, node->data);

    printf("pop one\n");
    node = stack_pop(&stack);
    printf("node %p -> data %d\n", node, node->data);
    printf("fetch top\n");
    node = stack_top(&stack);
    printf("node %p -> data %d\n", node, node->data);
    print_stack(&stack);
    
    printf("pop more\n");
    for (int i=0; i < COUNT / 2; i++)
    {
        node = stack_pop(&stack);
        printf("popped node %p -> data %d\n", node, node->data);
    }
    print_stack(&stack);
}

void test_queue(t_node *nodes[COUNT])
{
    // init
    t_queue queue;
    queue.count = 0;
    queue.head = NULL;
    queue.tail = NULL;

    printf("add one node\n");
    printf("result: %s\n", add_to_queue(nodes[0], &queue) ? "success": "false");
    print_queue(&queue);
    printf("push other nodes\n");
    for (int i=1; i < COUNT; i++)
        printf("result: %s\n", add_to_queue(nodes[i], &queue) ? "success": "false");
    print_queue(&queue);

    printf("pop one\n");
    t_node *node = pop_queue(&queue);
    printf("node %p -> data %d\n", node, node->data);
    print_queue(&queue);
    
    printf("pop more\n");
    for (int i=0; i < COUNT / 2; i++)
    {
        node = pop_queue(&queue);
        printf("popped node %p -> data %d\n", node, node->data);
    }
    print_queue(&queue);
}

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

void test_map(t_node *nodes[COUNT])
{
    // init
    char *keys[10] = {
        "Lee",
        "Jang",
        "Kim",
        "Hwang",
        "Son",
        "Moon",
        "Jo",
        "Jeong",
        "Ko",
        "Choi"
    };
    t_map map;
    for (int i=0; i < MAP_SIZE; i++)
        map.array[i] = NULL;
    for (int i=0; i < COUNT; i++)
        nodes[i]->key = keys[i % 10];

    printf("hash check\n");
    printf("%s -> %d\n", keys[0], hash(keys[0]));
    printf("%s -> %d\n", keys[1], hash(keys[1]));

    printf("add map check\n");
    printf("result: %s\n", add_to_map(nodes[0], &map) ? "success": "false");
    print_map(&map);
    printf("add more nodes\n");
    for (int i=1; i < COUNT / 2; i++)
        printf("result: %s\n", add_to_map(nodes[i], &map) ? "success": "false");
    print_map(&map);

    printf("search map\n");
    t_node *node = search_map(keys[0], &map);
    printf("node %p -> data %d key %s\n", node, node->data, node->key);
    node = search_map(keys[COUNT / 2 + 1], &map);
    printf("result %s: node %p (not existing)\n", keys[COUNT / 2 + 1], node);
    
    printf("add more nodes\n");
    for (int i=COUNT / 2; i < COUNT; i++)
        printf("result: %s\n", add_to_map(nodes[i], &map) ? "success": "false");
    print_map(&map);

    printf("delete from map\n");
    for (int i=0; i < COUNT; i += 2)
        printf("result: %s\n", delete_from_map(keys[i], &map) ? "success": "false");
    print_map(&map);
}