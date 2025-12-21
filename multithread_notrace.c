#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

int run(void *arg) {
  int i = *(int *)arg;

  printf("THREAD %d: Running thread\n", i);

  return i; // to be picked up by thrd_join()
}

#define THREAD_COUNT 5

int main(void) {
  thrd_t t[THREAD_COUNT]; // to hold the thread ID

  int i;

  printf("Launching threads\n");

  for (i = 0; i < THREAD_COUNT; i++) {

    int *aarg = malloc(sizeof *aarg);
    *aarg = i;

    thrd_create(t + i, run, aarg);
  }

  printf("Doing other things while the thread runs...\n");

  printf("Waiting for the thread to complete...\n");

  for (int i = 0; i < THREAD_COUNT; i++) {
    int res;
    thrd_join(t[i], &res);

    printf("Thread %d complete! \n", res);
  }

  printf("All threads complete\n");
}
