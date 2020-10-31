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

int Length2(struct node* head) {
    struct node* current = head;
    int count = 0;
    for(current = head; current != NULL; current=current->next) {
        count++;
    }
    return count;
}

void Push(struct node** headRef, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

struct node* AddAtHead() {
    struct node* head = NULL;
    int i;

    for(i = 1; i < 6; i++) {
        Push(&head, i);
    }

    // head = {5, 4,3,2,1};

    return head;
}

struct node* BuildFromEnd() {
    struct node* head = NULL;
    struct node* tail;
    int i;
    Push(&head, 1);

    tail = head;
    for(i = 2; i < 6; i++) {
        Push(&(tail->next), i); // add node at tail->next
        tail=tail->next; // advance tail to point to last node
    }

    return head; // head == {1, 2, 3, 4, 5};
}

void printLinkie(struct node* head) {
    // [1 => 2 => 4 => 5]
    printf("[");
    struct node* current = head;
   while(current != NULL) {
       
       printf("%d", current->data);
       if(current->next != NULL) {
           printf(" => ");
       }
       current = current->next;

       
   }
   printf("]\n");
}

struct node* BuildWithDummyNode() {
    struct node dummy;
    struct node* tail = &dummy;

    dummy.next = NULL;

    for(int i = 1; i<6; i++) {
        Push(&(tail->next), i);
        tail = tail->next;
    }
    return dummy.next;
}

struct node* BuildWithLocalRef() {
    struct node* head = NULL;
    struct node** lastPtrRef = &head;

    for(int i = 1; i<6;i++) {
        Push(lastPtrRef, i);
        lastPtrRef= &((*lastPtrRef)->next);
    }

    return head;
}

void AppendNode(struct node** headRef, int num) {
    struct node* current = *headRef;
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = num;
    newNode->next = NULL;

    if(current == NULL) {
        *headRef = newNode; // manipulates head node, thats why they used double pointer
    } else {
        while(current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}


int main() {

    struct node* head = NULL;
    Push(&head, 1);
    Push(&head, 2);
    Push(&head, 3);
    printf("Length: %d\n", Length2(head));
    printLinkie(head);

    struct node* n = AddAtHead();
    printLinkie(n);
    printLinkie(BuildFromEnd());
    printLinkie(BuildWithDummyNode());
    struct node* nn = BuildWithLocalRef();
    AppendNode(&nn, 100);
    printLinkie(nn);
    return 0;
}