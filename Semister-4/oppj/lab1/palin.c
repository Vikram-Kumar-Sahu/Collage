#include<stdio.h>
void main(){
    int a,c=0,r=0;
    printf("enter a number:");
    scanf("%d",&a);
    int n=a;
    while(n>0){
        r=n%10;
        c=c*10+r;
        n=n/10;
    }
    if(a==c){
        printf("the entered number is palindrome num");}
    else{
     printf("the entered number is not palindrome num");
    }
}