#include "list.h"

void list_init(list* l)
{
	l->head	= NULL;
	l->tail	= NULL;
}

list_node* list_find(list* l, list_node* ln, compar func)
{
	list_node* tmp = l->head;
	
	if(tmp == NULL)
		return NULL;
	
	if(!func(ln, tmp))
		return tmp;
	
	while(tmp->next != NULL)
	{
		if(!func(ln, tmp->next))
			return tmp->next;
		tmp = tmp->next;
	}
}

void list_append(list* l, list_node* ln)
{
	if(l->head == NULL)
	{
		l->head			= ln;
		l->tail			= ln;
	}
	else
	{
		ln->next		= NULL;
		l->tail->next	= ln;
		l->tail			= ln;
	}
}

// Return the pointer of the next node before the node
// to be deleted may be the best return value.
list_node* list_remove(list* l, list_node* ln, compar func)
{
	list_node* tmp	= l->head;
	list_node* rmv;

	if(tmp == NULL)
		return tmp;

	if(!func(ln, tmp))
	{
		l->head	= NULL;
		l->tail	= NULL;
		return tmp;
	}

	while(tmp->next != NULL)
	{
		if(func(ln, tmp->next) != 0)
		{
			tmp = tmp->next;
		}
		else
		{
			rmv = tmp->next;
			if(rmv->next)
			{
				tmp->next = rmv->next;
			}
			else
			{
				tmp->next = NULL;
				l->tail = tmp;
			}
			return rmv->next;
		}
	}

	return NULL;
}

void list_travel(list* l, info print_info)
{
	list_node* tmp = l->head;

	if(tmp == NULL)
		return;
	do
	{
		print_info(tmp);
		tmp = tmp->next;
	}while(tmp != NULL);
}
