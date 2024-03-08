#include "structures.h"

t_node *tree_search_preorder(int data, t_tree *tree);
t_node *tree_search_postorder(int data, t_tree *tree);
t_node *tree_search_inorder(int data, t_tree *tree);
t_node *btree_search(int data, t_tree *tree);

/*
전위 순회 (preorder traversal)
- N -> L -> R
*/
t_node *tree_search_preorder(int data, t_tree *tree)
{
    if (tree == NULL)
        return NULL;

    // 루트 노드를 방문한다 (N)
    #ifdef DEBUG
    printf("%d ", tree->node->data);
    #endif
    if (tree->node->data == data)
        return tree->node;
    
    // 왼쪽 서브트리를 방문한다 (L)
    t_node *found = tree_search_preorder(data, tree->left);
    if (found != NULL)
        return found;
    
    // 오른쪽 서브트리를 방문한다 (R)
    return tree_search_preorder(data, tree->right);
}

/*
후위 순회 (postorder traversal)
- L -> R -> N
*/
t_node *tree_search_postorder(int data, t_tree *tree)
{
    if (tree == NULL)
        return NULL;

    // 왼쪽 서브트리를 방문한다 (L)
    t_node *found = tree_search_postorder(data, tree->left);
    if (found != NULL)
        return found;
    
    // 오른쪽 서브트리를 방문한다 (R)
    found = tree_search_postorder(data, tree->right);
    if (found != NULL)
        return found;

    // 루트 노드를 방문한다 (N)
    #ifdef DEBUG
    printf("%d ", tree->node->data);
    #endif
    if (tree->node->data == data)
        return tree->node;
    
    return NULL;
}

/*
중위 순회 (inorder traversal)
- L -> N -> R
*/
t_node *tree_search_inorder(int data, t_tree *tree)
{
    if (tree == NULL)
        return NULL;

    // 왼쪽 서브트리를 방문한다 (L)
    t_node *found = tree_search_inorder(data, tree->left);
    if (found != NULL)
        return found;

    // 루트 노드를 방문한다 (N)
    #ifdef DEBUG
    printf("%d ", tree->node->data);
    #endif
    if (tree->node->data == data)
        return tree->node;
    
    // 오른쪽 서브트리를 방문한다 (R)
    return tree_search_inorder(data, tree->right);
}

/*
Binary Search Tree (BST)에서 노드를 찾는다
*/
t_node *btree_search(int data, t_tree *tree)
{
    if (tree == NULL || tree->node == NULL)
        return (NULL);

    while (tree != NULL)
    {
        if ((tree->node)->data == data)
            return (tree->node);
        else if ((tree->node)->data < data)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return (NULL);
}
