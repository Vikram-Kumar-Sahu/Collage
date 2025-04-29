#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void display(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
struct Node* mergeOddEven(struct Node* list1, struct Node* list2) {
    struct Node* head = NULL; 
    struct Node** lastPtrRef = &head;  
    while (list1 != NULL || list2 != NULL) {
        if (list1 != NULL && list1->data % 2 != 0) {
            *lastPtrRef = list1;
            lastPtrRef = &((*lastPtrRef)->next);
        }
        if (list1 != NULL) {
            list1 = list1->next;
        }
        
        if (list2 != NULL && list2->data % 2 == 0) {
            *lastPtrRef = list2;
            lastPtrRef = &((*lastPtrRef)->next);
        }

        if (list2 != NULL) {
            list2 = list2->next;
        }
    }
    *lastPtrRef = NULL;  
    return head;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n1, n2, data;
    printf("Enter the number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter elements of List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        append(&list1, data);
    }
    printf("Enter the number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter elements of List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        append(&list2, data);
    }
    printf("List 1: ");
    display(list1);
    printf("List 2: ");
    display(list2);
    struct Node* mergedList = mergeOddEven(list1, list2);
    printf("Merged List : ");
    display(mergedList);

    return 0;}