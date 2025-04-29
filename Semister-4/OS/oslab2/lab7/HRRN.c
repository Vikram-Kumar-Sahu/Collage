#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    float response_ratio;
    int is_completed;
    struct Process* next;
};

struct Process* createProcess(int pid, int arrival_time, int burst_time) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->pid = pid;
    newProcess->arrival_time = arrival_time;
    newProcess->burst_time = burst_time;
    newProcess->completion_time = 0;
    newProcess->waiting_time = 0;
    newProcess->turnaround_time = 0;
    newProcess->response_ratio = 0.0;
    newProcess->is_completed = 0;
    newProcess->next = NULL;
    return newProcess;
}

void calculateHRRN(struct Process* head, int n) {
    int time = 0, completed = 0;
    while (completed < n) {
        struct Process* current = head;
        struct Process* maxProcess = NULL;
        float max_response_ratio = -1.0;

        while (current != NULL) {
            if (!current->is_completed && current->arrival_time <= time) {
                int waiting_time = time - current->arrival_time;
                float response_ratio = (float)(waiting_time + current->burst_time) / current->burst_time;
                
                if (response_ratio > max_response_ratio) {
                    max_response_ratio = response_ratio;
                    maxProcess = current;
                }
            }
            current = current->next;
        }
        
        if (maxProcess == NULL) {
            time++;
            continue;
        }
        
        maxProcess->completion_time = time + maxProcess->burst_time;
        maxProcess->turnaround_time = maxProcess->completion_time - maxProcess->arrival_time;
        maxProcess->waiting_time = maxProcess->turnaround_time - maxProcess->burst_time;
        maxProcess->is_completed = 1;
        
        time += maxProcess->burst_time;
        completed++;
    }
}

void displayResults(struct Process* head, int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;
    struct Process* current = head;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    while (current != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", current->pid, current->arrival_time, current->burst_time,
               current->completion_time, current->turnaround_time, current->waiting_time);
        total_waiting_time += current->waiting_time;
        total_turnaround_time += current->turnaround_time;
        current = current->next;
    }
    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;
    struct Process* head = NULL;
    struct Process* tail = NULL;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int arrival_time, burst_time;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_time, &burst_time);
        
        struct Process* newProcess = createProcess(i + 1, arrival_time, burst_time);
        if (head == NULL) {
            head = newProcess;
            tail = newProcess;
        } else {
            tail->next = newProcess;
            tail = newProcess;
        }
    }
    
    calculateHRRN(head, n);
    displayResults(head, n);
    
    return 0;
}