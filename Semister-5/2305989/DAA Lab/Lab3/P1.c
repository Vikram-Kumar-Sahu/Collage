#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 600

long long comparisons = 0;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Error check for memory allocation
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));
    if (L == NULL || R == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int readFile(const char *filename, int arr[]) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "c:\\Collage\\Semister-5\\2305989\\DAA Lab\\Lab3\\%s", filename);
    
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        printf("Error opening file: %s\n", filepath);
        return -1;
    }
    
    int n = 0;
    while (fscanf(fp, "%d", &arr[n]) == 1 && n < MAX)
        n++;
    
    fclose(fp);
    return n;
}

void writeFile(const char *filename, int arr[], int n) {
    char filepath[256];
    snprintf(filepath, sizeof(filepath), "c:\\Collage\\Semister-5\\2305989\\DAA Lab\\Lab3\\%s", filename);
    
    FILE *fp = fopen(filepath, "w");
    if (!fp) {
        printf("Error opening file for writing: %s\n", filepath);
        return;
    }
    
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", arr[i]);
    
    fclose(fp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX], n, option;
    char inFile[30], outFile[30];

    while (1) {
        printf("\nMAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (option == 4)
            break;

        switch (option) {
            case 1:
                strcpy(inFile, "inAsce.txt");
                strcpy(outFile, "outMergeAsce.txt");
                break;
            case 2:
                strcpy(inFile, "inDesc.txt");
                strcpy(outFile, "outMergeDesc.txt");
                break;
            case 3:
                strcpy(inFile, "inRand.txt");
                strcpy(outFile, "outMergeRand.txt");
                break;
            default:
                printf("Invalid option! Please select 1-4.\n");
                continue;
        }

        n = readFile(inFile, arr);
        if (n <= 0) {
            printf("No data to sort or file error.\n");
            continue;
        }

        printf("Before Sorting: ");
        printArray(arr, n);

        comparisons = 0;
        struct timespec start, end;
        
        if (clock_gettime(CLOCK_MONOTONIC, &start) == -1) {
            printf("Error getting start time\n");
            continue;
        }

        mergeSort(arr, 0, n - 1);

        if (clock_gettime(CLOCK_MONOTONIC, &end) == -1) {
            printf("Error getting end time\n");
            continue;
        }

        long long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);

        writeFile(outFile, arr, n);

        printf("After Sorting: ");
        printArray(arr, n);
        printf("Number of Comparisons: %lld\n", comparisons);
        printf("Execution Time: %lld nanoseconds\n", elapsed_ns);
    }
    return 0;
}