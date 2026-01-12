#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 600

long long comparisons = 0;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int readFile(const char *filename, int arr[]) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }
    int n = 0;
    while (fscanf(fp, "%d", &arr[n]) != EOF) {
        n++;
    }
    fclose(fp);
    return n;
}

void writeFile(const char *filename, int arr[], int n) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    int arr[MAX], n;
    char inputFile[50], outputFile[50];

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n2. Descending Data\n3. Random Data\n4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(inputFile, "inAsce.txt");
            strcpy(outputFile, "outMergeAsce.txt");
            break;
        case 2:
            strcpy(inputFile, "inDesc.txt");
            strcpy(outputFile, "outMergeDesc.txt");
            break;
        case 3:
            strcpy(inputFile, "inRand.txt");
            strcpy(outputFile, "outMergeRand.txt");
            break;
        default:
            printf("Exiting...\n");
            return 0;
    }

    n = readFile(inputFile, arr);
    if (n == 0) return 0;

    printf("Before Sorting:\n");
    displayArray(arr, n);

    comparisons = 0;
    mergeSort(arr, 0, n - 1);

    printf("After Sorting:\n");
    displayArray(arr, n);

    writeFile(outputFile, arr, n);

    printf("Number of Comparisons: %lld\n", comparisons);

    return 0;
}
