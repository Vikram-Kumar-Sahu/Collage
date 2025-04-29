#include<stdio.h>
#include<limits.h>
int larg(int arr[],int n)
{
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>m)
        m=arr[i];
    }
    return m;
}
int small(int arr[],int n)
{
    int s=INT_MAX;
     for(int i=0;i<n;i++)
    {
        if(arr[i]<s)
        s=arr[i];
    }
    return s;
}
void main()
{
    int n,l,s;
    printf("enter the size of array:");
    scanf("%d",&n);
    //printf("\n");
    int arr[n];
    printf("enter the elements of the array:");
        
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    l=larg(arr,n);
    s=small(arr,n);
    printf("\n");
    printf("Largest element of array is %d",l);
    printf("\n");
    printf("Smallest element of the array is %d",s);
}
