#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node *n;
    n = (struct node*) malloc(sizeof(struct node));  
    n->data = data;  
    n->left = NULL;  
    n->right = NULL;  
    return n;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);  
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);  
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);  
        printf("%d ", root->data);  
        inorder(root->right); 
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  
        preorder(root->left);  
        preorder(root->right); 
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);  
        postorder(root->left);  
        postorder(root->right); 
    }
}

struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}


struct node* inorderPredecessor(struct node* root) {
    root = root->left;
    while (root && root->right != NULL) {
        root = root->right;
    }
    return root;
}


struct node* deleteNode(struct node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);  
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value); 
    }
    else {
        
        if (root->left == NULL) { 
            struct node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {  
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        
        struct node* ipre = inorderPredecessor(root);  
        root->data = ipre->data;  
        root->left = deleteNode(root->left, ipre->data); 
    }
    return root;
}

int main() {
    struct node *root = NULL;  
    int choice, value;
    struct node *searchResult;

    while (1) {
        
        printf("\n\nBinary Search Tree Operations Menu\n");
        printf("1. Insert a node\n");
        printf("2. Display Preorder Traversal\n");
        printf("3. Display Postorder Traversal\n");
        printf("4. Display Inorder Traversal\n");
        printf("5. Search for a value\n");
        printf("6. Delete a node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d inserted successfully!\n", value);
                break;

            case 2:
                
                printf("Preorder traversal of the BST: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                
                printf("Postorder traversal of the BST: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                
                printf("Inorder traversal of the BST: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchResult = search(root, value);

                if (searchResult != NULL) {
                    printf("Value %d found in the BST.\n", searchResult->data);
                } else {
                    printf("Value %d not found in the BST.\n", value);
                }
                break;

            case 6:
               
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Value %d deleted (if it existed)!\n", value);
                break;

            case 7:
                
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
