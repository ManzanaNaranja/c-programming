#include<stdio.h>

struct node{
    int data;
    struct node * left, *right;  
};

struct node * root = NULL;

void insert(int data) {
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->left = NULL;
    tempNode->right = NULL;

    // if tree is empty, create root node
    if(root == NULL) {
        root = tempNode;
    } else {
        current = root;
        parent = NULL;

        while(1) {
            parent = current;

            //go to left of the tree
            if(data < parent->data) {
                current = current->left;

                //insert to the left
                if(current == NULL) {
                    parent->left = tempNode;
                    return;
                }
            } else { // go to right of the tree
                current = current->right;
                if(current == NULL) { // insert to the right
                    parent->right = tempNode;
                    return;
                }
            }
        }
    }
}

struct node* search(int data) {
    struct node *current = root;
    printf("Visiting elements: ");

    while(current->data != data) {
        printf("%d ", current->data);
        
        //go to left tree
        if(data < current->data) {
            current = current->left;
        } else { // else, go to right tree
            current = current->right;
        }

        if(current == NULL) {
            return NULL;
        }
    }
    return current;
}

void pre_order_traversal(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

void inorder_traversal(struct node* root) {
    if(root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void post_order_traversal(struct node* root) {
    if(root != NULL) {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int i;
    int array[7] = {27, 14, 35, 10, 19, 31, 42};
    for(i = 0; i < 7; i++) {
        insert(array[i]);
    }

    i = 31;
    struct node * temp = search(i);
    if(temp != NULL) {
        printf("[%d] Element found.\n", temp->data);
    } else {
        printf("[ x ] Element not found (%d).\n",i);
    }

    i = 15;
    temp = search(i);
    if(temp != NULL) {
        printf("[%d] Element found.\n", temp->data);
    } else {
        printf("[ x ] Element not found (%d).\n",i);
    }

   printf("\nPreorder traversal: ");
   pre_order_traversal(root);

   printf("\nInorder traversal: ");
   inorder_traversal(root);

   printf("\nPost order traversal: ");
   post_order_traversal(root);       

    
    // insert(5);
    // insert(11);
    // insert(1);
    // insert(2);
    // printf("%d", root->left->right->data); 



    return 0;
}