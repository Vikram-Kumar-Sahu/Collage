#include<stdio.h>
void main()
{
    printf("enter the value of n");
    int n;
    scanf("%d",&n);
    int i,j;
    int arr[n][n];
    for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
     scanf("%d",&arr[i][j]);
    }
    for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
     printf("%d",arr[i][j]);
     printf("\n");
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        j=0;int k=n-1;
        while(j<k)
        {
           int temp=arr[i][j];
            arr[i][j]=arr[i][k];
            arr[j][k]=temp; 
            j++;k--;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",arr[i][j]);
        printf("\n");
    }
    

    
}
