#include<stdio.h>
void asc(int arr[],int n);
void main()
{
    int n,j;
    printf("enter the size of array");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("before sorting elements of the given array:");
    for(int i=0;i<n;i++)
    {
    printf("%d ",arr[i]);
    }
    printf("\n");
    asc(arr,n);
    printf("After sorting elements of the given array:");
    for(int i=0;i<n;i++)
    {
    printf("%d ",arr[i]);
    }
    
}
void asc(int arr[],int n)
{
    int a,i,j;
    for (i=0;i<n;++i) 
        {
            for (j=i+1;j<n;++j)
            {
                if (arr[i]>arr[j]) 
                {
                    a=arr[i];
                    arr[i]=arr[j];
                    arr[j]=a;
                }
            }
    }
   
}
