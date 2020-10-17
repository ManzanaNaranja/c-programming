#include <stdio.h>

int main() {

    int val = 11;

    printf("Val: %d\n", val);
    if (val > 10){
        printf("Val is greater than 10");
    } else if(val == 10) {
        printf("Val is equal to 10");
    } else {
        printf("val is less than 10");
    }
    printf("\n");

    int val2 = 3;

    printf("Val2: %d\n", val2);
    if(val2 < 5 && val > 5) {
        printf("val2 is less than five and val is greater than 5");
    }

}