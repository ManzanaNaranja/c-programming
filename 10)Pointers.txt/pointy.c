#include<stdio.h>

int main() {
    // allocates a local (stack) variable called name, which is a pointer to a single character
    // causes the string "John" to appear somewhere in the program memory (after it is compiled and executed)
    // it initializes the name argument to point to where the J character resides (which is followed by the rest of the string in its memory);

    char * name = "John";

    // define a local var a

    int a = 1;

    // defien a pointer variable using the & operator

    int * pointer_to_a = &a;

    a ++;
    *pointer_to_a += 1; // references where the pointer points

    printf("The value a is %d\n", a);

    printf("The value of a is also %d\n", *pointer_to_a);

    

    return 0;
}