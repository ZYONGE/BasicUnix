#include <stdio.h>
#include "park.h"

int get_input(void) {
    int age;
    printf("나이를 입력하시오: ");
    scanf("%d", &age);
    return age;
}

int calculate_fee(int age) {
    if (age <= 6 || age >= 70) {
        return 0;
    } else if (age >= 7 && age <= 12) {
        return 1000;
    } else if (age >= 13 && age <= 19) {
        return 2000;
    } else if (age >= 20 && age <= 69) {
        return 3000;
    } else {
        return -1;
    }
}

void display(int age) {
    int fee = calculate_fee(age);

    if (fee >= 0) {
        printf("입장료는 %d원 입니다.\n", fee);
    } else {
        printf("잘못된 입력입니다.\n");
    }
}