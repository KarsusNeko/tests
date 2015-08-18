#ifndef __QUEUE_H
#define __QUEUE_H

//#undef NULL
//#define NULL	(void*)0

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _node {
	struct node *next;
} node;

typedef struct _queue {
	node*	head;
	node*	tail;
} queue;

void queue_init(queue* q);
void queue_deinit(queue* q);
void queue_push(queue* q, node* nd);
node* queue_top(queue* q);
node* queue_pop(queue* q);

#ifdef __cplusplus
}
#endif

#endif // __QUEUE_H