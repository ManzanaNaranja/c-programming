#include<stdio.h>

int main() {

    // creating a pointer
        // datatype *var_name

    // 3 types of pointers, 
        // NULL pointers, Void pointers, and wild pointers

    // NULL pointer // use to direct to an empty location in a computer system. 
    int *ptr = NULL;
    printf("THe value of ptr is %p\n", ptr); // 00000000

    // VOID pointer, is a form of pointer where it is used to point to another variable of any data type
    // it can store the address of a variable of ANY data type

    int x = 4;
    float y = 5.5;
    void *pointer; // doesn't declare what type of data it will store
    pointer = &x;

    printf("Integer variable is = %d\n", *( (int*) pointer) );
    pointer = &y;
    printf("Float variable is = %f\n", *( (float*) pointer) );
   
   // Wild Pointer, pointers that are not initialized. can point to any arbirtrary
   // memory location which can cause a program to eventually crash.

   int *p; // wild pointer
   int z = 10;
   p = &z;
   printf("p=> %d\n", *p);
    
    ////////////////////
    // pointers and arrays

    int array[10];
    int *ptr1 = array;

    ptr1[0] = 1;
    *(array + 1) = 2;
    *(1 + array) = 2;
    array[2] = 4;

    printf("%d\n", *array+3); 

////////////////////////////////////
  // more on pointers // https://www.youtube.com/watch?v=47IS8VtAM9E

  // * dereference operator
  // used to get values of pointers
    // returns content at particular address

  // & refrence operator
  // creates an address to something (returns a pointer/address)

  int i, k, *ip;

  ip = &i; // ip is equal of the address of i
  i = 100;
  k = *ip;  // we take ip and dereference it, now looking at contents of it which is 100 so k = 100.
  k = k + 2; // k = 100 + 2  so k = 102
  i = *(&k); // taking address of k, referencing it, and taking contents of it so i = 102. (i = k).
  *(&k) = 200; // take address of k, set contents equal to 200,  k = 200

  printf("%d", k);


 
    
    return 0;
}



