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

void swap(struct node** head, int k) {
    if (*head == NULL || k <= 0) {
        printf("Invalid position for swap.\n");
        return;
    }

    struct node* prev = NULL;
    struct node* curr = *head;
    struct node* next = NULL;

    // Move to the k-th node
    for (int i = 1; i < k && curr != NULL; i++) {
        prev = curr;
        curr = curr->link;
    }

    // Ensure that both k-th and (k+1)-th nodes exist
    if (curr == NULL || curr->link == NULL) {
        printf("Cannot perform swap at position %d\n", k);
        return;
    }

    next = curr->link; // (k+1)-th node

    // Perform the swap
    if (prev != NULL) {
        prev->link = next;  // Previous node points to (k+1)-th node
    } else {
        *head = next;  // If swapping involves the head node
    }

    curr->link = next->link;  // k-th node points to (k+2)-th node
    next->link = curr;        // (k+1)-th node points to k-th node
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
    head->link = createNode(3);
    head->link->link = createNode(4);
    head->link->link->link = createNode(5);
    head->link->link->link->link = createNode(6);

    printf("Original List:\n");
    Display(head);

    // Swap the 2nd and 3rd nodes (i.e., swap node 3 and node 4)
    swap(&head, 2);
    
    printf("\nList after swapping 2nd and 3rd nodes:\n");
    Display(head);

    return 0;
}