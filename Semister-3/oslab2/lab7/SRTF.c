#include <stdio.h>

#define MAX_PROCESSES 100

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void calculateSRTF(struct Process processes[], int n) {
    int time = 0, completed = 0, min_index;
    int min_remaining = __INT_MAX__;
    int is_completed[MAX_PROCESSES] = {0};
    
    while (completed < n) {
        min_index = -1;
        min_remaining = __INT_MAX__;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && !is_completed[i] && processes[i].remaining_time < min_remaining) {
                min_remaining = processes[i].remaining_time;
                min_index = i;
            }
        }
        
        if (min_index == -1) {
            time++;
            continue;
        }
        
        processes[min_index].remaining_time--;
        time++;
        
        if (processes[min_index].remaining_time == 0) {
            processes[min_index].completion_time = time;
            processes[min_index].turnaround_time = processes[min_index].completion_time - processes[min_index].arrival_time;
            processes[min_index].waiting_time = processes[min_index].turnaround_time - processes[min_index].burst_time;
            is_completed[min_index] = 1;
            completed++;
        }
    }
}

void displayResults(struct Process processes[], int n) {
    float total_waiting_time = 0, total_turnaround_time = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time,
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    int n;
    struct Process processes[MAX_PROCESSES];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i].pid = i + 1;
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    calculateSRTF(processes, n);
    displayResults(processes, n);
    
    return 0;