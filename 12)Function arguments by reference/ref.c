#include<stdio.h>

typedef struct{
        int x;
        int y;
} point;


// void move(point * p) {
//     (*p).x++;
//     (*p).y++;
// }

void move(point * p) { // Shorthand version of commented out function above 
    p->x++;
    p->y++;
}

void addone(int *n) { // receives pointer and CAN manipulate it because it knows where it is in memory
    (*n)++;
}

int main() {

    int n = 0;
    printf("Before: %d\n", n); // 0
    addone(&n);
    printf("After: %d\n", n); // 1

    point p;
    p.x = 0;
    p.y = 0;

    printf("X: %d Y: %d\n", p.x, p.y);
    move(&p);

    printf("X: %d Y: %d\n", p.x, p.y);
    


    return 0;
}