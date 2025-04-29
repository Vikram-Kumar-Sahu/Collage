#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t rw_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int read_count = 0;
int data = 0;

// Reader function
void* reader(void* arg) {
    int reader_id = (int)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        read_count++;
        if (read_count == 1)
            pthread_mutex_lock(&rw_mutex);
        pthread_mutex_unlock(&mutex);

        // Critical Section for Readers
        printf("Reader %d: Read data = %d\n", reader_id, data);
        sleep(1);

        pthread_mutex_lock(&mutex);
        read_count--;
        if (read_count == 0)
            pthread_mutex_unlock(&rw_mutex);
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    return NULL;
}

// Writer function
void* writer(void* arg) {
    int writer_id = (int)arg;
    while (1) {
        pthread_mutex_lock(&rw_mutex);
        
        // Critical Section for Writers
        data += 1;
        printf("Writer %d: Wrote data = %d\n", writer_id, data);
        sleep(2);
        
        pthread_mutex_unlock(&rw_mutex);
        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t read[5], write[2];
    int reader_ids[5], writer_ids[2];

    // Create reader threads
    for (int i = 0; i < 5; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&read[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < 2; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&write[i], NULL, writer, &writer_ids[i]);
    }

    // Join threads
    for (int i = 0; i < 5; i++)
        pthread_join(read[i], NULL);
    for (int i = 0; i < 2; i++)
        pthread_join(write[i], NULL);

    pthread_mutex_destroy(&rw_mutex);
    pthread_mutex_destroy(&mutex);

    return 0;
}
