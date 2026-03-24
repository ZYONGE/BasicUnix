// File: b.c
#include "module.h"   // 

static void exchange (int *ap, int *bp);

void print_value(int x, int y) {
    printf ("After : %d, %d\n", x, y);
    exchange (&x, &y);
    printf ("Intrachange: %d, %d\n", x, y);
}

static void exchange (int *ap, int *bp) {
    int temp;

    temp = *ap*2;
    *ap = *bp*2;
    *bp = temp;
}
