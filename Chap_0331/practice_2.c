#define PI 3.141592
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void area (double r);
void circumference (double r);

int main () {

    while (1){ 
        char option;
        printf ("A. 면적\nC. 둘레\nQ. 종료\n");
        printf ("옵션을 입력하시오 : ");
        scanf (" %c", &option);

        double r;
        printf ("반지름을 입력하시오 : ");
        scanf ("%lf", &r);

        switch (option){
            case 'A':
            case 'a':
                area (r);
                break;

            case 'C' :
            case 'c' :
                circumference (r);
                break;

            case 'Q':
            case 'q' :
                exit (0);

            default :
            printf ("다시 입력하시오\n");
        }
    }

    return 0;
}

void area (double r){
    printf ("원의 면적 : %lf\n", PI * pow (r, 2));
}

void circumference (double r){
    printf ("원의 둘레 : %lf\n", 2 * PI * r);
}