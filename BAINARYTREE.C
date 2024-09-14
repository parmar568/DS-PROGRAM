#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Define the node structure
struct node {
    int data;
    struct node *left, *right;
};

// Function prototypes
struct node* create();
void inorder(struct node *root);

int main() {
    struct node *root;
    root = create();
    
    // Optional: Call inorder function to test the tree creation
    printf("\nInorder traversal of the created tree:\n");
    inorder(root);
    
    return 0;
}

// Function to create a new node and construct the binary tree
struct node* create() {
    struct node *temp;
    int data, choice;

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("\n 0 exit");
    printf("\n 1 enter a new node");
    printf("\n 2 enter your choice: ");
    scanf("%d", &choice);

    if (choice == 0) {
        free(temp);
        return NULL;
    } else if (choice == 1) {
        printf("Enter the data: ");
        scanf("%d", &data);
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        printf("Enter the left child of %d:\n", data);
        temp->left = create();
        printf("Enter the right child of %d:\n", data);
        temp->right = create();
        return temp;
    } else {
        printf("Invalid choice.\n");
        free(temp);
        return NULL;
    }
}

// Function to perform inorder traversal of the binary tree
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
