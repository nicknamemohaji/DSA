#include "structures.h"

t_node *stack_top(t_stack *stack);
bool stack_push(t_node *node, t_stack *stack);
t_node *stack_pop(t_stack *stack);
void print_stack(t_stack *stack);

/*
stack_push: 스택에 노드를 push한다.
:param node: (t_node *) 추가할 노드
:param stack: (t_stack *) 스택의 포인터
:return: (bool) push 결과
*/
bool stack_push(t_node *node, t_stack *stack)
{
    if (node == NULL || stack == NULL)
        return false;

    // 스택 크기가 0인 경우에 대해 예외처리
    if (stack->size == 0)
    {
        stack->head = node;
        stack->tail = node;
        stack->size++;
        return true;
    }
    (stack->tail)->next = node;
    stack->tail = node;
    stack->size++;
    return true;
}

/*
stack_pop: 스택에서 노드를 pop한다.
:param stack: (t_stack *) 스택의 포인터
:return: (t_node *) 노드의 포인터. 스택이 NULL 포인터이거나, 크기가 0이면 NULL을 반환한다.
*/
t_node *stack_pop(t_stack *stack)
{
    if (stack == NULL || stack->size == 0)
        return (NULL);

    // 스택 크기가 1인 경우에 대해 예외처리
    if (stack->size == 1)
    {
        t_node *node = stack->head;
        stack->head = NULL;
        stack->tail = NULL;
        stack->size--;
        return (node);
    }
    t_node *prev_node = stack->head, *node = stack->tail;
    while (prev_node->next != stack->tail)
        prev_node = prev_node->next;
    prev_node->next = NULL;
    stack->tail = prev_node;
    stack->size--;
    return (node);
}

/*
stack_top: 스택 가장 위에 있는 노드를 반환한다.
:param stack: (t_stack *) 스택의 포인터
:return: (t_node *) 노드의 포인터. 스택이 NULL 포인터이거나, 크기가 0이면 NULL을 반환한다.
*/
t_node *stack_top(t_stack *stack)
{
    if (stack == NULL || stack->size == 0)
        return (NULL);
    return (stack->tail);
}

/*
print_stack: 스택의 내용을 출력한다.
:param stack: (t_stack *) 스택의 포인터
*/
void print_stack(t_stack *stack)
{
    printf("--- top ---\n");
    printf("size %d\n", stack->size);

    t_node *nodes[stack->size], *node = stack->head;

    for (int i=0; node != NULL; i++)
    {
        nodes[i] = node;
        node = node->next;
    }
    for (int i=0; i < stack->size; i++)
        printf("\t%d\t---\t%d\n", i + 1, nodes[stack->size - 1 - i]->data);

    printf("--- bottom ---\n");
}