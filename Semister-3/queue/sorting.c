#include <stdio.h>
#include <stdlib.h>

struct Node {
    int processId;
    int burstTime;
    struct Node* next;
};

void enqueue(struct Node** head, int processId, int burstTime);
void FCFS(struct Node* head); 
int main() {
    struct Node* head = NULL;

  
    enqueue(&head, 1, 5);
    enqueue(&head, 2, 2);
    enqueue(&head, 3, 3);

    printf("FCFS Scheduling:\n");
    FCFS(head);

    return 0;
}


void enqueue(struct Node** head, int processId, int burstTime) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->processId = processId;
    newNode->burstTime = burstTime;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void FCFS(struct Node* head) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    int timeElapsed = 0;

    struct Node* temp = head;

    while (temp != NULL) {
        int waitingTime = timeElapsed;
        int turnaroundTime = waitingTime + temp->burstTime;

        totalWaitingTime += waitingTime;
        totalTurnaroundTime += turnaroundTime;

        printf("Process %d: Burst Time = %d, Waiting Time = %d, Turnaround Time = %d\n",
               temp->processId, temp->burstTime, waitingTime, turnaroundTime);

        timeElapsed += temp->burstTime;
        temp = temp->next;
    }

    int numberOfProcesses = 3; 
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / numberOfProcesses);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / numberOfProcesses);
}