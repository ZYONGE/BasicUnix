#include <stdio.h>
long unsigned factorial(long unsigned n);

int main(void){

    int n;
    long unsigned f;

    printf("임의의 양의 정수를 입력:");
    scanf("%d", &n);

    f = factorial (n);

    printf("1부터 %d까지의 곱 : %lu\n", n, f);
    
    return 0;
}

long unsigned factorial (long unsigned n){
    long unsigned f = 1;
    for (long unsigned i = 1; i <= n; i++){
        f *= i;
    }
    return f;
}