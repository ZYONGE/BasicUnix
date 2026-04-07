#ifndef MODULE_H
#define MODULE_H

void input_value(int *value);
extern void print_value(int value);
extern void exchange(int *a, int *b);

void sum_global(int a, int b);
void sum_callbyval(int a, int b);
int sum_retbyval(int a, int b);
void sum_callbyref(int *a, int *b);
int *sum_retbyref(int *a, int *b);


#endif