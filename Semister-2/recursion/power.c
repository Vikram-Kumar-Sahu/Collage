#include<stdio.h>
int power(int a,int b)
{
    int ans=1;
    if(b==0)
    return 1;
    ans=a*power(a,b-1);
    ;
     return ans;
    
}
void main()
{
    int k=0;
int a=2,b=2;
k=power(a,b);
printf("%d \n",k);
}
