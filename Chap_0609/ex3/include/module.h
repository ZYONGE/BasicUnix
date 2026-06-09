
// FILE: module.h
#ifndef __MODULE_H__
#define __MODULE_H__

typedef struct data_t {
  int a;
  int b;
} data;

extern void print_value(data *);       
extern data *input_value(); 
extern void exchange(data *d);

#else

#endif 

