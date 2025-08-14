#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 600

long long comparisons = 0;
int best_case = 1, worst_case = 1;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high, int *is_best, int *is_worst)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparisons++;
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    int pos = i + 1;

    int left = pos - low;
    int right = high - pos;
    if (!(left <= (high - low) / 2 && right <= (high - low) / 2))
        *is_best = 0;
    if (!(left == 0 || right == 0))
        *is_worst = 0;

    return pos;
}

void quickSort(int arr[], int low, int high, int *is_best, int *is_worst)
{
    if (low < high)
    {
        int pos = partition(arr, low, high, is_best, is_worst);
        quickSort(arr, low, pos - 1, is_best, is_worst);
        quickSort(arr, pos + 1, high, is_best, is_worst);
    }
}

int readFile(const char *filename, int arr[])
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
    {
        printf("Error opening file: %s\n", filename);
        return -1;
    }
    int n = 0;
    while (fscanf(fp, "%d", &arr[n]) == 1 && n < MAX)
        n++;
    fclose(fp);
    return n;
}

void writeFile(const char *filename, int arr[], int n)
{
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++)
        fprintf(fp, "%d ", arr[i]);
    fclose(fp);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[MAX], n, option;
    char src[30], des[30];

    while (1)
    {
        printf("\nMAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 4)
            break;

        switch (option)
        {
            case 1:
                strcpy(src, "inAsce.txt");
                strcpy(des, "outQuickAsce.txt");
                break;
            case 2:
                strcpy(src, "inDesc.txt");
                strcpy(des, "outQuickDesc.txt");
                break;
            case 3:
                strcpy(src, "inRand.txt");
                strcpy(des, "outQuickRand.txt");
                break;
            default:
                printf("Invalid option!\n");
                continue;
        }

        n = readFile(src, arr);
        if (n <= 0)
        {
            printf("No data to sort or file error.\n");
            continue;
        }

        printf("Before Sorting: ");
        printArray(arr, n);

        comparisons = 0;
        best_case = 1;
        worst_case = 1;
        quickSort(arr, 0, n - 1, &best_case, &worst_case);

        writeFile(des, arr, n);

        printf("After Sorting: ");
        printArray(arr, n);
        printf("Number of Comparisons: %lld\n", comparisons);
        if (best_case)
            printf("Scenario: Best-case partitioning\n");
        else if (worst_case)
            printf("Scenario: Worst-case partitioning\n");
        else
            printf("Scenario: Neither best nor worst-case partitioning\n");
    }
    return 0;
}