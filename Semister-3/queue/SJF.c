#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    struct Process* next;
} Process;

void sortByBurstTime(Process** head, int time);
void displayProcesses(Process* head);

int main() {
    int n, i;
    Process* head = NULL;
    Process* temp = NULL;
    Process* newProcess = NULL;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newProcess = (Process*)malloc(sizeof(Process));
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &newProcess->at, &newProcess->bt);
        newProcess->pid = i + 1;
        newProcess->next = NULL;

        if (head == NULL) {
            head = newProcess;
            temp = head;
        } else {
            temp->next = newProcess;
            temp = temp->next;
        }
    }

    temp = head;
    int time = 0;
    while (temp != NULL) {
        sortByBurstTime(&temp, time);

        if (time < temp->at)
            time = temp->at;  

        temp->ct = time + temp->bt;
        temp->tat = temp->ct - temp->at;
        temp->wt = temp->tat - temp->bt;

        time = temp->ct;
        temp = temp->next;
    }

    displayProcesses(head);

    // Free the allocated memory
    temp = head;
    while (temp != NULL) {
        Process* toFree = temp;
        temp = temp->next;
        free(toFree);
    }

    return 0;
}

void displayProcesses(Process* head) {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    Process* temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", temp->pid, temp->at, temp->bt, temp->ct, temp->tat, temp->wt);
        temp = temp->next;
    }
}

// Implement sortByBurstTime function
void sortByBurstTime(Process** head, int time) {
    Process* current = *head;
    Process* selected = NULL;
    Process* prev = NULL;
    Process* prevSelected = NULL;

    while (current != NULL && current->at <= time) {
        if (selected == NULL || current->bt < selected->bt) {
            selected = current;
            prevSelected = prev;
        }
        prev = current;
        current = current->next;
    }

    // If a suitable process is found, move it to the head of the list
    if (selected != NULL && selected != *head) {
        if (prevSelected != NULL) {
            prevSelected->next = selected->next;
        }
        selected->next = *head;
        *head = selected;
    }
}
