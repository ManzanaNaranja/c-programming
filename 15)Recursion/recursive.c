#include<stdio.h>

unsigned int multiply(unsigned int x, unsigned int y) {

    if (x == 1) {
        return y;
    }
    else if(x > 1) {
        return y + multiply(x-1, y);
    }

    return 0;

}

int factorial(x) {
    if(x <= 1) {
        return 1;
    }
    return x * factorial(x-1);
}

void sysout(int a) {
    printf("%d\n", a);
}

int main() {

    int a = multiply(9, 4);
    sysout(a);

    sysout(factorial(10));

    sysout(factorial(4));


    return 0;
}