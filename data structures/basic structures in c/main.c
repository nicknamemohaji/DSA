#include "structures.h"

static void clear_nodes(t_node *nodes[COUNT]);

int main(void)
{
    // init
    srand(time(NULL));
    t_node *nodes[COUNT];
    for (int i=0; i<COUNT; i++)
    {
        int val;
        do {
            val = rand() % 100;
        } while (val == 0);
        nodes[i] = new_node(val);
    }

    char *tests[] = {
        "linked_list",
        "stack",
        "queue",
        "map",
        "tree"
    };
    void (*test_funcs[])(t_node *[]) = {
        test_linked_list,
        test_stack,
        test_queue,
        test_map,
        test_tree
    };

    char c;
    for (int i=0; i < (int) (sizeof(tests)/sizeof(char *)); i++)
    {
        printf("\n\n------- %s test --------\n\n", tests[i]);
        printf("do test? (y/n): ");
        while ((c = getchar()) != 'y' && c != 'n') {printf("do test? (y/n): ");}

        if (c != 'y')
            continue;
        test_funcs[i](nodes);
        clear_nodes(nodes);
    }

    // free
    for (int i=0; i < COUNT; i++)
    {
        free(nodes[i]);
        nodes[i] = NULL;
    }
    
    return (0);
}

static void clear_nodes(t_node *nodes[COUNT])
{
    for (int i=0; i < COUNT; i++)
        nodes[i]->next = NULL;
}
