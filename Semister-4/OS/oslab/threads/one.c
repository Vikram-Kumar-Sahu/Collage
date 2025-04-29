#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* routine(void *arg){
int data=*((int *)arg);
printf("%d",data);
return NULL;
}

int main(){
int a=3;
pthread_t t1;
pthread_create (&t1,NULL,&routine,&a);
pthread_join(t1,NULL);
return 0;
}
