#include <stdio.h>

void sum ();
int input(int n);

int main(){
    sum();
    return 0;
}

void sum (){
    int n;
    n = input(n);
    while(n>0){
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum+=i;
        }
        break;
    }
    printf("1부터 %d까지의 합 : %d\n", n, sum);
}

int input (int n){
    int n;
    printf("양수를 입력하세요 : ");
    scanf ("%d", &n);
    return n;
}