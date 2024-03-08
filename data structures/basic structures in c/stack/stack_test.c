#include "structures.h"

void test_stack(t_node *nodes[COUNT]);

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
