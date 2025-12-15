#include <stdio.h>

int main() {

  char charMax = (char)((unsigned char)~0 >> 1);
  char charMin = -charMax - 1;
  printf("Signed Char:   %d to %d\n", charMin, charMax);
}
