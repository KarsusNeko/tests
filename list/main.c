#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

typedef struct _stu_node
{
	list_node*	next;
	int			id;
	char		name[12];	
} stu_node;

int cmp(list_node* ln1, list_node* ln2)
{
	stu_node* stu1;
	stu_node* stu2;

	stu1 = (stu_node*)ln1;
	stu2 = (stu_node*)ln2;

	return (stu1->id - stu2->id);
}

void print_i(list_node* ln)
{
	stu_node* stu;

	stu = (stu_node*)ln;

	printf("%d: %s\n", stu->id, stu->name);
}

int main(void)
{
	list stuts;
	list_init(&stuts);

	stu_node a;
	stu_node b;
	stu_node c;

	a.id = 1;
	strcpy(a.name, "a");
	b.id = 2;
	strcpy(b.name, "b");
	c.id = 3;
	strcpy(c.name, "c");

	list_append(&stuts, (list_node*)&a);
	list_append(&stuts, (list_node*)&b);
	list_append(&stuts, (list_node*)&c);

	printf("list: \n");
	list_travel(&stuts, print_i);
	
	stu_node* tmp;
	if( tmp = (stu_node*)list_find(&stuts, (list_node*)&b, cmp) )
		printf("find node b: %d, %s\n", tmp->id, tmp->name);
	else
		printf("cannot find node b.\n");
	if( tmp = (stu_node*)list_remove(&stuts, (list_node*)&c, cmp) )
		printf("removed node c: %d, %s\n", tmp->id, tmp->name);
	else
		printf("cannot find node c.");

	printf("after remove c: \n");
	list_travel(&stuts, print_i);

	stu_node d;
	d.id = 4;
	strcpy(d.name, "d");

	list_append(&stuts, (list_node*)&d);

	printf("after append d: \n");
	list_travel(&stuts, print_i);

	return 0;
}
