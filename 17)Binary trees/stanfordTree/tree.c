#include<stdio.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printArray(int [], int); 
void printPathsRecur(struct node*, int [], int); 
void printPaths(struct node*); 

// insert a new node with the given number in the correct place
// returns the new root pointer which the caller should then use
// (trick to avoid using reference parameters) (aka double pointers)

struct node* insert(struct node* node, int data) {
    // 1. if the tree is empty, return a new, sigle node
    if (node == NULL) {
        return(newNode(data));
    } else {
        // 2. Otherwaise, recur down the tree
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }

        return node; // return the (unchanged node pointer)
    }
}

void pre_order_traversal(struct node* node) {
    if(node != NULL) {
        printf("%d ", node->data);
        pre_order_traversal(node->left);
        pre_order_traversal(node->right);
    }
}

void inorder_traversal(struct node* node) {
    if(node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

void post_order_traversal(struct node* node) {
    if(node != NULL) {
        post_order_traversal(node->left);
        post_order_traversal(node->right);
        printf("%d ", node->data);
    }

}



int size(struct node* node) {
    if(node == NULL) {
        return 0;
    } else {
        return(size(node->left) + 1 + size(node->right));
    }
}

int maxDepth(struct node* node) {
    if(node == NULL) return 0;

    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);

    if(leftDepth > rightDepth) {
        return 1 + leftDepth;
    } else {
        return 1 + rightDepth;
    }
}

int minValue(struct node* node) {
    if(node->left == NULL) return node->data;
    return minValue(node->left);
}


void printPaths(struct node* node) {
    int path[1000];
    printPathsRecur(node, path, 0);
}

void printPathsRecur(struct node* node, int path[], int pathLen) {
    if(node==NULL) return;

    // append node to path array
    path[pathLen] = node->data;
    pathLen++;
    // if a leaf node, print the path that led here
    if(node->left==NULL && node->right == NULL) {
        printArray(path, pathLen);
    } else {
        printPathsRecur(node->left, path, pathLen);
        printPathsRecur(node->right, path, pathLen);
    }

}

void printArray(int ints[], int len) {
    int i;
    for(i = 0; i < len; i++) {
        printf("%d ", ints[i]);
    }
    printf("\n  ");
}

void mirror(struct node* node) {
    // essentally start with root node, and flip its children.
    // repeat that recursively

    if(node == NULL) {
        return;
    }
    //swap
    struct node* tempNode = node->right;
    node->right = node->left;
    node->left = tempNode;

    mirror(node->left);
    mirror(node->right);

}

void doubleTree(struct node* node) {
    if(node == NULL) return;

    struct node* tempNode = node->left;
    node->left = newNode(node->data);
    node->left->left = tempNode;

    doubleTree(node->left->left);
    doubleTree(node->right);

}

int sameTree(struct node* a, struct node* b) {

    if (a == NULL && b == NULL) {
        return 1;
    } else if(a != NULL && b != NULL) {
        if((a->data == b->data) && (sameTree(a->left, b->left) == 1) && (sameTree(a->right, b->right) == 1)) {
            return 1;
        } else {
            return 0;
        }
    } else { // one empty, one is not empty
        return 0;
    }
    

    

  

        
}





int hasPathSum(struct node* node, int sum) {
    
    if(node == NULL) return 0;

    sum -= node->data;
    if(sum == 0 && isLeaf(node) == 1) {
        return 1;
    }

    int left = hasPathSum(node->left, sum);
    int right = hasPathSum(node->right, sum);

    if(left == 1 || right == 1) {
        return 1;
    } else {
        return 0;
    }
}

int isLeaf(struct node* node) {
    if((node->right == NULL) && (node->left == NULL)) {
        return 1; // true
    } else {
        return 0; // false
    }
}



int main() {

    // struct node* node = newNode(10);

    // printf("%d\n", node->data);

    // insert(node, 3);
    // insert(node, 11);
    // insert(node, 4);
    // printf("%d\n", node->left->data);

    // pre_order_traversal(node);
    // printf("\n");
    // inorder_traversal(node);
    // printf("\n");
    // post_order_traversal(node);
    // printf("\n");
    // printf("%d", hasPathSum(node, 17));

    // struct node* node = newNode(10);
    //int values[] = {5, 2, 7, 18, 13, 19};
    // int values[] = {5, 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

    struct node* node = newNode(4);
    int values[] = {2, 5, 1, 3};
    int length = sizeof(values) / sizeof(values[0]);
    for(int i = 0; i < length; i++) {
        insert(node, values[i]);
    }

    printf("Tree Size: %d\n", size(node));
    printf("Max Depth: %d\n", maxDepth(node));
    printf("Min Value: %d\n", minValue(node));
    printf("Print Paths:\n  ");
    printPaths(node);
    printf("\b\b");//two backspaces to undo the indent
    printf("Inorder Traversal: ");
    inorder_traversal(node);
    printf("\n");

    // BEFORE MIRROR
    printf("preorder traversal ");
    pre_order_traversal(node);
    printf("\n");
    printf("[MIRROR]\n");
    mirror(node); // mirror
    // AFTER MIRROR
    printf("preorder traversal ");
    pre_order_traversal(node);
    printf("\n");
    
    struct node* node2 = newNode(2);
    insert(node2, 1);
    insert(node2, 3);

    printf("\nTree 2:\n");
    pre_order_traversal(node2);
    printf("\n[DOUBLE]\n");
    doubleTree(node2);
    printf("Tree Size: %d\n", size(node));
    pre_order_traversal(node2);

    //////////////////////////////////
    // compare two trees
    struct node* n1 = newNode(2);
    insert(n1, 1);
    insert(n1, 3);
    struct node* n2 = newNode(2);
    insert(n2, 1);
    insert(n2, 3);


    printf("\n%d", sameTree(n1, n2));

//        10
//     5      18
//   2   7  14   19

    
    return 0;
}