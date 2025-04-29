#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int prime[10]={2,3,5,7,11,13,17,19,23,29};

void* routine(void* args){
int index=*(int*)args;
printf("%d",prime[index]);
free(args);
return NULL;
}

int main(){
	pthread_t th[10];
	int i;
	for(i=0;i<10;i++){
		int* a=malloc(sizeof(int));
		*a=i;
		pthread_create(&th[i],NULL,&routine,a);
	}
	for(i=0;i<10;i++){
	pthread_join(th[i],NULL);
	}
}


