#include<stdio.h>

struct node {
    int data;
    struct node* next;
};

struct node* BuildOneTwoThree() {
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    return head;
}

int Length(struct node* head) {
    struct node* current = head;
    int count = 0;

    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}


int main() {

    struct node* n = BuildOneTwoThree();
    printf("%d\n", n->data);
    printf("count: %d", Length(n));
    return 0;
}