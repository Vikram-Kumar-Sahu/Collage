#include<stdio.h>
int sum(int n)
{
    if(n==0)
    return 0;
    int ans=n+sum(n-1);
    
     return ans;
    
}
void main()
{
    int k=0;
int n=4;
k=sum(n);
printf("%d \n",k);
}
