#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

// Function to display the linked list
void Display(struct node* ptr){
    while(ptr != NULL){
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}

// Function to remove alternate nodes
struct node* alter(struct node* head){
    struct node* ptr = head;
    struct node* temp;

    while(ptr != NULL && ptr->link != NULL){
        temp = ptr->link;            // Store the next node
        ptr->link = temp->link;       // Skip the next node
        free(temp);                   // Free the skipped node
        ptr = ptr->link;              // Move to the next pair of nodes
    }

    return head;
}

// Helper function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

int main() {
    // Creating a linked list for demonstration
    struct node* head = createNode(2);
    head->link = createNode(3);
    head->link->link = createNode(4);
    head->link->link->link = createNode(5);
    head->link->link->link->link = createNode(6);

    printf("Original List:\n");
    Display(head);

    // Alter the list by removing alternate nodes
    head = alter(head);
    
    printf("\nList after removing alternate nodes:\n");
    Display(head);

    return 0;
}
