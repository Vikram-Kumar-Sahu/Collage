#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap5990(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition5990(int arr[], int low, int high) 
{
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = arr[pivotIndex];
    swap5990(&arr[pivotIndex], &arr[high]);
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap5990(&arr[i], &arr[j]);
        }
    }
    swap5990(&arr[i + 1], &arr[high]);
    return i + 1;
}

void randomizedQuicksort5990(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition5990(arr, low, high);
        randomizedQuicksort5990(arr, low, pi - 1);
        randomizedQuicksort5990(arr, pi + 1, high);
    }
}

void printArray5990(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size\n");
        return 1;
    }

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(arr);
            return 1;
        }
    }

    printf("Unsorted array:\n");
    printArray5990(arr, n);

    randomizedQuicksort5990(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray5990(arr, n);

    free(arr);
    return 0;
}