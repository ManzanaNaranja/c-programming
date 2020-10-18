#include <stdio.h>

int main() {

    int ages[5];
    int weight[] = {10, 100, 101, 102, 103};

    const char *a[2];
    a[0] = "blah";
    a[1] = "hmm";

    printf("first string in arr: %s\n", a[0]);

    ages[0] = 11;
    ages[1] = 2;
    ages[2] = 79;
    ages[3] = 44;
    ages[4] = 24;

    

    printf("The 2nd age in the array is %d\n", ages[1]);
    printf("Second weight value is %d\n", weight[1]);


   

}