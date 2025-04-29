#include<stdio.h>
void main(){
    int i=0,a=0,b=1,c=0;
    printf("1st->%d,\n",a);
    printf("2->%d,\n",b);
    for(i=0;i<8;i++){
        c=a+b;
        printf("%d->%d,\n",i+3,c);
        a=b;
        b=c;

    }
}
