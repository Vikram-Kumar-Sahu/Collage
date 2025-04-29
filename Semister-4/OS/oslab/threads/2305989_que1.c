#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10        
#define THREAD_MAX 2  

int arr[MAX] = {38, 27, 43, 3, 9, 82, 10, 45, 1, 14};
int part = 0;         

void merge(int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[high - low + 1];

    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}
void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low, mid, high);
    }
}
void* thread_merge_sort(void* arg) {
    int which_part = part++; 

    int low = which_part * (MAX / 2);
    int high = (which_part + 1) * (MAX / 2) - 1;

    merge_sort(low, high);
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[THREAD_MAX];

    printf("Before Sorting:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < THREAD_MAX; i++) {
        if (pthread_create(&threads[i], NULL, &thread_merge_sort, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
    }
    for (int i = 0; i < THREAD_MAX; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
    }
    merge(0, (MAX / 2) - 1, MAX - 1);
    printf("After Sorting:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
