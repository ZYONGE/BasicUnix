#include <stdio.h>

void calculate(void);

int main(void) {

    calculate();

    return 0;
}

void calculate(void) {

    int option;
    printf("1. +\n 2. -\n 3. *\n 4. /\n");
    printf("옵션 선택: ");
    scanf("%d", &option);

    int n, m;
    printf("두 양의 정수 입력: ");
    scanf("%d %d", &n, &m);

    switch (option) {
        case 1:
            printf("%d + %d = %d\n", n, m, n + m);
            break;
        case 2:
            printf("%d - %d = %d\n", n, m, n - m);
            break;
        case 3:
            printf("%d * %d = %d\n", n, m, n * m);
            break;
        case 4:
            if (m != 0) {
                printf("%d / %d = %.2f\n", n, m, (float)n / m);
            } else {
                printf("0으로 나눌 수 없습니다.\n");
            }
            break;
        default:
            printf("잘못된 옵션입니다.\n");
    }

}