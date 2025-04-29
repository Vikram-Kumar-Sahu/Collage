#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};


void Display(struct node* ptr){
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

void add(struct node* ptr) {
    while(ptr != NULL) {
        ptr->data += 3;  // Add 3 to the data in the current node
        ptr = ptr->link; // Move to the next node
    }
}

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

int main() {
    // Creating a linked list for demonstration
    struct node* head = createNode(2);
    head->link = createNode(2);
    head->link->link = createNode(2);
    head->link->link->link = createNode(2);
    head->link->link->link->link = createNode(1);

    printf("Original List:\n");
    Display(head);

   
    add(head);
    printf("\nthe added ll:\n");
    Display(head);

    return 0;
}