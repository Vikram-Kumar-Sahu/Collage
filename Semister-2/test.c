
#include <stdio.h>
#include <pthread.h>

void *f1(void *arg){
    
    printf("Name is: %s\n", (char *)arg);

    return NULL;
}


int main(){
    pthread_t t1;
    char name[] = "Shivam";
    pthread_create(&t1, NULL, f1, name);
    pthread_join(t1, NULL);
    return 0;
}
