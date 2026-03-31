#include <stdio.h>

int sum (int n);

int main(){

    int i;
    printf("정수를 입력:");
    scanf("%d", &i);

    printf("1부터 %d까지의 합 : %d\n", i, sum(i));
    
    return 0;
}

//1부터 n까지의 합을 구하는 함수    
int sum (int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
    }
    return s;
}