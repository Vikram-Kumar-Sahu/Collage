#include<stdio.h>
void main(){
    int a,c=0;
    printf("enter a number");
    scanf("%d",&a);
    for(int i=2;i<a;i++){
        if(a%i==0){
            c++;
        }
    }
    if(c==0)
    printf("the entered number is prime");
    else
     printf("the entered number is not prime");
}