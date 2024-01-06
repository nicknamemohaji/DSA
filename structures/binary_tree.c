#include "structures.h"

bool add_to_tree(t_node *node, t_tree *tree);
t_node *search_from_tree(int data, t_tree *tree);
bool delete_from_tree(t_node *node, t_tree *tree);
void print_tree(t_tree *tree);

/*
bool add_to_tree: 이진트리의 알맞은 위치에 노드를 추가
:param node: (t_node *) 트리에 추가할 노드의 포인터
:param tree: (t_tree *) 트리의 포인터
:return: (bool) 추가 결과
*/
bool add_to_tree(t_node *node, t_tree *tree)
{
    if (tree == NULL || node == NULL)
        return false;

    // 트리에 아무런 노드도 없는 경우에 대해 예외 처리
    if (tree->node == NULL)
    {
        tree->node = node;
        return true;
    }
    
    // 새로운 트리 노드를 할당
    t_tree *new_tree = (t_tree *)malloc(1 * sizeof(t_tree));
    if (new_tree == NULL)
    {
        perror(strerror(errno));
        return false;
    }
    new_tree->node = node;
    new_tree->left = NULL;
    new_tree->right = NULL;

    // 노드를 추가할 위치를 찾는다
    // 같은 값이 있다면 (트리 노드 말고 데이터 노드의) 연결리스트의 끝에 붙인다.
    t_node *parent = tree;
    for(;;)
    {
        if ((parent->node)->data == node->data)
        {
            t_node *prev = parent->node;
            while (prev->next != NULL)
                prev = prev->next;
            prev->next = node;
            free(new_tree);
            return true;
        }
        else if ((parent->node)->data < node->data)
        {   
            if (parent->left == NULL)
            {
                parent->left = new_tree;
                return true;
            }
            parent = parent->left;
        }
        else
        {
            if (parent->right == NULL)
            {
                parent->right = new_tree;
                return true;
            }
            parent = parent->right;
        }
    }
    
}

t_node *search_from_tree(int data, t_tree *tree)
{
    if (tree == NULL || tree->node == NULL)
        return (NULL);

    while (tree != NULL)
    {
        if ((tree->node)->data == data)
            return (tree->node);
        else if ((tree->ndoe)->data < data)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return (NULL);
}

bool delete_from_tree(t_node *node, t_tree *tree)
{
    if (node == NULL || tree == NULL)
        return false;

    t_node *prev_node = search_from_tree(node->data, tree);
    if (prev_node == NULL)
        return false;
    while (prev_node->next != NULL && prev_node != node)
        prev_node = prev_node->next;

    // 트리 노드 전체를 삭제하는 경우
    if (prev_node == tree->node)
    {
        // TODO
        return true;
    }
    // 연결리스트에서 일부만 삭제하는 경우
    prev_node->next = node->next;
    return true;
}