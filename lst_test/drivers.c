#include "drivers.h"

dev_list __dev_lst;

void dev_init()
{
    dev_list_init(&__dev_lst);
}

void dev_register(dev_node* dev_node)
{
	dev_list_append(&__dev_lst, dev_node);
}

int dev_unregister(char* name)
{
	if(dev_list_remove(&__dev_lst, name))
		return 1;

	return 0;
}

int dev_open(char* name)
{
	dev_node*	tmp;

	tmp = dev_list_find(&__dev_lst, name);
	if(!tmp)
		return 1;

	(tmp->dev_operations).open();
	return 0;
}

int dev_close(char* name)
{
	dev_node*	tmp;

	tmp = dev_list_find(&__dev_lst, name);
	if(!tmp)
		return 1;

	(tmp->dev_operations).close();
	return 0;
}

int dev_read(char* name, void* buf, int size)
{
	dev_node*	tmp;

	tmp = dev_list_find(&__dev_lst, name);
	if(!tmp)
		return 1;

	(tmp->dev_operations).read(buf, size);
	return 0;
}

int dev_write(char* name, void* buf, int size)
{
	dev_node*	tmp;

	tmp = dev_list_find(&__dev_lst, name);
	if(!tmp)
		return 1;

	(tmp->dev_operations).write(buf, size);
	return 0;
}

int dev_ctrl(char* name, int cmd, void* arg)
{
	dev_node*	tmp;

	tmp = dev_list_find(&__dev_lst, name);
	if(!tmp)
		return 1;

	(tmp->dev_operations).ctrl(cmd, arg);
	return 0;
}
