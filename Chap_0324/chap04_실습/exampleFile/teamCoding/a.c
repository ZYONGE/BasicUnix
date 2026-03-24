/* 
 * gcc -o prog a.c b.c
 */

//File: a.c

#include "module.h"

void exchange (int *ap, int *bp);

int main() {
    int a, b;
    input (&a, &b);         
    printf ("Before: %d, %d\n", a, b);
    exchange (&a, &b);
    print_value (a, b);          
    return 0;   
}

void input (int *ap, int *bp) {
    printf("Type two integers: ");
    scanf("%d%d", ap, bp);
}

void exchange (int *ap, int *bp) {
    int temp;

    temp = *ap;
    *ap = *bp;
    *bp = temp;
}
