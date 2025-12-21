#include <stdio.h>
#include <threads.h>
#include <time.h>

mtx_t lock;

int slow_worker(void *arg) {
  mtx_lock(&lock);

  printf("Slow thread: locked mutex. sleeping 3s\n");

  struct timespec sleep_time;
  sleep_time.tv_sec = 3;
  sleep_time.tv_nsec = 0;
  thrd_sleep(&sleep_time, NULL);

  printf("SLeep done. unlock\n");

  mtx_unlock(&lock);
  return 0;
}

int impatient_worker(void *arg) {
  struct timespec ts;

  timespec_get(&ts, TIME_UTC);

  ts.tv_sec += 1;

  printf("Impatient try to lock within 1s\n");

  int result = mtx_timedlock(&lock, &ts);

  if (result == thrd_success) {
    printf("Impatient success, got lock\n");
    mtx_unlock(&lock);
  }

  else if (result == thrd_timedout) {
    printf("Impatient failed timeout\n");
  } else {
    printf("Impatient idk error\n");
  }

  return 0;
}

int main() {

  if (mtx_init(&lock, mtx_timed) != thrd_success) {
    return 1;
  }

  thrd_t t1, t2;

  thrd_create(&t1, slow_worker, NULL);

  struct timespec ts = {0, 100000000};
  thrd_sleep(&ts, NULL);

  thrd_create(&t2, impatient_worker, NULL);

  thrd_join(t1, NULL);
  thrd_join(t2, NULL);

  mtx_destroy(&lock);

  return 0;
}
