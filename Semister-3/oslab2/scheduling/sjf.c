#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid, at, bt, ct, tat, wt;
    struct process *next;
};

// Function to create a new process node
struct process *create() {
    struct process *newProcess = (struct process *)malloc(sizeof(struct process));
    scanf("%d %d %d", &newProcess->pid, &newProcess->at, &newProcess->bt);
   
    newProcess->ct = newProcess->tat = newProcess->wt = 0;
    newProcess->next = NULL;
    return newProcess;
}

void display(struct process *head) {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    struct process *temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", temp->pid, temp->at, temp->bt, temp->ct, temp->tat, temp->wt);
        temp = temp->next;
    }
}

// Function to perform SJF (Non-Preemptive) scheduling
void calculate(struct process *head, int n) {
    struct process *temp;
    struct process *shortest;
    int completed = 0, currentTime = 0;

    while (completed < n) {
        temp = head;
        shortest = NULL;

        // Find the process with the shortest burst time that has arrived
        while (temp != NULL) {
            if (temp->at <= currentTime && (shortest == NULL || temp->bt < shortest->bt)) {
                shortest = temp;
            }
            temp = temp->next;
        }

        // If no process is available, CPU remains idle
        if (shortest == NULL) {
            printf("CPU is idle at time %d\n", currentTime);
            currentTime++;
            continue;
        }

        // Execute the shortest job
        currentTime += shortest->bt;
        shortest->ct = currentTime;
        shortest->tat = shortest->ct - shortest->at;
        shortest->wt = shortest->tat - shortest->bt;
        completed++;
    }
}

// Main function
int main() {
    int n;
    struct process *head = NULL;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter process id, arrival time, and burst time for process %d: ", i + 1);
        struct process *newProcess = create();

        if (head == NULL) {
            head = newProcess;
        } else {
            struct process *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newProcess;
        }
    }

    calculate(head, n);
    display(head);

    return 0;
}
