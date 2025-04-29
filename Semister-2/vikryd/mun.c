#include<stdio.h>
void main(){
    int n;
    int *ptr;
    printf("enter a num");
    scanf("%d",&n);
    ptr=&n;
    printf("the given number is %d",*ptr);
}
