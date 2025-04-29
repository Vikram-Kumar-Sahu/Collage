#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* top = NULL;

int isEmpty(node* tp) {
    return (tp == NULL);  // Corrected to check the passed pointer instead of global top
}

int isFull(node* tp) {
    node* p = (node*)malloc(sizeof(node));
    if (p == NULL) {
        return 1;
    } else {
        free(p);  // Free allocated memory to avoid memory leaks
        return 0;
    }
}

node* push(node* tp, int x) {
    if (isFull(tp)) {
        printf("Stack Full\n");
        return tp;  // Return tp without any changes
    } else {
        node* n = (node*)malloc(sizeof(node));
        n->data = x;
        n->next = tp;
        return n;  // Return the new top of the stack
    }
}

int pop(node** tp) {
    if (isEmpty(*tp)) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 to indicate an error
    } else {
        node* n = *tp;
        *tp = (*tp)->next;  // Move top to the next node
        int x = n->data;
        free(n);
        return x;
    }
}

void linkedListTraversal(node* tp) {
    if (tp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while (tp != NULL) {
        printf("Element: %d\n", tp->data);
        tp = tp->next;
    }
}

int peek(int pos){
    node* ptr=top;
    for(int i=0;(i<pos-1&&ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;

    }
    else{
        return -1;
    }
}
int main() {
    int choice, value,pos;

    do {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                top = push(top, value);  // Update the top after push
                break;
            case 2:
                value = pop(&top);  // Pass the address of top to update it
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                linkedListTraversal(top);
                break;
            case 4:
            
                printf("Enter the pos: ");
                scanf("%d", &pos);
                value=peek(pos);
                printf("peek value: %d\n", value);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
