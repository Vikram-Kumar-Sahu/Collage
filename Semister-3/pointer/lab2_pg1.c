#include <stdio.h>
int main() {
    int n, c, a;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    do {
        printf("\n1. Find the number of non-zero elements\n");
        printf("2. Display Upper Triangular Matrix\n");
        printf("3. Display the elements just above and below the diagonal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1: {
                int c = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (arr[i][j] != 0) {
                            c++;
                        }
                    }
                }
                printf("Number of non-zero elements: %d\n", c);
                break;
            }
            case 2: {
                printf("Upper Triangular Matrix:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (j >= i) {
                            printf("%d ", arr[i][j]);
                        } else {
                            printf("  ");
                        }
                    }
                    printf("\n");
                }
                break;
            }
            case 3: {
                printf("Elements just above the diagonal:\n");
                for (int i = 0; i < n - 1; i++) {
                    printf("%d ", arr[i][i + 1]);
                }
                printf("\nElements just below the diagonal:\n");
                for (int i = 1; i < n; i++) {
                    printf("%d ", arr[i][i - 1]);
                }
                printf("\n");
                break;
            }
            case 4: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (c != 4);
    return 0;
}
