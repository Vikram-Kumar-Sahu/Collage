#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
 
 int mail=0;
 pthread_mutex_t mutex;
 
 void* routine(){
 	for(int i=0;i<1000000;i++)
 	{
 		pthread_mutex_lock(&mutex);
 		mail++;
 		pthread_mutex_unlock(&mutex);
 	}
 }
 
 int main(){
 	pthread_t th[4];
 	int i;
 	pthread_mutex_init(&mutex,NULL);
 	for(i=0;i<4;i++){
 		pthread_create(&th[i],NULL,&routine,NULL);
 	}
 	for(i=0;i<4;i++){
 		pthread_join(th[i],NULL);
 	}
 	pthread_mutex_destroy(&mutex);
 	printf("%d",mail);
 }
