#include<stdio.h>
void dec(int n)
{
    if(n==0)
    return ;
    else{
    printf("%d \n",n);
    return dec(n-1);
}
}
int main()
{
    int n=5;
    dec(n);
    return 0;
}
