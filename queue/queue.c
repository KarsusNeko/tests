#include "queue.h"

#ifdef __cplusplus
extern "C"
{
#endif

void queue_init(queue* q)
{
#if __cplusplus >= 201103L
	q->head	= nullptr;
	q->tail	= nullptr;
#else
	q->head	= NULL;
	q->tail	= NULL;
#endif
	q->size	= 0;
}

void queue_push(queue* q, node* nd)
{
#if __cplusplus >= 201103L
	nd->next = nullptr;
	if (q->tail != nullptr)
#else
	nd->next = NULL;
	if (q->tail	!= NULL)
#endif
		q->tail->next = nd;
	q->tail = nd;

#if __cplusplus >= 201103L
	if (q->head == nullptr)
#else
	if (q->head == NULL)
#endif
		q->head = nd;

	q->size++;
}

node* queue_pop(queue* q)
{
	node*	tmp;
	
	tmp = q->head;
#if __cplusplus > cplusplus >= 201103L
	if (q->head != nullptr)
#else
	if (q->head != NULL) {
#endif
		q->head = q->head->next;
		q->size--;
	}

	return tmp;
}

node* queue_top(queue* q)
{
	return q->head;
}

int queue_size(queue* q)
{
	return q->size;
}

#ifdef __cplusplus
}
#endif
