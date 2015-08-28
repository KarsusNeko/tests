#include "dev_list.h"
#include <string.h>

int dev_cmp(list_node* ln1, list_node* ln2)
{
	dev_node* dn1 = NULL;
	dev_node* dn2 = NULL;

	dn1 = (dev_node*)ln1;
	dn2 = (dev_node*)ln2;

	return (strcmp(dn1->dev_name, dn2->dev_name));
}

void dev_list_init(dev_list* dl)
{
	list_init(dl);
}

void dev_list_clear(dev_list* dl)
{}


void dev_list_append(dev_list* dl, dev_node* dn)
{
	list_append(dl, dn);
}

dev_node* dev_list_find(dev_list* dl, const char* dev_name)
{
	dev_node tmp;
	strcpy(tmp.dev_name, dev_name);

	return (dev_node*)list_find(dl, &tmp, dev_cmp);
}

dev_node* dev_list_remove(dev_list* dl, const char* dev_name)
{
	dev_node tmp;

	strcpy(tmp.dev_name, dev_name);

	return (dev_node*)list_remove(dl, &tmp, dev_cmp);
}
