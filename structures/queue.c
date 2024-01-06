#include "structures.h"

bool add_to_queue(t_node *node, t_queue *queue);
t_node *pop_queue(t_queue *queue);
void print_queue(t_queue *queue);

/*
bool add_to_queue(t_queue *queue, t_node *node): 큐에 노드를 추가
:param queue: (t_queue *) 큐의 포인터
:param node: (t_node *) 노드의 포인터
:return: (bool) 실행 결과
*/
bool add_to_queue(t_node *node, t_queue *queue)
{
    if (queue == NULL)
        return false;
    queue->count++;

    // head가 없는 경우에 대해 예외 처리
	if (queue->head == NULL)
	{
		queue->head = node;
		queue->tail = node;
		return true;
	}

	(queue->tail)->next = node;
	queue->tail = node;
	return true;
}

/*
t_node *pop_queue
:param queue: (t_queue *) 큐의 포인터
:return: (t_node *) 노드의 포인터. 큐에 아무것도 없으면 NULL 반환
*/
t_node	*pop_queue(t_queue *queue)
{
    if (queue == NULL)
        return (NULL);
    if (queue->count == 0)
		return (NULL);

	queue->count--;
	t_node	*node = queue->head;
	if (queue->count == 0)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
        queue->head = node->next; 
    return (node);
}

void print_queue(t_queue *queue)
{
    if (queue == NULL)
        return ;
    printf("--- start ---\n");

    t_node *node = queue->head;
    for (int i=0; i < queue->count; i++)
    {
        printf("\t%d\t:\t%d\n", i + 1, node->data);
        node = node->next;
    }
    printf("--- end ---\n");
}
