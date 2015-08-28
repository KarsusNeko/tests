#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "drivers.h"

void hello_open()
{
    printf("hello: open\n");
}

void hello_close()
{
    printf("hello: close\n");
}

void hello_read(char* buf, unsigned char size)
{
    char a[5] = "hi";
    strcpy(buf, a);
}

void hello_write(char* buf, unsigned char size)
{
    printf("size %d: %s\n", size, buf);
}

void hello_ctrl(int cmd, void* arg)
{
    printf("cmd: %d, arg: %d\n", cmd, *(int*)arg);
}

dev_node hello = { 0 };

dev_ops hello_op = { 0 };

void sys_init()
{
    dev_init();
}

int main(void)
{
    sys_init();

    int buf[8];

    hello_op.open = hello_open;
    hello_op.close = hello_close;
    hello_op.read = hello_read;
    hello_op.write = hello_write;
    hello_op.ctrl = hello_ctrl;

    hello.dev_id = 1;
    hello.dev_sub_id = 1;
    strcpy(hello.dev_name, "hello");
    hello.dev_operations = hello_op;

    dev_register(&hello);
    dev_open("hello");
    dev_read("hello", buf, 8);
    printf("read buf: %s\n", buf);
    strcpy(buf, "icu");
    dev_write("hello", buf, sizeof(buf));
    dev_close("hello");
	return 0;
}
