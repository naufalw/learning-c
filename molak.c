#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *p = malloc(1);
    int *c = malloc(1);


    *p = 1410065408;

    for (int i = 0; ; i++) {
        p[i] = 'X';
        if (i % 100 == 0) printf("Written %d bytes...\n", i);
    }

    free(p);

}
