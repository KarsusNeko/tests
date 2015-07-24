#include "queue.h"
#include <string.h>
#include <stdio.h>

struct _work_queue {
	queue	que;
	char	q_name[10];
} work_queue;

typedef struct _work_node {
	node*	next;
	void*	data;
	void	(*do_something)();
} work_node;

void do_something_1()
{
	printf("doing work 1\n");
}

void do_something_2()
{
	printf("doing work 2\n");
}

int main(void)
{
	strcpy(work_queue.q_name, "baka test");
	queue_init(&work_queue.que);

	int wn_data_1 = 1;
	work_node work_1;
	work_1.data = (void*)wn_data_1;
	work_1.do_something = do_something_1;

	int wn_data_2 = 2;
	work_node work_2;
	work_2.data = (void *)wn_data_2;
	work_2.do_something = do_something_2;

	queue_push(&work_queue.que, (node*)&work_1);
	queue_push(&work_queue.que, (node*)&work_2);

	printf("push work 1 and work 2, queue size: %d\n", queue_size(&work_queue.que));
	((work_node*)queue_pop(&work_queue.que))->do_something();
	((work_node*)queue_pop(&work_queue.que))->do_something();
	printf("pop work 1 and work 2, queue size: %d\n", queue_size(&work_queue.que));

	return 0;
}
