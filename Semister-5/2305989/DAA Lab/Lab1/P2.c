#include <stdio.h>

void PrefixSum(int arr[], int ps[], int n)
{
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            ps[i] = arr[i];
        else
            ps[i] = arr[i] + ps[i - 1];
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n], ps[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    PrefixSum(arr, ps, n);
    printf("Prefix Sum: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", ps[i]);
    printf("\n");
    return 0;
}