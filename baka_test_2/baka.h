#ifndef __BAKA_H
#define __BAKA_H

#define N	255

typedef struct _observer observer;

typedef struct _observer_list
{
	observer*	head;
	observer*	tail;
	observer*	current;
	int			size;

	void	(*add_obsvr)(observer* obsv);
	void	(*rmv_obsvr)(observer* obsv);
} observer_list;

typedef struct _object
{
	// An Observer List
	observer_list	oq;

	int		num;

	void	(*notifier)(observer* observers);
	void	(*obsvr_add)(observer* observer);
	void	(*obsvr_remove)(observer* observer);
} object;

typedef struct _observer
{
	int		identity;
	void*	arg;
	void*	rtn;
	void	(*update_obj)(object* obj);

	observer*	next;
	observer*	prev;
} observer;

#endif 
