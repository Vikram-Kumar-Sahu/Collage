#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};

void swap5990(struct person *a, struct person *b) 
{
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify5990(struct person arr[], int n, int i) 
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l].age < arr[smallest].age)
        smallest = l;
    if (r < n && arr[r].age < arr[smallest].age)
        smallest = r;
    if (smallest != i) 
    {
        swap5990(&arr[i], &arr[smallest]);
        minHeapify5990(arr, n, smallest);
    }
}

void buildMinHeap5990(struct person arr[], int n) 
{
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify5990(arr, n, i);
}

void maxHeapify5990(struct person arr[], int n, int i) 
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l].weight > arr[largest].weight)
        largest = l;
    if (r < n && arr[r].weight > arr[largest].weight)
        largest = r;
    if (largest != i) 
    {
        swap5990(&arr[i], &arr[largest]);
        maxHeapify5990(arr, n, largest);
    }
}

void buildMaxHeap5990(struct person arr[], int n) 
{
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify5990(arr, n, i);
}

int readData5990(const char *filename, struct person **arr) 
{
    FILE *fp = fopen(filename, "r");
    if (!fp) 
    {
        printf("Error opening file!\n");
        return 0;
    }
    int n;
    fscanf(fp, "%d", &n);
    *arr = (struct person*)malloc(n * sizeof(struct person));
    for (int i = 0; i < n; i++) 
    {
        fscanf(fp, "%d %s %d %d %d", &(*arr)[i].id, (*arr)[i].name, &(*arr)[i].age, &(*arr)[i].height, &(*arr)[i].weight);
    }
    fclose(fp);
    return n;
}

void display5990(struct person arr[], int n) 
{
    printf("Id Name Age Height Weight(pound)\n");
    for (int i = 0; i < n; i++)
        printf("%d %s %d %d %d\n", arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
}

void displayYoungestWeight5990(struct person arr[], int n)
{
    if (n == 0) 
    {
        printf("No data loaded!\n");
        return;
    }
    printf("Weight of youngest student: %.2f kg\n", arr[0].weight * 0.453592);
}

void deleteOldest5990(struct person arr[], int *n)
{
    if (*n == 0) 
    {
        printf("Heap is empty!\n");
        return;
    }
    int oldestIdx = 0;
    for (int i = 1; i < *n; i++) 
    {
        if (arr[i].age > arr[oldestIdx].age)
            oldestIdx = i;
    }
    printf("Deleting oldest person: %s (Age: %d)\n", arr[oldestIdx].name, arr[oldestIdx].age);
    arr[oldestIdx] = arr[*n - 1];
    (*n)--;
    buildMinHeap5990(arr, *n);
}

void insertMinHeap5990(struct person arr[], int *n, struct person newPerson)
{
    arr[*n] = newPerson;
    int i = *n;
    (*n)++;
    while (i != 0 && arr[(i-1)/2].age > arr[i].age) 
    {
        swap5990(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

int main()
{
    struct person *arr = NULL;
    int choice, n = 0, minHeapBuilt = 0, maxHeapBuilt = 0;
    while(1)
    {
        printf("\nMain Menu\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice == 7)
            break;

        switch(choice)
        {
            case 1: 
                char filename[50];
                printf("Enter filename: ");
                scanf("%s", filename);
                n = readData5990(filename, &arr);
                if (n > 0)
                    display5990(arr, n);
                minHeapBuilt = 0;
                maxHeapBuilt = 0;
                break;
            case 2:
                if (n == 0) 
                {
                    printf("No data loaded!\n");
                    break;
                }
                buildMinHeap5990(arr, n);
                minHeapBuilt = 1;
                printf("Min-heap created based on age.\n");
                display5990(arr, n);
                break;
            case 3:
                if (n == 0) 
                {
                    printf("No data loaded!\n");
                    break;
                }
                buildMaxHeap5990(arr, n);
                maxHeapBuilt = 1;
                printf("Max-heap created based on weight.\n");
                display5990(arr, n);
                break;
            case 4:
                if (!minHeapBuilt) 
                {
                    printf("Min-heap not created yet!\n");
                    break;
                }
                displayYoungestWeight5990(arr, n);
                break;
            case 5:
                struct person newPerson;
                printf("Enter Id Name Age Height Weight: ");
                scanf("%d %s %d %d %d", &newPerson.id, newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                arr = (struct person*)realloc(arr, (n+1) * sizeof(struct person));
                insertMinHeap5990(arr, &n, newPerson);
                printf("Person inserted into Min-heap.\n");
                display5990(arr, n);
                break;
            case 6:
                if (!minHeapBuilt) 
                {
                    printf("Min-heap not created yet!\n");
                    break;
                }
                deleteOldest5990(arr, &n);
                display5990(arr, n);
                break;
            default:
                printf("Invalid option!\n");
        }
    }
    free(arr);
    return 0;
}