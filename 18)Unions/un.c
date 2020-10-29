#include<stdio.h>

union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

struct operator {
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    } types;
};

int main() {


    union intParts parts;
    parts.theInt = 5968145;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n", 
    parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

    // vs

    int theInt = parts.theInt;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n", 
    theInt, *((char*)&theInt+0), *((char*)&theInt+1), *((char*)&theInt+2), *((char*)&theInt+3));

    // or with array syntax which can be a tiny bit incer sometimes

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    theInt, ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], ((char*)&theInt)[3]);

    struct operator op;
    op.type = 0;
    op.types.intNum = 352;
    op.types.floatNum = 121.12;
    op.types.doubleNum = 1201321.1231;

    printf("%d\n", op.types.intNum);
    printf("%f\n", op.types.doubleNum);

    printf("size of intNum: %d\n", sizeof(op.types.intNum));
    printf("size of floatNum: %d\n", sizeof(op.type));
    printf("size of doubleNum: %d\n", sizeof(op.types.doubleNum));
    printf("size of struct operator op: %d\n", sizeof(op));


    

    return 0;
}
