#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid,AT,BT,CT,TAT,WT;
    struct Process *next;
};

struct Process* create() {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    scanf("%d %d %d", &newProcess->pid, &newProcess->AT, &newProcess->BT);
    newProcess->next = NULL;
    return newProcess;
}

void calculate(struct Process* head) {
    int currentTime = 0;
    struct Process* temp = head;

    while (temp != NULL) {
        if (currentTime < temp->AT) {
            currentTime = temp->AT;
        }
        currentTime+=temp->BT;
        temp->CT=currentTime;
        temp->TAT=temp->CT - temp->AT;
        temp->WT=temp->TAT - temp->BT;
        temp=temp->next;
    }
}

void display(struct Process* head) {
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    struct Process* temp = head;
    while (temp != NULL) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",temp->pid, temp->AT, temp->BT, temp->CT, temp->TAT, temp->WT);
        temp = temp->next;
    }
}

int main() {
    struct Process* head = NULL;
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
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
    calculate(head);
    display(head);
}