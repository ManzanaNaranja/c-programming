#include <stdio.h>

int main() {

    for(int i = 0; i < 10; i++) {
        printf("%d\n", i);

    }

    int array[10] = {1, 2,3 ,4,5,6,7,8,9,10};
    int sum = 0; 
    int product = 1;
    int i;
    for(i = 0; i < 10; i++) {
        sum += array[i];
        product *= array[i];
    }

    printf("Sum of the arrays is %d\n", sum);
    printf("Product of the arrays is %d\n", product);

    return 0;
}