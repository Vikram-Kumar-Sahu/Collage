#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int mail=0;

void* routine(){
for(int i =0;i<100;i++){
mail++;
}
}

int main(){
pthread_t t1,t2;
pthread_create(&t1,NULL,&routine,NULL);

pthread_create(&t2,NULL,&routine,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
printf("%d",mail);
return 0;
}
