#include <stdio.h>
#include <stdlib.h>

#include "module.h"

int main(){
    int a, b;
    input_value(&a);
    input_value(&b);

    sum_global(a, b);
    sum_callbyval(a, b);
    int sum1 = sum_retbyval(a, b);
    printf("Sum (return by value): %d\n", sum1);

    return 0;
}