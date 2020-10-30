#include<stdio.h>

void Swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int x = 1;
    int y = 2;
    printf("x: %d, y: %d\n", x, y);
    Swap(&x, &y);
    printf("x: %d, y: %d", x, y);


    return 0;
}