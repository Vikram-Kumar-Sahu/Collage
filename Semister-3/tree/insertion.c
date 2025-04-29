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

void insert(struct node* root,int key){
    struct node* prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("can not insert");
            return;}

    
    else if (key<root->data)
    {
        root=root->left;
        /* code */
    }
    else
        root=root->right;
}
    struct node* new=createNode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
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
    insert(p,7);
}