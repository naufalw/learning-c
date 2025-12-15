#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp){
    int offset = 0;
    int bufsize = 4;
    char *buf;
    int c;

    printf("Initial size buffer: %zu\n", sizeof(buf));


    buf = malloc(bufsize);

    if (buf == NULL){
        return NULL;
    }

    while (c = fgetc(fp), c != '\n' && c != EOF){

        if (offset == bufsize -1 ){

            bufsize *=2;

            char *new_buf = realloc(buf, bufsize);

            if (new_buf == NULL){
                free(buf);
                return NULL;
            }

            buf = new_buf;

            printf("Resizing size buffer: %zu\n", sizeof(buf));

        }

        buf[offset++] = c;
    }

    // at EOF and no bytes, just free the buffer and return NULL
    if (c == EOF && offset == 0){
        free(buf);
        return NULL;
    }

    // shrink it down
    if (offset < bufsize-1){
        // +1 here since we wanna append end of string;
        char *new_buf = realloc(buf,offset + 1);

        if (new_buf != NULL){
            buf = new_buf;
        }

        printf("Making it small buffer: %zu\n", sizeof(buf));

    }

    buf[offset] = '\0';

    printf("Size buffer: %zu\n", sizeof(buf));

    return buf;
}

int main(void){
    FILE *fp = fopen("quote.txt", "r");

    char *line;

    while ((line = readline(fp)) != NULL){
        printf("%s\n", line);
        free(line);
    }

    fclose(fp);
}
