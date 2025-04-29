#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;         
    int burst_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int burst_time) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->id = id;
    newProcess->burst_time = burst_time;
    newProcess->next = NULL;
    return newProcess;
}

void addProcess(Process** head, int id, int burst_time) {
    Process* newProcess = createProcess(id, burst_time);
    if (*head == NULL) {
        *head = newProcess;
        newProcess->next = *head;  
    } else {
        Process* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newProcess;
        newProcess->next = *head; 
    }
}

void roundRobin(Process** head, int time_quantum) {
    if (*head == NULL) {
        printf("No processes to schedule.\n");
        return;
    }

    Process* current = *head;
    Process* prev = NULL;
    int time = 0; 

    while (*head != NULL) {
        if (current->burst_time > 0) {
            printf("Process %d runs for %d units\n", current->id, 
                   (current->burst_time > time_quantum ? time_quantum : current->burst_time));
            time += (current->burst_time > time_quantum) ? time_quantum : current->burst_time;
            current->burst_time -= time_quantum;

            if (current->burst_time <= 0) {
                printf("Process %d completed at time %d\n", current->id, time);
                
                if (current->next == current) {
                    free(current);
                    *head = NULL;
                    return;
                }

                Process* temp = current;
                if (prev != NULL) {
                    prev->next = current->next;
                }

                if (*head == current) {
                    *head = current->next;
                }

                current = current->next;
                free(temp);
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
}

int main() {
    Process* head = NULL;
    int n, i, burst_time, time_quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &burst_time);
        addProcess(&head, i, burst_time);
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    printf("\nExecuting Round Robin Scheduling:\n");
    roundRobin(&head, time_quantum);

    return 0;
}