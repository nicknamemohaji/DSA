#include "structures.h"

bool add_to_tree(t_node *node, t_tree *tree);
t_node *search_from_tree(int data, t_tree *tree);
bool delete_from_tree(t_node *node, t_tree *tree);
void print_tree(t_tree *tree);
static void print_tree_dfs(int depth, t_tree *tree);

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
    t_tree *parent = tree;
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
        else if ((tree->node)->data < data)
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
    if (search_from_tree(node->data, tree) == NULL)
        return false;
    
    // 삭제할 노드를 찾는다
    t_tree *parent = tree;
    t_tree *target = NULL;
    while (parent != NULL)
    {
        if ((parent->node)->data == node->data)
        {
            target = parent;
            break;
        }
        else 
            tree = parent;
        
        if ((parent->node)->data < node->data)
            parent = parent->left;
        else
            parent = parent->right;
    }
    if (target == NULL)
        return false;
    
    // target이 leaf 노드인 경우: target을 삭제하고 부모 노드의 자식 노드를 NULL로 설정
    if (target->left == NULL && target->right == NULL)
    {
        if (tree->left == target)
            tree->left = NULL;
        else
            tree->right = NULL;
        free(target);
        return true;
    }
    // target이 자식 노드를 한 개 가지고 있는 경우: target을 삭제하고 부모 노드의 자식 노드를 target의 자식 노드로 설정
    else if (target->left == NULL || target->right == NULL)
    {
        t_tree *child = NULL;
        if (target->left != NULL)
            child = target->left;
        else
            child = target->right;
        
        if (tree->left == target)
            tree->left = child;
        else
            tree->right = child;
        free(target);
        return true;
    }
    // target이 자식 노드를 두 개 가지고 있는 경우
    else
    {
        // target의 오른쪽 서브트리에서 가장 작은 노드를 찾는다
        t_tree *right_min = target->right;
        while (right_min->left != NULL)
            right_min = right_min->left;
        
        // 찾은 가장 작은 노드의 left 노드에 target의 left 노드를 연결한다
        // (target의 left 노드는 target보다 작은 값이므로 right_min의 left 노드로 연결해도 BST의 성질을 만족한다)
        right_min->left = target->left;
        if (tree->left == target)
            tree->left = target->right;
        else
            tree->right = target->right;
        
        free(target);
        return true;
    }
}

void print_tree(t_tree *tree)
{
    if (tree == NULL)
        return;
    else
        print_tree_dfs(0, tree);
}

static void print_tree_dfs(int depth, t_tree *tree)
{
    if (tree == NULL)
        return;
    
    for (int i = 0; i < depth; i++)
        printf("  ");
    printf("%d\n", (tree->node)->data);
    print_tree_dfs(depth + 1, tree->left);
    print_tree_dfs(depth + 1, tree->right);
}