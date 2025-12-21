#include <stdio.h>
#include <threads.h>
#define VALUE_COUNT_MAX 5

int value[VALUE_COUNT_MAX];
int value_count = 0;

mtx_t value_mtx;
cnd_t value_cnd;

int run(void *arg) {
  (void)arg;

  for (;;) {

    mtx_lock(&value_mtx);

    while (value_count < VALUE_COUNT_MAX) {
      printf("Thread waiting\n");
      cnd_wait(&value_cnd, &value_mtx);
    }

    printf("Thread is awake\n");

    int t = 0;

    for (int i = 0; i < VALUE_COUNT_MAX; i++) {
      t += value[i];
    }

    printf("Total is: %d\n", t);

    value_count = 0;

    mtx_unlock(&value_mtx);
  }
  return 0;
}

int main(void) {
  thrd_t t;

  mtx_init(&value_mtx, mtx_plain);
  cnd_init(&value_cnd);

  thrd_create(&t, run, NULL);
  thrd_detach(t);

  for (;;) {
    int n;

    scanf("%d", &n);

    mtx_lock(&value_mtx);

    value[value_count++] = n;

    if (value_count == VALUE_COUNT_MAX) {
      printf("Main: Signaling thread\n");
      cnd_signal(&value_cnd);
    }

    mtx_unlock(&value_mtx);
  }

  mtx_destroy(&value_mtx);
  cnd_destroy(&value_cnd);
}
