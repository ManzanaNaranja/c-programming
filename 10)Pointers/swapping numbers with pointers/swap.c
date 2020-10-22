#include<stdio.h>

void swapnum(int *num1, int *num2) {
    int temp;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {
    int v1 = 11, v2 = 77;
    printf("Before swapping:");
    printf("\nv1: %d, v2: %d\n", v1, v2);
    
    // swapping the numbers
    swapnum(&v1, &v2);

    printf("After Swapping:");
    printf("\nv1: %d, v2: %d\n", v1, v2);

    return 0;
}