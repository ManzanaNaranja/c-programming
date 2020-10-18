#include<stdio.h>

struct point {
    int x;
    int y;
};


typedef struct{
    char * brand;
    int model;
} vehicle;



void draw2(vehicle car); // typedef so no structs in front

void draw(struct point p);


int main() {

    // structures are foundation for objects and classes in c.

    struct point p;

    p.x = 10;
    p.y = 5;

    draw(p);

    vehicle car;
    car.brand = "Tesla";
    car.model = 2020;

    draw2(car);

    return 0;
}

void draw(struct point p) {
        printf("X: %d Y: %d\n", p.x, p.y);
}

void draw2(vehicle car) { // leave out structs since it is a typedef
        printf("X: %s Y: %d\n", car.brand, car.model);
}

