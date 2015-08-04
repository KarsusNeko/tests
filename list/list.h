#ifndef __LIST_H
#define __LIST_H

typedef int _list_node
{
	struct _list_node* next;
} list_node;

typedef int _list
{
	list_node*	head;
	list_node*	tail;
} list;

typedef int (*compar)(list_node* ln1, list_node* ln2);
typedef void (*info)(list_node* ln);

void list_init(list* l);
list_node* list_find(list* l, list_node* ln, compar func);
void list_append(list* l, list_node* ln);
list_node* list_remove(list* l, list_node* ln, compar func);
void list_travel(list* l, info print_info);
