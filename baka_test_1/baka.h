#ifndef __BAKA_H
#define __BAKA_H

enum {SYB1, SYB2, SYB3};

typedef struct arg_1
{
	void (*handler_1)(struct arg_1* arg_1);
} arg_1;

typedef struct arg_2
{
	int a;
	void (*handler_2)(struct arg_2* arg_2);
} arg_2;

typedef struct arg_3
{
	int a;
	long b;
	void (*handler_3)(struct arg_3* arg_3);
} arg_3;

typedef struct baka
{
	void *arg;
	int len;
	int syb;

	void (*baka_handler)(void* baka_arg);
} baka;

#endif // __BAKA_H
