#include <stdio.h>
#include <stdlib.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        // Queue is empty, add the first element
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front) {
        // Queue is full
        printf("Queue is full\n");
    }
    else {
        // Normal enqueue operation
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        // Queue is empty
        printf("Queue is empty\n");
    }
    else if (front == rear) {
        // Queue has only one element, reset after dequeue
        printf("Dequeued element: %d\n", queue[front]);
        front = rear = -1;
    }
    else {
        // Normal dequeue operation
        printf("Dequeued element: %d\n", queue[front]);
        front = (front + 1) % N;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        // Queue is empty
        printf("Queue is empty\n");
    }
    else {
        // Display elements from front to rear in circular manner
        int i = front;
        printf("Queue is: ");
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", queue[rear]);  // Print the last element
    }
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
