#include "structures.h"

void test_map(t_node *nodes[COUNT]);

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
        nodes[i]->data_ptr = keys[i % 10];

    printf("hash check\n");
    printf("%s -> %d\n", keys[0], hash(keys[0]));
    printf("%s -> %d\n", keys[1], hash(keys[1]));

    printf("add map check\n");
    printf("result: %s\n", add_to_map(nodes[0], &map) ? "success": "false");
    print_map(&map);
    printf("add more nodes\n");
    for (int i=1; i < COUNT / 2; i++)
        printf("result: %s\n", add_to_map(nodes[i % 10], &map) ? "success": "false");
    print_map(&map);

    printf("search map\n");
    t_node *node = search_map(keys[0], &map);
    printf("node %p -> data %d key %s\n", node, node->data, (char *)node->data_ptr);
    node = search_map(keys[(COUNT / 2 + 1) % 10], &map);
    printf("result %s: node %p (not existing)\n", keys[(COUNT / 2 + 1) % 10], node);
    
    printf("add more nodes\n");
    for (int i=COUNT / 2; i < COUNT; i++)
        printf("result: %s\n", add_to_map(nodes[i], &map) ? "success": "false");
    print_map(&map);

    printf("delete from map\n");
    for (int i=0; i < COUNT; i += 2)
        printf("result: %s\n", delete_from_map(keys[i % 10], &map) ? "success": "false");
    print_map(&map);
}