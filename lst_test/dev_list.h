#ifndef __DEV_LIST_H
#define __DEV_LIST_H

typedef struct _dev_ops
{
	// To save private data
	// 
	void*			private_data;

	void			(*open)();
	void			(*close)();
	void			(*read)(char* buf, unsigned char size);
	void			(*write)(char* buf, unsigned char size);
	void			(*ctrl)(int cmd, void* arg);
} dev_ops;

typedef struct _dev_node
{
	list_node*		next;
	unsigned char	dev_id;
	unsigned short	dev_sub_id;
	char			dev_name[12];
	dev_ops			dev_operations;
} dev_node;

typedef list	dev_list;

void dev_list_init(dev_list* dl);
void dev_list_append(dev_list* dl, dev_node* dn);
dev_node* dev_list_find(dev_list* dl, const char* dev_name);
dev_node* dev_list_remove(dev_list* dl, const char* dev_name);
void dev_list_clear(dev_list* dl);

#endif // __DEV_LIST_H