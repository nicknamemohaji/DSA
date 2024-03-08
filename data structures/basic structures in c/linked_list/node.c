#include "structures.h"

t_node *new_node(int data);

/*
t_node *new_node: 새로운 노드를 동적 할당한다.
:param data: (int) 노드에 담길 정보 
:return: (t_node *) 할당된 노드의 포인터. 할당 실패시, STDERR에 에러 메시지를 출력하고 NULL을 반환한다.
*/
t_node *new_node(int data)
{
    // 새로운 노드를 동적 할당
    t_node *node = (t_node*) malloc(1 * sizeof(t_node));
    if (node == NULL)
    {
        perror(strerror(errno));
        return NULL;
    }

    // 할당된 노드에 정보를 저장
    node->data = data;
    node->next = NULL;
    node->data_ptr = NULL;
    return node;
}