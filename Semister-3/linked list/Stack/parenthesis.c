#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    char* arr;
};

int isEmpty(struct stack* ptr) {
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct stack* ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    } else 
        return 0;
}

void push(struct stack* ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow\n");
    } else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return '\0';  // Return '\0' as an error value for char
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int paranthesisMatching(char* exp) {
    // Allocate memory for stack
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    // Traverse the expression
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(sp, '(');  // Push opening parenthesis
        } else if (exp[i] == ')') {
            if (isEmpty(sp)) {
                return 0;  // Unmatched closing parenthesis
            }
            pop(sp);  // Pop matching opening parenthesis
        }
    }

    // Check if the stack is empty after processing
    if (isEmpty(sp)) {
        return 1;  // Parentheses are balanced
    } else {
        return 0;  // Unmatched opening parenthesis
    }
}

int main() {
    char* exp = "((B)(*----$$q)";
    if (paranthesisMatching(exp)) {
        printf("Matching\n");
    } else {
        printf("Not Matching\n");
    }
    return 0;
}
