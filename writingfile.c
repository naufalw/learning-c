#include <stdio.h>

int main(void) {
  FILE *fp;

  int x = 32;

  fp = fopen("writings.txt", "w");

  fputc('B', fp);
  fputc('\n', fp);
  fprintf(fp, "x = %d\n", x);
  fputs("Hello, world", fp);
  fclose(fp);
}
