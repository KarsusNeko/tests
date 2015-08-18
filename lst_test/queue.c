#include "queue.h"

#ifdef __cplusplus
extern "C"
{
#endif

void queue_init(queue* q)
{
	q->head	= NULL;
	q->tail	= NULL;

	q->size	= 0;
}

void queue_deinit(queue* q)
{
	while(!queue_pop(q));
}

void queue_push(queue* q, node* nd)
{
	nd->next = NULL;
	if (q->tail	!= NULL)
		q->tail->next = nd;
	q->tail = nd;

	if (q->head == NULL)
		q->head = nd;
}

node* queue_pop(queue* q)
{
	node*	tmp;
	
	tmp = q->head;
	if (q->head != NULL)
		q->head = q->head->next;

	return tmp;
}

node* queue_top(queue* q)
{
	return q->head;
}

#ifdef __cplusplus
}
#endif
