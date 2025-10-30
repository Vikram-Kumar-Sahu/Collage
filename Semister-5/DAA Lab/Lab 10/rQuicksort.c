#include <stdio.h>

int _2305989_binarySearchLeftmost(int arr[], int n, int key, int *comparisons) {
    int left = 0, right = n - 1;
    int result = -1;
    *comparisons = 0;

    while (left <= right) {
        (*comparisons)++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            result = mid;
            right = mid - 1; // keep searching left for first occurrence
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, key, comparisons;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int index = _2305989_binarySearchLeftmost(arr, n, key, &comparisons);

    if (index != -1)
        printf("%d found at index position %d\nNumber of comparisons: %d\n", key, index, comparisons);
    else
        printf("%d not found in the array\nNumber of comparisons: %d\n", key, comparisons);

    return 0;
}
