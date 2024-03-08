#include "structures.h"

void test_queue(t_node *nodes[COUNT]);

void test_queue(t_node *nodes[COUNT])
{
    // init
    t_queue queue;
    queue.count = 0;
    queue.head = NULL;
    queue.tail = NULL;

    printf("add one node\n");
    printf("result: %s\n", enqueue(nodes[0], &queue) ? "success": "false");
    print_queue(&queue);
    printf("push other nodes\n");
    for (int i=1; i < COUNT; i++)
        printf("result: %s\n", enqueue(nodes[i], &queue) ? "success": "false");
    print_queue(&queue);

    printf("pop one\n");
    t_node *node = dequeue(&queue);
    printf("node %p -> data %d\n", node, node->data);
    print_queue(&queue);
    
    printf("pop more\n");
    for (int i=0; i < COUNT / 2; i++)
    {
        node = dequeue(&queue);
        printf("popped node %p -> data %d\n", node, node->data);
    }
    print_queue(&queue);
}
