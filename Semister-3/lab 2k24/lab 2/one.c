#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *n, int x, int a) {
    if (x > *n || x < 0) {
        printf("Not valid\n");
    } else {
        for (int i = *n; i > x; i--) {
            arr[i] = arr[i - 1];
        }
        arr[x] = a;
        (*n)++;
    }
    print(arr, *n);
}

void delete(int arr[], int *n, int x) {
    if (x >= *n || x < 0) {
        printf("Not valid\n");
    } else {
        for (int i = x; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
    }
    print(arr, *n);
}

void search(int arr[], int n, int x) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            c++;
            printf("Element found at position %d\n", i);
            return;
        }
    }
    printf("Element not found\n");
}

int main() {
    int n, c, x, a;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n + 1];  // Allocate extra space to accommodate insertion

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Linear Search\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter the element position to be inserted: ");
                scanf("%d", &x);
                printf("Enter the element: ");
                scanf("%d", &a);
                insert(arr, &n, x, a);
                break;

            case 2:
                printf("Enter the element position to be deleted: ");
                scanf("%d", &x);
                delete(arr, &n, x);
                break;

            case 3:
                printf("Enter the element to be searched: ");
                scanf("%d", &x);
                search(arr, n, x);
                break;

            case 4:
                printf("Array elements: ");
                print(arr, n);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (c != 5);

    return 0;
}