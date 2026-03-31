#include <stdio.h>

// Global variables
int p, q, r;

// Function prototypes
void sum_global ();
void sum_callbyval(int, int);
int sum_retbyval(int, int);
void sum_callbyref (int *, int*, int *);
int *sum_retbyref (int *, int *);

// Main function
int main () {
    int a=20, b=30, res;
    p = a;
    q = b;

    sum_global ();
    printf ("After sum_global(): %d + %d = %d\n", p, q, r);

    sum_callbyval (a, b);
    printf ("Data transfer by call by val : a= %d, b = %d \n", a, b);

    res = sum_retbyval (a, b);
    printf ("Data transfer by return by val : %d \n", res);

    sum_callbyref (&a, &b, &res);
    printf ("Data transfer by call by ref : %d + %d = %d\n", a, b, res);

    res = *sum_retbyref (&a, &b);
    printf ("Data transfer by return by ref : %d \n", res);

return 0;
}

// Function definitions
void sum_global () {
    r = p + q;
}
void sum_callbyval (int x, int y) {
    r = x + y;
}
int sum_retbyval (int x, int y) {
    return x + y;
}
void sum_callbyref (int *x, int *y, int *z) {
    *z = *x + *y;
}
int *sum_retbyref (int *x, int *y) {
    r = *x + *y;
    return &r;
}
