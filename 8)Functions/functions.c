#include <stdio.h>

int doub(int num) {
    return num * 2;
}

int dec(int num) {
    return num - 1;
}

int main() {
    int i = 2;
    while(i < 1000000) {
        printf("%d ", i);
        i = doub(i);
        i = dec(i);
    }
    return 0;
    
}