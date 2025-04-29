#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t semaphore;

// Critical Section Function
void* critical_section(void* arg) {
    int thread_id = (int)arg;
    
    printf("Thread %d: Waiting to enter critical section\n", thread_id);
    
    // Wait (P)
    sem_wait(&semaphore);
    
    // Critical Section
    printf("Thread %d: Entered critical section\n", thread_id);
    sleep(2); // Simulate work
    printf("Thread %d: Exiting critical section\n", thread_id);
    
    // Signal (V)
    sem_post(&semaphore);
    
    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    // Initialize semaphore with value 1 for mutual exclusion
    sem_init(&semaphore, 0, 1);

    // Create 5 threads
    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, critical_section, &thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);
    return 0;
}
