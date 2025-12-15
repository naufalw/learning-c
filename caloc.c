#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *p = malloc(10* sizeof(int));

    for (int i = 0; i < 10; i++){
        printf("Content at %d = {%d}\n", i+1, *(p+i));
    }

    for (int i = 0; i < 10; i++){
        p[i]=i+5;
    }

    for (int i = 0; i < 10; i++){
        printf("Content at %d = {%d}\n", i+1, *(p+i));
    }

}
