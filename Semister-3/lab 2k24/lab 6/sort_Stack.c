#include <stdio.h>
#include <stdbool.h>
#define MAX 100
struct Stack {
    int arr[MAX];
    int top;
};
bool isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}
bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", element);
    } else {
        stack->arr[++(stack->top)] = element;
        printf("%d pushed to stack.\n", element);
    }
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Cannot pop element.\n");
        return -1;
    } else {
        return stack->arr[(stack->top)--];
    }
}

void sortedInsert(struct Stack* stack, int element) {
    if (isEmpty(stack) || stack->arr[stack->top] <= element) {
        push(stack, element);
        return;
    }
    int temp = pop(stack);
    sortedInsert(stack, element);
    push(stack, temp);
}
void sortStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        return;
    }

    int temp = pop(stack);
    sortStack(stack);
    sortedInsert(stack, temp);
}
void printStack(struct Stack* stack) {
    printf("Stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    stack.top = -1;

    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Sort Stack\n4. Display Stack\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            
            value = pop(&stack);
            if (value != -1) {
                printf("Popped element: %d\n", value);
            }
            break;
        case 3:
            
            sortStack(&stack);
            printf("Stack sorted.\n");
            break;
        case 4:
        
            printStack(&stack);
            break;
        case 5:
            
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
