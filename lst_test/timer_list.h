#ifndef __TIMER_LIST_H
#define	__TIMER_LIST_H

#include "list.h"

// At first I suppose a work mode such as work once  or
// work periodically flag may be better. But then I find
// that we can handle this outside the timer so I delete
// this field.
typedef struct _timer
{
	list_node*		next;
	unsigned long	ticks;
	void			(*task)(void* arg);
	void*			arg;
	char			name[7];
} timer;

typedef list	timer_list;

void	timer_list_init(timer_list* tl);
timer*	timer_remove(timer_list* tl, char* name);
void	timer_append(timer_list* tl, timer* timer);
void	timer_list_clear(timer_list* tl);

#endif // __TIMER_LIST_H
