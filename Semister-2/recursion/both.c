#include<stdio.h>
void both(int n)
{
    if(n==0)
    return;
    printf("%d \n",n);
    both(n-1);
    printf("%d \n",n);
    return;
    
}
void main()
{
int n=4;
both(n);
}
