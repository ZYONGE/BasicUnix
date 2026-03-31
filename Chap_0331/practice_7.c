// 문제 :
#include <stdio.h>

int input ();
int sum (int, int);
void print (int, int, int);

int main() {
    int a, b, c;
    a = input ();
    b = input ();
    c = sum (a, b);

    print (a, b, c);
    return 0;
}

int input () {
    int n;
    printf("정수를 입력:");
    scanf("%d", &n);
    return n;
}

int sum (int a, int b) {
    return a + b;
}

void print (int x, int y, int z) {
    printf("%d + %d = %d\n", x, y, z);
}