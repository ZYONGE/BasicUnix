#include <stdio.h>

int processList(int *list, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list[i];
    }
    return sum;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}