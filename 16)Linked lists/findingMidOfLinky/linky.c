#include<stdio.h>

struct Node{
    int data;
    struct Node* next;

};


void printMiddle(struct Node *head) {
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    while(fast_ptr != NULL && fast_ptr->next != NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    printf("The middle element is [%d]\n\n", slow_ptr->data);
}

void addLast(struct Node *head, int data) {
    struct Node * current = head;

    while(current->next != NULL) {
        current = current -> next;
    }

    current->next = (struct Node *) malloc(sizeof(struct Node));
    current->next->data = data;
    current->next->next = NULL;

}


int main() {

    struct Node* head = (struct Node *) malloc(sizeof(struct Node));
    head->data = 5;
    head->next = NULL;
    addLast(head, 2);
    addLast(head, 4);
    addLast(head, 10);
    addLast(head, 25);

    printMiddle(head);

    return 0;
}