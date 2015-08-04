#include "list.h"

void list_init(list* l)
{
	l->head	= NULL;
	l->tail	= NULL;
}

list_node* list_find(list* l, list_node* ln)
{
	list_node* tmp = l->head;
	
	if(tmp == NULL)
		return NULL;
	
	if(func(ln, tmp))
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
	if(l->head == NULL && l->tail == NULL)
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

list_node* list_remove(list* l, list_node* ln, compar func)
{
	list_node* tmp	= l->head;
	list_node* rmv;

	if(tmp == NULL)
		return tmp;

	if(func(ln, tmp))
	{
		l->head	= NULL;
		l->tail	= NULL;
		return tmp;
	}

	while(tmp->next != NULL)
	{
		if(!func(ln, tmp->next))
		{
			tmp = tmp->next;
		}
		else
		{
			rmv = tmp->next;
			tmp->next = rmv->next;
			return rmv;
		}
	}

	return NULL;
}

void list_travel(list* l, info print_info)
{
	list_node* tmp = l->head;

	if(tmp == NULL)
		return tmp;
}
