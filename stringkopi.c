#include <stdio.h>

void strcpy_array(char *s, char *t);
void strcpy_pointers(char *s, char *t);
void strcpy_experienced(char *s, char *t);

int main() {

  char amessage[] = "Hello world";
  char bmessage[] = "HAHA";

  // this leads to undefined behavior since we're copying bigger string to
  // smaller one
  strcpy_experienced(bmessage, amessage);

  printf("%s\n", amessage);

  // amessage[0] = 'N';

  // char *pmessage = "Hello World";
  // pmessage = "HAHA";
  // pmessage[0] = 'H';
  // printf("%s", pmessage);
  // printf("%s", amessage);
}

void strcpy_array(char *s, char *t) {
  int i;

  i = 0;

  while ((s[i] = t[i]) != '\0')
    i++;
}

void strcpy_pointers(char *s, char *t) {
  int i;

  i = 0;

  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

void strcpy_experienced(char *s, char *t) {
  while ((*s++ = *t++) != '\0')
    ;
}
