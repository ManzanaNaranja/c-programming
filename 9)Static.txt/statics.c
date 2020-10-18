#include<stdio.h>

int increment() { 

    int count = 0; // not static
    count ++;
    return count; // count variable is removed from memory after completion of function
}

int incrementWithStatic() {
    static int count = 0;
    count++;
    return count;
}

int sum(i) {
    static int total = 0;
    total += i;
    return total;
}



int main() {
    printf("%d ", increment());
    printf("%d ", increment());
    printf("\n");

    printf("%d ", incrementWithStatic());
    printf("%d ", incrementWithStatic());
    printf("\n");

    printf("%d ", sum(10));
    printf("%d ", sum(1));
    printf("%d ", sum(8));
    printf("%d ", sum(84));

    return 0;
}