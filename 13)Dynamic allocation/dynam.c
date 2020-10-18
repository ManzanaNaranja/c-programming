#include<stdio.h>

typedef struct {
    char * name;
    int age;
} person;

int main() {

    person * myperson = (person *) malloc(sizeof(person)); // allocates a new person in the myperson argument

    myperson->name = "John";
    myperson->age = 21;

    printf("name: %s\n", myperson->name);
    printf("age: %d\n", myperson->age);

    

    printf("name: %s\n",(*myperson).name);
    printf("name: %d\n",(*myperson).age);

    free(myperson); // does not delete myperson var, releases the data it points to
    // after calling myperson, will not be able to access that area anymore.
    // have to allocate new data to it if we want to use that pointer again.

    

    return 0;
}