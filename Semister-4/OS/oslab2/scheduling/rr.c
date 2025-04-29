#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid, AT, BT, remaining_time, CT, TAT, WT;
    struct Process *next;
};

struct Process* create() {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    scanf("%d %d %d", &newProcess->pid, &newProcess->AT, &newProcess->BT);
    newProcess->remaining_time = newProcess->BT;
    newProcess->next = NULL;
    return newProcess;
}

void calculate_rr(struct Process* head, int time_quantum) {
    int currentTime = 0, completed = 0, n = 0;
    struct Process* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }

    while (completed < n) {
        temp = head;
        while (temp != NULL) {
            if (temp->AT <= currentTime && temp->remaining_time > 0) {
                if (temp->remaining_time <= time_quantum) {
                    currentTime += temp->remaining_time;
                    temp->remaining_time = 0;
                    temp->CT = currentTime;
                    temp->TAT = temp->CT - temp->AT;
                    temp->WT = temp->TAT - temp->BT;
                    completed++;
                } else {
                    currentTime += time_quantum;
                    temp->remaining_time -= time_quantum;
                }
            }
            temp = temp->next;
        }
    }
}

void display(struct Process* head) {
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    while (head != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", head->pid, head->AT, head->BT, head->CT, head->TAT, head->WT);
        head = head->next;
    }
}

int main() {
    struct Process* head = NULL;
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    for (int i = 0; i < n; i++) {
        printf("Enter PID, AT, and BT for process %d: ", i + 1);
        struct Process* newProcess = create();
        if (head == NULL) {
            head = newProcess;
        } else {
            struct Process* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newProcess;
        }
    }

    calculate_rr(head, time_quantum);
    display(head);

    return 0;
}