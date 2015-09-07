#ifndef __TIMER_H
#define __TIMER_H

#include "timer_list.h"

extern unsigned long ticks;

typedef void (*timer_handler)(void* arg);

int  timer_create(timer* timer, const char* name, unsigned long ticks, timer_handler hndlr, void* arg);
void timer_register(timer* timer);
void timer_unregister(char* name);

void timer_init();
void timer_free();

//void timer_workflow(timer_list *tl);
void timer_workflow();

#endif // __TIMER_H
