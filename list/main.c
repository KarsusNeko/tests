#include <stdio.h>
#include "list.h"

typedef struct _stu_node
{
	list_node*	next;
	int			id;
	char		name[12];	
} stu_node;

int cmp(list_node* ln1, list_node* ln2)
{
}
