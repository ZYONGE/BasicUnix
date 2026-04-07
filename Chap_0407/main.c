#include <stdio.h>
#include <stdlib.h>

#include "module.h"

int main(){
    int a, b;

    input_value(&a);
    input_value(&b);

    print_value(a);
    print_value(b);

    exchange(&a, &b);
    printf("After exchange:\n");
    
    print_value(a);
    print_value(b);

    return 0;
}