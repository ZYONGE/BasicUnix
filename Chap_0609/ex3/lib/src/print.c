// FILE: print.c
#include <stdio.h>
#include "module.h"

void print_value (data *d) {
  printf ("%d <=> %d\n", d->a, d->b);
}
