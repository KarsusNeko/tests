#include "timer.h"
#include <string.h>

timer_list __tmr_lst;

int timer_create(timer* timer,
				const char* name,
				unsigned long tick,
				timer_handler hndlr,
				void* arg)
{
	if(tick < ticks)
		return -1;

	timer->ticks	= ticks;
	timer->task		= hndlr;
	timer->arg		= arg;
	strcpy(timer->name, name);
	
	return ticks;
}

void timer_register(timer* timer)
{
	timer_list_append(&__tmr_lst, timer);
}

void timer_unregister(char* name)
{
	timer_list_remove(&__tmr_lst, name);
}

void timer_init()
{
	timer_list_init(&__tmr_lst);
}

void timer_free()
{
	timer_list_clear(&__tmr_lst);
}

void timer_workflow()
{
	timer* curs;

	curs = (timer*)&__tmr_lst->head;

	while(curs != NULL)
	{
		if( curs->ticks <= ticks )
		{
			curs->task(curs->arg);
			curs = timer_list_remove(&__tmr_lst, curs);
		}
		else
		{
			curs = curs->next;
		}
	}
}