#include "structures.h"

void test_tree(t_node *nodes[COUNT]);

void test_tree(t_node *nodes[COUNT])
{
    // init
    t_tree tree;
    tree.node = nodes[0];
    tree.left = NULL;
    tree.right = NULL;

    printf("add node check\n");
    for (int i=1; i<COUNT; i++)
        add_to_tree(nodes[i], &tree);
    print_tree(&tree);

    printf("---- btree search ----\n");
    printf("non existent value check\n");
    t_node *node = btree_search(0, &tree);
    printf("node %p\n", node);
    printf("existent value check\n");
    node = btree_search(nodes[rand() % COUNT]->data, &tree);
    printf("node %p -> data %d\n", node, node->data);
    printf("---- inorder search ----\n");
    printf("non existent value check\n");
    node = tree_search_inorder(0, &tree);
    printf("node %p\n", node);
    printf("existent value check\n");
    node = tree_search_inorder(nodes[rand() % COUNT]->data, &tree);
    printf("node %p -> data %d\n", node, node->data);
    printf("---- postorder search ----\n");
    printf("non existent value check\n");
    node = tree_search_postorder(0, &tree);
    printf("node %p\n", node);
    printf("existent value check\n");
    node = tree_search_postorder(nodes[rand() % COUNT]->data, &tree);
    printf("node %p -> data %d\n", node, node->data);
    printf("---- preorder search ----\n");
    printf("non existent value check\n");
    node = tree_search_preorder(0, &tree);
    printf("node %p\n", node);
    printf("existent value check\n");
    node = tree_search_preorder(nodes[rand() % COUNT]->data, &tree);
    printf("node %p -> data %d\n", node, node->data);

    printf("remove existent node\n");
    printf("result: %s\n", delete_from_btree(nodes[1], &tree) ? "success": "false");
    printf("remove non existent node\n");
    printf("result: %s\n", delete_from_btree(nodes[1], &tree) ? "success": "false");
    print_tree(&tree);

    // free tree using postorder traversal
    if (tree.left != NULL)
        free_tree(tree.left);
    if (tree.right != NULL)
        free_tree(tree.right);
}
