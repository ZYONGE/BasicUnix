#include <stdio.h>

int main( ){

    int n, *np=&n, *pt=np;
    char c, *cp=0; //또는 *cp=NULL

    *np = 10;
    c = 'B';
    cp = &c;

    printf ("*np=%d\n", *np);
    printf ("*cp = %c\n", *cp);

    return 0;
}