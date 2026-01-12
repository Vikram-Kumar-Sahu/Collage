#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void find(int arr[], int n, int *ss, int *sl)
{
    int smallest = INT_MAX, largest = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] < smallest)
        {
            *ss = smallest;
            smallest = arr[i];
        }
        else if(arr[i] < *ss && arr[i] != smallest)
            *ss = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] > largest)
        {
            *sl = largest;
            largest = arr[i];
        }
        else if(arr[i] > *sl && arr[i] != largest)
            *sl = arr[i];
    }
}

int main()
{
    int n, ss, sl;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    find(arr, n, &ss, &sl);
    if(ss == INT_MAX || sl == INT_MIN)
        printf("No second largest and second smallest. \n");
    else
        printf("Second Smallest: %d \nSecond Largest: %d \n", ss, sl);
    return 0;
}