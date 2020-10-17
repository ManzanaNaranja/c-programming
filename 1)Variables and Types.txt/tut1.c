#include <stdio.h>

int main() {

    int a = 10;
    int b = 20;
    a = a + b + a/2 + b/2;

    char character = 'G';
    double thedoub = 2.1413;
	
	char name[] = "BenkoKann";
	char name2[] = {'t','h','e','k','a','n','n'};
	char newname[20];
    
    printf("a + b + a/2 + b/2 = %d\n", a);

    printf("I am an integer of value: %d and my size is %lu bytes\n", a, sizeof(int));

    printf("I am a character of value: %c and my size is %lu byte.\n",character,sizeof(char));

    printf("I am the doub: %lf and my size is %lu bytes.\n", thedoub, sizeof(double));
	
	printf("name: %s\n", name);
	printf("name2: %s\n",name2);
	
	printf("enter new name: ");
	scanf("%s", newname);
	printf("your new name is %s.", newname);
	
	
	
    return 0;

}