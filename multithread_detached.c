#include <stdio.h>
#include <threads.h>
#include <time.h>

#define THREAD_COUNT 10

int run(void *arg) {
  int *num = (int *)arg;

  printf("Thread %lu running!\n", thrd_current());

  return 0;
}

int main(void) {
  thrd_t t;

  for (int i = 0; i < THREAD_COUNT; i++) {
    int now = i;

    thrd_create(&t, run, &now);
    thrd_detach(t);
  }

  thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);
}
