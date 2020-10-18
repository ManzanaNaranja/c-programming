#include <stdio.h>

int main() {

    int i = 0; 

    while (i < 10) {
        i++;
        printf("%d ", i);
        
    }
    printf("\n");

    while(1) { // infinite
        i++;
        if(i % 2 == 0) {
            continue; 
        }
        if(i >20) {
            break;
        }

        printf("%d ", i);

        



    }

    return 0;
}