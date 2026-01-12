#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements");
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        arr[i] = a;
    }
    for (int i = 1; i < n; i++)
    {
        arr[i] = arr[i] + arr[i - 1];
    }
    printf("Final value of the Array is");
    for (int i = 0; i < n; i++)
    {
        printf("%d ,", arr[i]);
    }
}