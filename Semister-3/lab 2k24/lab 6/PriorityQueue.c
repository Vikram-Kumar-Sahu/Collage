#include <stdio.h>
#include <stdlib.h>

#define Max 5    
#define Pri 4   

int cq[Pri][Max];              
int rear[Pri] = {-1, -1, -1, -1};  
int front[Pri] = {-1, -1, -1, -1}; 

// Function to add an element to a specific priority queue
void ENQUEUE() {
    int n, p;
    printf("Enter the priority level (0 to %d): ", Pri - 1);
    scanf("%d", &p);
    
    if (p < 0 || p >= Pri) {
        printf("Invalid priority level.\n");
        return;
    }

    if ((rear[p] + 1) % Max == front[p]) {
        printf("Queue at priority %d is full.\n", p);
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &n);

    if (rear[p] == -1 && front[p] == -1) {  
        rear[p] = front[p] = 0;
    } else {
        rear[p] = (rear[p] + 1) % Max;
    }
    
    cq[p][rear[p]] = n;
    printf("Inserted element %d in priority %d queue.\n", n, p);
}

void DEQUEUE() {
    int p;
    printf("Enter the priority level to dequeue (0 to %d): ", Pri - 1);
    scanf("%d", &p);

    if (p < 0 || p >= Pri) {
        printf("Invalid priority level.\n");
        return;
    }

    if (rear[p] == -1 && front[p] == -1) { 
        printf("Queue at priority %d is empty.\n", p);
        return;
    }

    int d = cq[p][front[p]];
    printf("Deleted element %d from priority %d.\n", d, p);

    if (front[p] == rear[p]) {  
        front[p] = rear[p] = -1;
    } else {
        front[p] = (front[p] + 1) % Max;
    }
}


void DISPLAY() {
    for (int i = 0; i < Pri; i++) {
        if (front[i] == -1 && rear[i] == -1) {
            printf("Queue at priority %d is empty.\n", i);
        } else {
            printf("Queue at priority %d: ", i);
            int j = front[i];
            while (1) {
                printf("%d ", cq[i][j]);
                if (j == rear[i]) break;
                j = (j + 1) % Max;
            }
            printf("\n");
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                ENQUEUE();
                break;
            case 2:
                DEQUEUE();
                break;
            case 3:
                DISPLAY();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;  
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
