#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* routine(){
printf("thread");
}

int main(){
pthread_t t1;
pthread_create(&t1,NULL,&routine,NULL);
pthread_join(t1,NULL);
return 0;
}
