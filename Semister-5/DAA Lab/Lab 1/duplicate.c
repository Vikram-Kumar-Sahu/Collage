#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);

    int max_freq = 0, most_freq_val = -1;

    for (int i = 0; i < n - 1; i++) {
        int freq = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                freq++;
            }
        }
        if (freq > max_freq) {
            max_freq = freq;
            most_freq_val = arr[i];
        }
    }

    printf("The content of the data is: ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");

    if (max_freq > 1) {
        printf("Total number of occurrences of the most frequent value = %d\n", max_freq);
        printf("The most repeating element in the array = %d\n", most_freq_val);
    } else {
        printf("No duplicates found.\n");
    }

    free(arr);
    return 0;
}
