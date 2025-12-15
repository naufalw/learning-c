#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){

    int *x;
    x = malloc(sizeof(int) * 10);

    memset(x,0,0);
    if (x == NULL){
        printf("Error allocating 10 ints");
    }

}
