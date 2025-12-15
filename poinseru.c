#include <stdio.h>

int main() {
  int x = 1, y = 2, z[10];
  char t = 'a';
  int *ip;

  ip = &x;
  y = *ip;

  *ip = 0;
  int a = *&x;
}
