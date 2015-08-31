#include <stdio.h>
#include <string.h>

unsigned long ticks;

timer timer1;
timer timer2;

void hndlr_1(void *arg)
{
	printf("handler1 triggered at %d, argument: %d.\n", ticks, *(int*)arg);
}

void hndlr_2(void *arg)
{
	timer* tmp = (timer*)arg;
	timer->ticks += ticks;
	
	printf("handler2 triggered at %d.\n", ticks);
}

int main(void)
{
	if(timer_create(&timer1, "timer1", 100, hndlr_1, 32) < 0)
	{
		printf("failed to create timer1.\n");
	}
	
	if(timer_create(&timer2, "timer2", 200, hndlr_2, timer2))
	{
		printf("failed to create timer2.\n");
	}
	
	timer_register(&timer1);
	timer_register(&timer2);
	
	while(ticks++ < 500)
	{
		timer_workflow();
	}
	
	return 0;
}