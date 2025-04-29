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

struct node* search(struct node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(root->data<key)
    {
        return search(root->right,key);
    }
    else{
        return search(root->left,key);
    }
}
int main(){
    // Creating the nodes
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    // Linking the nodes to form the tree
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->right = p4;

    if(search(p,1)!=NULL){
        printf("element is present");
    }
    else
        printf("not present");
}