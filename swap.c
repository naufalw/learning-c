#include <stdio.h>

void swapBroken(int x, int y);
void swap(int *x, int *y);

int main() {
  int x = 5;
  int y = 10;

  swap(&x, &y);

  printf("%d %d", x, y);
}

void swapBroken(int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
