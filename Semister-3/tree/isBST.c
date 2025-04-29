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

// Function to check if a binary tree is a BST
int isBST(struct node* root){
    static struct node* prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    return 1;
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

    // Check if the tree is a Binary Search Tree (BST)
    if(isBST(p)){
        printf("The tree is a Binary Search Tree.\n");
    }
    else{
        printf("The tree is not a Binary Search Tree.\n");
    }

    return 0;
}
