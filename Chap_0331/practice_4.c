#include <stdio.h>

void add (int, int);
void subtract (int, int);
void multiply (int, int);
void divide (int, int);

int main (void ){
    char menu;
    int a, b;

    for (;;) {
        printf ("두 정수를 입력하시오: ");
        scanf ("%d, %d", &a, &b);

        printf ("a. 덧셈\ns. 뺄셈\nm. 곱셈\nd. 나눗셈\nq. 종료\n");
        printf (">> 원하는 메뉴를 선택하시오: ");
        scanf (" %c", &menu);

        switch (menu) {
            case 'a':
            add (a, b);
            break;

            case 's':
            subtract (a, b);
            break;

            case 'm':
            multiply (a, b);
            break;

            case 'd':
            divide (a, b);
            break;

            case 'q':
            return 0;
            
            default :
            printf ("잘못 입력하였습니다.\n");
        }
    }

    return 0;
}

void add (int a, int b){
    printf ("덧셈 결과 : %d\n", a + b);
}
void subtract (int a, int b){
    printf ("뺄셈 결과 : %d\n", a - b);
}
void multiply (int a, int b){
    printf ("곱셈 결과 : %d\n", a * b);
}
void divide (int a, int b){
    if (b == 0) {
        printf ("0으로 나눌 수 없습니다.\n");
    } else {
        printf ("나눗셈 결과 : %d\n", a / b);
    }
}
