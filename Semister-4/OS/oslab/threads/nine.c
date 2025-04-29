#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int arr[10]={1,2,3,4,5,6,7,8,9,10};

void* routine(void* args){
	int index=*(int*)args;
	int sum=0;
	for(int i=0;i<5;i++){
		sum+=arr[index+i];
	}
	*(int*)args=sum;
	return args;
}

int main(){
	pthread_t th[2];
	int i;
	for(i=0;i<2;i++){
		int* a=malloc(sizeof(int));
		*a=i*5;
		pthread_create(&th[i],NULL,routine,a);
	}
	int gS=0;
	for(i=0;i<2;i++){
		int* r;
		pthread_join(th[i],(void**)&r);
		gS+=*r;
		free(r);
		
	}
	printf("%d",gS);
	return 0;
}
