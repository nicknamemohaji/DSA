#include "structures.h"

void test_linked_list(void);
void test_stack(void);

int main(void)
{
    srand(time(NULL));

    printf("\n\n------- linked list test --------\n\n");
    test_linked_list();

    printf("\n\n------- stack test --------\n\n");
    test_stack();

    return (0);
}

void test_stack(void)
{
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

    // free
    for (int i=0; i < COUNT; i++)
    {
        free(nodes[i]);
        nodes[i] = NULL;
    }
}

void test_linked_list(void)
{
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

    // free
    for (int i=0; i<COUNT; i++)
    {
        free(nodes[i]);
        nodes[i] = NULL;
    }
}