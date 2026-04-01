#include <stdio.h>

#include "practice_7.h"


int main(void) {

    int a, b, c;

    a = input();
    b = input();
    c = sum(a, b);

    print(a, b, c);

    return 0;
}