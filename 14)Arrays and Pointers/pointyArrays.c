#include<stdio.h>



int main() {
    
char vowels[] = {'A', 'E', 'I', 'O', 'U'};
char *pvowels = &vowels;
int i;

    for (i = 0; i < 5; i++) {
    printf("&vowels[%d]: %u, pvowels + %d: %u, vowels + %d: %u\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
}

   for(i = 0; i < 5; i++) {
        printf("%c, %c, %c\n", vowels[i], *(pvowels + i), *(vowels+i));
   }

   ////////////////////////////////////////


    printf("SIZE OF CHAR: %zu\n", sizeof(char));

   // allocate memory

   char *str;

   str = (char *) malloc(15);
   strcpy(str, "tutorialspoint");
   printf("String: %s, Address: %u\n", str, str);

   // reallocating memory

   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String: %s, Address: %u\n", str, str);

/////////////////////////////////////////////////

// dynamic memory allocation for arrays

    // allocate memory to store 5 characters;

    // normally, you would have to know what would bee in the array
    // beforehand. using dynamic memory allocation, can allocate just
    // the amount required
    int n = 5;
    char *pvowels2 = (char *) malloc(n*sizeof(char));
    


    pvowels2[0] = 'A';
    pvowels2[1] = 'E';
    *(pvowels2+2) = 'I';
    pvowels2[3] = 'O';
    *(pvowels2+4) = 'U';

    for(i = 0; i < n; i++) {
        printf("%c", pvowels2[i]);
    }
    printf("\n");
    free(pvowels2);

//////////////////////////////////////////////////////////////////
    // dynamic memory allocation for 2d array
    // requires a pointer to a pointer

int nrows = 2;
int ncols = 5;
int j;

// Allocate memory for nrows pointers
char **pvowels3 = (char **) malloc(nrows * sizeof(char *));

// For each row, allocate memory for ncols elements
pvowels3[0] = (char *) malloc(ncols * sizeof(char));
pvowels3[1] = (char *) malloc(ncols * sizeof(char));

pvowels3[0][0] = 'A';
pvowels3[0][1] = 'E';
pvowels3[0][2] = 'I';
pvowels3[0][3] = 'O';
pvowels3[0][4] = 'U';

pvowels3[1][0] = 'a';
pvowels3[1][1] = 'e';
pvowels3[1][2] = 'i';
pvowels3[1][3] = 'o';
pvowels3[1][4] = 'u';

for (i = 0; i < nrows; i++) {
    for(j = 0; j < ncols; j++) {
        printf("%c ", pvowels3[i][j]);
    }

    printf("\n");
}

// Free individual rows
free(pvowels3[0]);
free(pvowels3[1]);

// Free the top-level pointer
free(pvowels3);



    return 0;
}