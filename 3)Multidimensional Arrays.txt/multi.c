#include <stdio.h>

int main() {

    int nums[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    int val = nums[2][2];

    char vowels[][5] = { // doesn't need a y val but NEEDS an x val

        {'A', 'E', 'I','O','U'},
        {'a','e','i','o','u'}

    };

    
    
    printf("%d\n", val);
    printf("%c\n", vowels[1][1]);

    return 0;
}