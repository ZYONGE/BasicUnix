#include <stdio.h>

int input ();
void sum (int n);

int main() {
    int n;
    sum (n);
    return 0;
}

int input (){
    int n;
    printf("양수를 입력하세요 : ");
    scanf ("%d", &n);
    return n;
}

void sum (int n){
    n = input ();
    while(n>0){
        int sum = 0;
        for(int i=1; i<=n; i++){
            sum+=i;
        }
        break;
    }
}