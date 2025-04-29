#include<stdio.h>
void main(){
int i,j,n=5,m=4;
for(i=0;i<n;i++){
    for(j=m;j>=0;j--){
        printf(" ");
    }
    for(j=0;j<=i;j++){
        printf("*");
    }
    for(j=0;j<i;j++){
        printf("*");
    }
    printf("\n");
    m--;
}
}
