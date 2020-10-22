#include<stdio.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) { // interates over a linked list and printes out vals
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

// adds an item to the end of the list
    // iterate over pointers until reach the last item
    //create a new done and allocate memory for it
    // then, sent val to specified value and set next node to NULL

void addLast(node_t * head, int val) { 
    node_t * current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    // now we can add a new variable
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

// add item to beginning of list
    // 1) Create a new item and set its value
    // 2) Link the new item to point to the head of the list
    // 3) Set the head of the list to be our new item

void addFirst(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}



int main() {




    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if(head == NULL) {
        return 1; // if malloc returned a null
    }

    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = (node_t *) malloc(sizeof(node_t));
    head->next->next->val = 11;
    head->next->next->next = NULL;
    addLast(head, 3);
    addLast(head, 10010);
    addLast(head, 1002222222);
    
    node_t ** h = &head;
    addFirst(h, 314);



   // printf("%d", head->val);
   print_list(head);

    return 0;
}

