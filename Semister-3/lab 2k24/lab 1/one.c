#include<stdio.h>
void compare(int *n,int *m)
{
    if(*m>*n)
    {
        printf("%d is greater than %d",*m,*n);

    }
    else if (*m==*n)

    {
        printf("%d is equal to %d",*m,*n);
           /* code */
    }
    else
    {
        printf("%d is greater then than %d",*n,*m);
    }
}
int main()
{
    int a,b;
    printf("Enter two numbers:\n");
    scanf("%d%d",&a,&b);
    compare(&a,&b);
    
}