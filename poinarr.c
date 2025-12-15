#include <stdio.h>

// int main() {
//   int arr[5] = {10, 20, 30, 40, 50};

//   int *x = arr;

//   printf("%p %d\n", x, *x);
//   x++;

//   printf("%p %d", x, *x);
// }

int main() {
  int arr[5] = {10, 20, 30, 40, 50};
  int(*x)[5] = &arr;

  printf("%p %d\n", x, (*x)[4]);
  x++;
  printf("%p %d", x, *x[0]);
}
