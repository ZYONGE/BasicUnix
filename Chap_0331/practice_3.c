// 0부터 첫 n개의 짝수의 합과
// 첫 n개의 홀수의 합을 계산하는 프로그램을 다음에 따라 작성하시오.
// 주어진 문장을 사용하여 함수로 표현한 프로그램을 작성하시오.
//for (cnt=0, i=1, j=2; cnt<n; ++cnt, i+=2, j+=2)
// sum_odd += i, sum_even += j;

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, cnt, i, j;
    int sum_odd = 0, sum_even = 0;

    printf ("n을 입력하시오 : ");
    scanf ("%d", &n);

    for (cnt=0, i=1, j=2; cnt<n; ++cnt, i+=2, j+=2) {
        sum_odd += i, sum_even += j;
    }

    printf ("첫 %d개의 짝수의 합 : %d\n", n, sum_even);
    printf ("첫 %d개의 홀수의 합 : %d\n", n, sum_odd);

    return 0;
}