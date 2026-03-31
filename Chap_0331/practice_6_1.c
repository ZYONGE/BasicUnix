#include <stdio.h>

long unsigned factorial (long unsigned n);

int main(void){

    long unsigned f;
    f = factorial (20);

    printf("1부터 20까지의 곱 : %lu\n", f);

    return 0;
}

long unsigned factorial (long unsigned n) {

    long unsigned result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}