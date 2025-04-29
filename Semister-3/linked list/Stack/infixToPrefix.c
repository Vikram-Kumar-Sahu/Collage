#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int top;
    int size;
    char *arr;
};

int stackTop(struct stack* sp) {
    if (sp->top == -1) {
        return -1;
    }
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack* ptr, char val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    } else {
        ptr->arr[++(ptr->top)] = val;
    }
}

char pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        return ptr->arr[(ptr->top)--];
    }
}

int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 3;
    } else if (ch == '+' || ch == '-') {
        return 2;
    } else if (ch == '(' || ch == ')') {
        return 1;
    } else {
        return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to reverse the infix expression and swap parentheses
void reverseAndSwapParentheses(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') {
            str[i] = ')';
        } else if (str[i] == ')') {
            str[i] = '(';
        }
    }
}

char* infixToPrefix(char *infix) {
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    char *prefix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        // If character is an operand (not an operator and not parentheses)
        if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')') {
            prefix[j++] = infix[i++];
        }
        // If we encounter an opening parenthesis
        else if (infix[i] == '(') {
            push(sp, infix[i++]);
        }
        // If we encounter a closing parenthesis
        else if (infix[i] == ')') {
            while (!isEmpty(sp) && stackTop(sp) != '(') {
                prefix[j++] = pop(sp);
            }
            pop(sp); // Discard the '(' from the stack
            i++;
        }
        // If character is an operator
        else {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))) {
                prefix[j++] = pop(sp);
            }
            push(sp, infix[i++]);
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(sp)) {
        prefix[j++] = pop(sp);
    }
    prefix[j] = '\0';

    // Reverse the result to get the correct prefix expression
    reverseAndSwapParentheses(prefix);

    return prefix;
}

int main() {
    char infix[25] = {'\0'};
    printf("Enter infix expression: ");
    scanf("%s", infix);

    printf("Infix Expression: %s\n", infix);

    // Reverse the input infix expression and swap parentheses
    reverseAndSwapParentheses(infix);
    printf("Reversed and Swapped Infix: %s\n", infix);

    // Get the prefix expression
    char *prefix = infixToPrefix(infix);
    printf("Prefix Expression: %s\n", prefix);

    free(prefix);
    return 0;
}
