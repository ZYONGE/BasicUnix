
// FILE: exchange.c
#include "module.h"

void exchange (data *d) {
  int tmp;
  tmp = d->a;
  d->a = d->b;
  d->b = tmp;
  print_value (d);          
}

