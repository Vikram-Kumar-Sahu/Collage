#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Pre-order traversal: root -> left -> right
void preOrder(struct node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal: left -> right -> root
void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

// In-order traversal: left -> root -> right
void inOrder(struct node* root){
     if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main(){
    // Creating the nodes
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    // Linking the nodes to form the tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->right = p4;

    // Pre-order traversal
    printf("Pre-order: ");
    preOrder(p);
    printf("\n");

    // Post-order traversal
    printf("Post-order: ");
    postOrder(p);
    printf("\n");

    // In-order traversal
    printf("In-order: ");
    inOrder(p);
    printf("\n");

    return 0;
}
