#include <stdio.h>
#include <stdlib.h>

#include "module.h"

void input_value(int *value){
    printf("Enter an integer value: ");
    scanf("%d", value);
}
void print_value(int value){
    printf("The value is: %d\n", value);
}
void exchange(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void sum_global(int a, int b){
    extern int global_sum;
    global_sum = a + b;
    printf("Sum (global variable): %d\n", global_sum);
}
void sum_callbyval(int a, int b){
    int sum = a + b;
    printf("Sum (call by value): %d\n", sum);
}
int sum_retbyval(int a, int b){
    int sum = a + b;
    printf("Sum (return by value): %d\n", sum);
    return sum;
}
void sum_callbyref(int *a, int *b){
    int sum = *a + *b;
    printf("Sum (call by reference): %d\n", sum);
}
int *sum_retbyref(int *a, int *b){
    int *sum = (int *)malloc(sizeof(int));
    *sum = *a + *b;
    return sum;
}

