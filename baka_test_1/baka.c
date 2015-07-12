#include "baka.h"
#include <stdio.h>

void baka_handler_1()
{
	printf("baka_handler_1 called.\n");
}

void baka_handler_2(arg_2* arg_2)
{
	printf("baka_handler_2 called, a=%d\n", arg_2->a);
}

void baka_handler_3(arg_3* arg_3)
{
	printf("baka_hanlder_3 called, a=%d, b=%d\n", arg_3->a, arg_3->b);
}


void baka_func(baka* baka)
{
	switch(baka->syb)
	{
	case SYB1:
		baka->baka_handler((arg_1*)baka->arg);
		break;
	case SYB2:
		baka->baka_handler((arg_2*)baka->arg);
		break;
	case SYB3:
		baka->baka_handler((arg_3*)baka->arg);
		break;
	default:
		break;
	}
}

int main(void)
{
	arg_1 a_1;
	a_1.handler_1 = baka_handler_1;

	baka baka_1;
	baka_1.arg = (void*)&a_1;
	baka_1.syb = SYB1;
	baka_1.baka_handler = a_1.handler_1;

	baka_func(&baka_1);

	arg_2 a_2;
	a_2.a = 2;
	a_2.handler_2 = baka_handler_2;

	baka baka_2;
	baka_2.arg = (void*)&a_2;
	baka_2.syb = SYB2;
	baka_2.baka_handler = a_2.handler_2;

	baka_func(&baka_2);

	arg_3 a_3;
	a_3.a = 3;
	a_3.b = 4;
	a_3.handler_3 = baka_handler_3;

	baka baka_3;
	baka_3.arg = (void*)&a_3;
	baka_3.syb = SYB3;
	baka_3.baka_handler = a_3.handler_3;

	baka_func(&baka_3);

	return 0;
}
