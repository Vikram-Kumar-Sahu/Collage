#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid, at, bt, ct, tat, wt, bt2;
    struct process *next;
};

// Function to create a new process node
struct process *create() {
    struct process *newProcess = (struct process *)malloc(sizeof(struct process));
    scanf("%d %d %d", &newProcess->pid, &newProcess->at, &newProcess->bt);
    newProcess->bt2 = newProcess->bt; // Store original burst time
    newProcess->ct = newProcess->tat = newProcess->wt = 0;
    newProcess->next = NULL;
    return newProcess;
}

// Function to perform SRTF scheduling
void calculate(struct process *head, int n) {
    int completed = 0, currentTime = 0;
    struct process *temp;
    
    while (completed < n) {
        struct process *shortest = NULL;
        temp = head;

        // Find the process with the shortest remaining time
        while (temp != NULL) {
            if (temp->at <= currentTime && temp->bt > 0 &&
                (shortest == NULL || temp->bt < shortest->bt)) {
                shortest = temp;
            }
            temp = temp->next;
        }

        // If no process is ready, CPU remains idle
        if (shortest == NULL) {
            printf("CPU is idle at time %d\n", currentTime);
            currentTime++;
            continue;
        }

        // Execute the process for 1 unit of time
        shortest->bt--;
        currentTime++;

        // If the process completes execution
        if (shortest->bt == 0) {
            completed++;
            shortest->ct = currentTime;
            shortest->tat = shortest->ct - shortest->at;
            shortest->wt = shortest->tat - shortest->bt2; // Use original burst time
        }
    }
}

// Function to display process details
void display(struct process *head) {
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    while (head != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", head->pid, head->at, head->bt2, head->ct, head->tat, head->wt);
        head = head->next;
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
