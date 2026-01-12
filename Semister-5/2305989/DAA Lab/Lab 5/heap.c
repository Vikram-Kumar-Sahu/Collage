 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char name[50];
    int age;
    int height;
    int weight; 
};

struct person *people = NULL;
int size = 0;  
int capacity = 0;

void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void maxHeapify(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMinHeap(struct person arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void buildMaxHeap(struct person arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void insertMinHeap(struct person newPerson) {
    size++;
    people = realloc(people, size * sizeof(struct person));
    int i = size - 1;
    people[i] = newPerson;

    while (i != 0 && people[(i-1)/2].age > people[i].age) {
        swap(&people[i], &people[(i-1)/2]);
        i = (i-1)/2;
    }
}
void deleteOldest() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    
    int maxAgeIndex = 0;
    for (int i = 1; i < size; i++) {
        if (people[i].age > people[maxAgeIndex].age) {
            maxAgeIndex = i;
        }
    }

    printf("Deleted Person: %s (Age %d)\n", people[maxAgeIndex].name, people[maxAgeIndex].age);

    people[maxAgeIndex] = people[size-1];
    size--;
    people = realloc(people, size * sizeof(struct person));
    buildMinHeap(people, size);
}


void displayYoungestWeight() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Weight of youngest student: %.2f kg\n", people[0].weight * 0.453592);
}


void displayAll() {
    printf("\n%-5s %-20s %-5s %-7s %-7s\n", "ID", "Name", "Age", "Height", "Weight");
    for (int i = 0; i < size; i++) {
        printf("%-5d %-20s %-5d %-7d %-7d\n",
               people[i].id, people[i].name, people[i].age, people[i].height, people[i].weight);
    }
    printf("\n");
}


void readDataFromFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    fscanf(fp, "%d", &capacity);  
    people = malloc(capacity * sizeof(struct person));

    for (int i = 0; i < capacity; i++) {
        fscanf(fp, "%d %s %d %d %d",
               &people[i].id, people[i].name, &people[i].age,
               &people[i].height, &people[i].weight);
    }
    size = capacity;
    fclose(fp);

    printf("Data loaded successfully!\n");
    displayAll();
}


int main() {
    int choice;
    char filename[50] = "students.txt";

    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            readDataFromFile(filename);
        } 
        else if (choice == 2) {
            buildMinHeap(people, size);
            printf("Min-heap (Age) created.\n");
            displayAll();
        } 
        else if (choice == 3) {
            buildMaxHeap(people, size);
            printf("Max-heap (Weight) created.\n");
            displayAll();
        } 
        else if (choice == 4) {
            displayYoungestWeight();
        } 
        else if (choice == 5) {
            struct person newP;
            printf("Enter Id Name Age Height Weight: ");
            scanf("%d %s %d %d %d", &newP.id, newP.name, &newP.age, &newP.height, &newP.weight);
            insertMinHeap(newP);
            printf("Inserted successfully!\n");
            displayAll();
        } 
        else if (choice == 6) {
            deleteOldest();
            displayAll();
        }
    } while (choice != 7);

    free(people);
    return 0;
}
