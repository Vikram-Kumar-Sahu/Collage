#include <stdio.h>
#include <stdlib.h>


struct process {
    int pid;
    int at;   
    int bt;   
    int ct;   
    int tat;  
    int wt;   
    struct process* next; 
};

struct process* createProcess(int pid, int at, int bt) {
    struct process* newprocess = (struct process*)malloc(sizeof(struct process));
    newprocess->pid = pid;
    newprocess->at = at;
    newprocess->bt = bt;
    newprocess->ct = 0;
    newprocess->tat = 0;
    newprocess->wt = 0;
    newprocess->next = NULL;
    return newprocess;
}

void appendProcess(struct process** head, struct process* newprocess) {
    if (*head == NULL) {
        *head = newprocess;
    } else {
        struct process* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newprocess;
    }
}

void sortProcessesByArrivalTime(struct process** head) {
    struct process* current = *head;
    struct process* index = NULL;

    if (*head == NULL) return;

    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->at > index->at) {
         
                int tempPid = current->pid;
                int tempAt = current->at;
                int tempBt = current->bt;

                current->pid = index->pid;
                current->at = index->at;
                current->bt = index->bt;

                index->pid = tempPid;
                index->at = tempAt;
                index->bt = tempBt;
            }
            index = index->next;
        }
        current = current->next;
    }
}

void FCFS(struct process* head) {
    int currentTime = 0;
    struct process* temp = head;

    while (temp != NULL) {
        if (currentTime < temp->at) {
            currentTime = temp->at;  
        }

        temp->wt = currentTime - temp->at; 
        temp->tat = temp->wt + temp->bt;  
        temp->ct = currentTime + temp->bt;

        currentTime += temp->bt; 
        temp = temp->next;
    }
}

void display(struct process* head) {
    printf("\nProcess Details:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    struct process* temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               temp->pid, temp->at, temp->bt, temp->ct, temp->tat, temp->wt);
        temp = temp->next;
    }
}

int main() {
    struct process* head = NULL;
    int n, pid, at, bt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter process ID, arrival time, and burst time for process %d: ", i + 1);
        scanf("%d %d %d", &pid, &at, &bt);
        struct process* newprocess = createProcess(pid, at, bt);
        appendProcess(&head, newprocess);
    }

    sortProcessesByArrivalTime(&head);

    printf("\nFCFS Scheduling:\n");
    FCFS(head);

    display(head);

    return 0;
}
