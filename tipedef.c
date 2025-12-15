#include <stdio.h>

struct animal {
  char name;
  int leg_count, speed;
};

typedef struct animal animal;

typedef struct {
  int price;
} shoe;

int main(void) {
  shoe b = {.price = 20};

  animal z = {.leg_count = 2, .name = 'e', .speed = 20};
  int a = 's';
}
