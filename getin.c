#include <ctype.h>
#include <stdio.h>

int getInt(int *pn);

int main() {
  int slot;
  int status = getInt(&slot);

  printf("%d", slot + 23);
}

int getInt(int *pn) {
  int c, sign;

  while (isspace(c = getchar())) {
    ;
  };

  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetc(c, stdin);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') {
    c = getchar();
  }

  for (*pn = 0; isdigit(c); c = getchar()) {
    *pn = 10 * *pn + (c - '0');
  }

  *pn *= sign;

  if (c != EOF) {
    ungetc(c, stdin);
  }

  return c;
}
