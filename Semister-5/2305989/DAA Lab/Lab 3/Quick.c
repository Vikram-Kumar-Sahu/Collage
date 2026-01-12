#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int comparisonCount = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high, int *scenarioFlag) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <=high - 1) {
            i++;
            comparisonCount++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
            comparisonCount++;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);

    // Check for best or worst case
    int leftSize = j - low;
    int rightSize = high - j;
    if ((leftSize == 0 && rightSize == high - low) || (rightSize == 0 && leftSize == high - low)) {
        *scenarioFlag = 1; // Worst-case
    } else if (leftSize <= (high - low) / 2 && rightSize <= (high - low) / 2) {
        *scenarioFlag = 2; // Best-case
    }

    return j;
}

// QuickSort
void quickSort(int arr[], int low, int high, int *scenarioFlag) {
    if (low < high) {
        int pi = partition(arr, low, high, scenarioFlag);
        quickSort(arr, low, pi - 1, scenarioFlag);
        quickSort(arr, pi + 1, high, scenarioFlag);
    }
}

// Read from file
int readFile(char *filename, int arr[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Cannot open file %s\n", filename);
        return -1;
    }
    int count = 0;
    while (fscanf(fp, "%d", &arr[count]) != EOF) {
        count++;
    }
    fclose(fp);
    return count;
}

// Write to file
void writeFile(char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
}

// Display array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, n;
    int arr[MAX];
    char inputFile[20], outputFile[20];

    while (1) {
        printf("\nMAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                strcpy(inputFile, "inQuickAsce.txt");
                strcpy(outputFile, "outQuickAsce.txt");
                break;
            case 2:
                strcpy(inputFile, "inQuickDesc.txt");
                strcpy(outputFile, "outQuickDesc.txt");
                break;
            case 3:
                strcpy(inputFile, "inQuickRand.txt");
                strcpy(outputFile, "outQuickRand.txt");
                break;
            default:
                printf("Invalid option\n");
                continue;
        }

        n = readFile(inputFile, arr);
        if (n <= 0) {
            continue;
        }

        printf("\nBefore Sorting (Content of %s):\n", inputFile);
        displayArray(arr, n);

        comparisonCount = 0;
        int scenarioFlag = 0;
        quickSort(arr, 0, n - 1, &scenarioFlag);

        writeFile(outputFile, arr, n);

        printf("After Sorting (Content of %s):\n", outputFile);
        displayArray(arr, n);
        printf("Number of Comparisons: %d\n", comparisonCount);
        if (scenarioFlag == 1)
            printf("Scenario: Worst-case partitioning\n");
        else if (scenarioFlag == 2)
            printf("Scenario: Best-case partitioning\n");
        else
            printf("Scenario: Neither best nor worst-case\n");
    }

    return 0;
}
