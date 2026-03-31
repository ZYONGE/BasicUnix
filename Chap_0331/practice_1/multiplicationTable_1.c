#include <stdio.h>

int multiplicationTable_1(void){

    int i, j;
    //2에서부터 9까지의 구구단을 출력하는 프로그램
    for (i = 2; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%d ", i * j);
        }
        printf("\n");
    }

    return 0;
}