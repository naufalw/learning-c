#include <stdio.h>
int main() {
  int myNumber = 100;

  void *genericPtr = &myNumber;

  int *tempPtr = (int *)genericPtr;

  printf("Value via temptr: %d\n", *tempPtr);

  printf("Value via direct cast: %d\n", *(int *)genericPtr);
}
