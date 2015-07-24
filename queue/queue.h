#pragma once

#undef NULL
#define NULL	(void*)0

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
	int		size;
} queue;

void queue_init(queue* q);
void queue_push(queue* q, node* nd);
node* queue_top(queue* q);
node* queue_pop(queue* q);
int queue_size(queue* q);

#ifdef __cplusplus
}
#endif
