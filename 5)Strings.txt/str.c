#include <stdio.h>

int main() {
    
    // string  with pointers

    char * str1 = "Person1";

    char str2[] = "BenkoKann";

    char name[10] = "BenkoKann"; // needs 10 even if there are 9 chars for null terminator (0), which
    // indicates the end of a string

    printf("name: %s\n", name);
    printf("name length: %d\n", strlen(name));

    // COMPARIGN STRINGS
    if(strncmp(name, "BenkoKann",9) == 0) { // takes in 2 strings, a max comparision length.
    // will return 0 if equal and a different number if not equal
        printf("Hello, BenkoKann!\n");
    } else {
        printf("Not equal to BenkoKann\n");
    }

    // String Concatenation

    char dest[20] = "Hello";
    char src[20]="World";
    strncat(dest,src,3);
    printf("%s\n",dest);
    strncat(dest,src,20);
    printf("%s\n",dest);




    return 0;
}