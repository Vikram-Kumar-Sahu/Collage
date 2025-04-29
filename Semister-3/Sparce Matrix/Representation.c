#include <stdio.h>
#include<stdbool.h>
#define MAX 100

void accept(int arr[MAX][MAX], int c, int r) {
    int i, j;
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printMatrix(int arr[MAX][MAX], int c, int r) {
    int i, j;
    printf("The matrix is:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
bool isSparce(int arr[MAX][MAX], int c, int r) {
    int i, j, z = 0, nz = 0;
    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            if (arr[i][j] == 0) {
                z++;
            } else {
                nz++;
            }
        }
    }
    return z > nz;
}
void Sparce(int arr[MAX][MAX], int c, int r) {
    int i, j, k = 1;
    int triplet[MAX][3];  // Sparse matrix in triplet form

    triplet[0][0] = c;
    triplet[0][1] = r;
    triplet[0][2] = 0;  // Initialize non-zero count

    for (i = 0; i < c; i++) {
        for (j = 0; j < r; j++) {
            if (arr[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = arr[i][j];
                k++;
            }
        }
    }
    triplet[0][2] = k - 1;  // Total non-zero elements

    // Printing the sparse matrix in triplet form
    printf("Sparse Matrix in Triplet Form:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}
int main() {
    int c, r;
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter the number of rows: ");
    scanf("%d", &r);

    int arr[MAX][MAX];  

    accept(arr, c, r);
    printMatrix(arr,c,r);
    if (isSparce(arr, c, r)) {
        printf("The matrix is sparse.\n");
        Sparce(arr, c, r);
    } else {
        printf("The matrix is not sparse.\n");
    }
    return 0;
}
