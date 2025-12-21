#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

// int run(void *arg) {
//   int n = *(int *)arg;
//   free(arg);
//   static int foo = 10;
//   int x = foo;
//   printf("Thread %d: x={%d}, foo={%d}\n", n, x, foo);
//   if (x != foo) {
//     printf("Thread %d: Craziness! x != foo! %d != %d\n", n, x, foo);
//   }
//   foo++;
//   return 0;
// }

int run(void *arg) {
  int n = *(int *)arg;
  free(arg);
  thread_local static int foo = 10;
  int x = foo;
  printf("Thread %d: x={%d}, foo={%d}\n", n, x, foo);
  if (x != foo) {
    printf("Thread %d: Craziness! x != foo! %d != %d\n", n, x, foo);
  }
  foo++;
  return 0;
}

#define THREAD_COUNT 5

int main(void) {
  thrd_t t[THREAD_COUNT];

  for (int i = 0; i < THREAD_COUNT; i++) {
    int *n = malloc(sizeof(*n));
    *n = i;
    thrd_create(t + i, run, n);
  }

  for (int i = 0; i < THREAD_COUNT; i++) {
    thrd_join(*(t + i), NULL);
  }
}
