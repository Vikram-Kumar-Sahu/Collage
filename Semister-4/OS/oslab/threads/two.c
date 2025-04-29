#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
int pid=fork();
if(pid==-1){
return 1;
}
printf("hello from processor\n");
if(pid !=0){
wait(NULL);
}
return 0;
}
