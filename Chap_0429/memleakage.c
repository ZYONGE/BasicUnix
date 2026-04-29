#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arr;

    for (int i=0;i<10;i++){
        arr = (int*)malloc(1000);
    }
    sleep(1);
    
    return 0;
}