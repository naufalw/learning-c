#include <stdio.h>
struct car {
    char *name;
    float price;
    int speed;
};

void set_price(struct car *c, float new_price);

int main(void){
    struct car saturn = {.speed = 175, .name = "Saturn SL/2"};

    set_price(&saturn, 900);

    printf("price is: %f\n", saturn.price);

}

void set_price(struct car *c, float new_price){
    c->price = new_price;
}
