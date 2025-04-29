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

// Sorting the linked list
void sorting(struct node *head){
    struct node *ptr, *cpt;
    int temp;
    ptr = head;
    while(ptr != NULL && ptr->link != NULL){
        cpt = ptr->link;
        while(cpt != NULL){
            if(ptr->data > cpt->data){
                temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
            cpt = cpt->link;
        }
        ptr = ptr->link;
    }
}


void removedup(struct node* head){
    struct node *ptr = head;
    while(ptr != NULL && ptr->link != NULL){
        if(ptr->data == ptr->link->data){
            struct node* temp = ptr->link;  
            ptr->link = ptr->link->link;    
            free(temp);  
        } else {
            ptr = ptr->link;
        }
    }
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
    head->link = createNode(2);
    head->link->link = createNode(2);
    head->link->link->link = createNode(2);
    head->link->link->link->link = createNode(1);

    printf("Original List:\n");
    Display(head);

    // Sorting the list
    sorting(head);
    printf("\nSorted List:\n");
    Display(head);

    // Removing duplicates
    removedup(head);
    printf("\nList after removing duplicates:\n");
    Display(head);

    return 0;
}
