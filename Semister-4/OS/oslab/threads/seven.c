#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *roll_dice() {
    int *result = malloc(sizeof(int));  // Allocate memory for result
    if (result == NULL) {
        perror("Failed to allocate memory");
        pthread_exit(NULL);
    }
    
    *result = (rand() % 6) + 1;  // Generate random dice roll
    printf("Rolled: %d\n", *result);
    
    return result;  // Return allocated memory
}

int main() {
    srand(time(NULL));  // Seed random number generator

    pthread_t th;
    int *res;  // Pointer to store result

    // Create the thread
    if (pthread_create(&th, NULL, roll_dice, NULL) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for thread to finish and get the result
    if (pthread_join(th, (void**)&res) != 0) {
        perror("Failed to join thread");
        return 1;
    }

    printf("Main received: %d\n", *res);  // Print result from thread
    free(res);  // Free allocated memory

    return 0;
}

