#include "timer_list.h"
#include <string.h>

int timer_cmp(list_node* ln1, list_node* ln2)
{
	timer* tm1;
	timer* tm2;

	tm1 = (timer*)ln1;
	tm2 = (timer*)ln2;

	return (strcmp(tm1->name, tm2->name));
}

void timer_list_init(timer_list* tl)
{
	list_init(tl);
}

timer*	timer_remove(timer_list* tl, char* name)
{
	timer	tmp;

	strcpy(tmp.name, name);

	return (timer*)list_remove(tl, &tmp, timer_cmp);
}

void timer_append(timer_list* tl, timer* timer)
{
	list_append(tl, timer);
}

void timer_list_clear(timer_list* tl)
{}
