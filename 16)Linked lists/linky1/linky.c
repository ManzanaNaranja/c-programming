#include<stdio.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) { // interates over a linked list and printes out vals
    node_t * current = head;

    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
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

    // explanation of double pointers in funtiion 
    // https://dev-notes.eu/2018/07/double-pointers-and-linked-list-in-c/
void addFirst(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;

    *head = new_node;
}

// Removing the first item (shift)

int shift(node_t ** head) {
    int retval = -1;
    node_t * next_node = NULL;

    if(*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval; // the value shifted off
}

// Removing the last item of the list (pop)

int pop(node_t * head) {
    int retval = 0;
    // if there is only one item in the list, remove it
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }
    node_t * current = head;
    while(current->next->next != NULL) {
        current = current->next;
    }

    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

// Removes by Index
int remove_index(node_t ** head, int n) {
    int i = 0; 
    int retval = -1;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0) {
        return shift(head);
    }

    for(i = 0; i < n-1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }
    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

// removes by value

int remove_val(node_t ** head, int value) {
    node_t * current = *head;
    node_t * temp_node = NULL;

    if(current->val == value) {
        shift(head);
        return 1;
    }

    while(current != NULL) {
        if(current->next->val == value) {
            temp_node = current->next;
            current->next = temp_node->next;
            free(temp_node);
            return 1;
        }

        current = current->next;
    }

    return 0;

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
    addLast(head, 99);
    addLast(head, 155);
    
    // node_t ** h = &head; // don't actually need to create a double pointer,
    // just pass in address of the head pointer
    addFirst(&head, 314);



   // printf("%d", head->val);
   print_list(head);
   shift(&head);
   print_list(head);
   shift(&head);
   print_list(head);
   pop(head);
   print_list(head);
   remove_index(&head, 3);
   print_list(head);
   remove_index(&head, 1);
   print_list(head);
   addLast(head, 100);
   addLast(head, 123);
   addLast(head, 22);
   print_list(head);
   remove_val(&head, 123);
   print_list(head);
   remove_index(&head, 2);
   remove_val(&head, 22);
   print_list(head);
   remove_val(&head, 28882);
   print_list(head);
   addLast(head, 22);
   print_list(head);


   

   

    return 0;
}

