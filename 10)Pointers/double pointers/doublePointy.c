#include<stdio.h>



int main() {

    int num = 123;

    int *ptr2;
    int **ptr1;

    // storing address of num in ptr2
    ptr2 = &num;

    // storing address of ptr2 in ptr1
    ptr1 = &ptr2;

    // displaying value of var using both single and double pointers

    printf("Value of var = %d\n", num);
    printf("Value of var using single pointer = %d\n", *ptr2);
    printf("Value of var using double pointer = %d\n", **ptr1);

    ////////////////////////////////////////////////////////////

    
    return 0;
}

