#include "structures.h"

t_node *new_node(int data);
t_node *search_list(int data, t_list *list);
bool add_node_to_list(t_node *new, t_list *list);
bool delete_from_list(t_node *node, t_list *list);
void print_list(t_list *list);


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
    return node;
}

/*
t_node *search_list: 리스트에서 주어진 정보와 일치하는 노드를 찾는다.
:param data: (int) 찾고자 하는 노드의 정보
:param list: (t_list *) 리스트의 포인터
:return: (t_node *) 찾은 노드의 포인터. 리스트에 해당 노드가 없으면 NULL을 반환한다.
*/
t_node *search_list(int data, t_list *list)
{
    if (list == NULL)
        return NULL;

    // 리스트의 첫 노드(head) 부터 시작
    t_node *node = list->head;
    // 리스트의 끝 노드(tail) 까지 탐색
    while (node != NULL)
    {
        // 노드를 찾았으면 포인터를 반환
        if (node->data == data)
            return node;
        // 찾지 못했으면 다음 노드를 탐색
        node = node->next;
    }
    // 노드의 끝까지 찾지 못했으면 NULL 포인터를 반환
    return NULL;
}

/*
bool add_node_to_list: 리스트의 끝(=tail)에 새로운 노드를 추가한다.
:param data: (t_node *) 새로운 리스트에 추가할 노드의 포인터
:param list: (t_list *) 리스트의 포인터
:return: (bool) 실행 결과

노드나 리스트가 NULL포인터면 실패하지만, 그 외의 경우에는 성공한다.
*/
bool add_node_to_list(t_node *new, t_list *list)
{
    if (list == NULL || new == NULL)
        return false;

    t_node *node = list->head;
    // head가 없는 경우에 대해 예외 처리
    if (node == NULL)
    {
        list->head = new;
        return true;
    }

    // 리스트의 끝(tail)으로 이동
    while (node->next != NULL)
        node = node->next;
    // 새로운 노드를 연결
    node->next = new;
    return true;
}

/*
bool delete_from_list: 리스트에서 노드를 제거한다.
:param data: (t_node *) 리스트에서 제거할 노드의 포인터
:param list: (t_list *) 리스트의 포인터
:return: (bool) 실행 결과

1) 노드나 리스트가 NULL포인터면 실패하고
2) 리스트에 제거하려는 노드가 없으면 실패한다
그 외의 경우에는 성공한다.

노드를 할당 해제하지 않는 것에 주의.
*/
bool delete_from_list(t_node *node, t_list *list)
{
    if (list == NULL || node == NULL)
        return false;

    t_node *prev_node = list->head;
    // head를 제거하는 경우에 대해 예외 처리
    if (node == prev_node)
    {
        list->head = node->next;
        return true;
    }

    // tail까지 이동하면서, 제거하려고 하는 노드를 가리키고 있는지 확인
    while (prev_node != NULL)
    {
        // 만약 제거하려고 하는 노드를 가리키고 있다면 리스트에서 노드 제거
        if (prev_node->next == node)
        {
            prev_node->next = node->next;
            return true;
        }

        // 아니면 계속 탐색
        prev_node = prev_node->next;
    }
    return false;
}

/*
void print_list: 리스트 전체를 출력한다.
:param list: (t_list *) 리스트의 포인터
*/
void print_list(t_list *list)
{
    printf("--- start ---\n");
    if (list == NULL)
        return ;

    int i = 1;
    t_node *node = list->head;
    while (node != NULL)
    {
        printf("\t%d\t:\t%d\n", i++, node->data);
        node = node->next;
    }
    printf("--- end ---\n");
}
