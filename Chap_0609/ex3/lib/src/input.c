
// FILE: input.c
#include <stdlib.h>
#include "module.h"

data *input_value () {
  data *d=0;
  d = malloc (sizeof (data));
  d->a = 3;
  d->b = 7;
  print_value (d);
  return d;
}


