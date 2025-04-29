#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q) {
    return q->r == q->f;
}

int isFull(struct queue *q) {
    return q->r == q->size - 1;
}

void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("The queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("The queue is empty\n");
    } else {
        q->f++;
        a = q->arr[q->f];
        printf("Dequeued element: %d\n", a);
    }
    return a;
}

void display(struct queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty\n");
        return;
    } else {
        printf("Queue elements: ");
        for (int i = q->f + 1; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int choice, val;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Check if empty\n4. Check if full\n5. Display Queue\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                if (isEmpty(&q)) {
                    printf("The queue is empty.\n");
                } else {
                    printf("The queue is not empty.\n");
                }
                break;
            case 4:
                if (isFull(&q)) {
                    printf("The queue is full.\n");
                } else {
                    printf("The queue is not full.\n");
                }
                break;
            case 5:
                display(&q);
                break;
            case 6:
                free(q.arr);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
