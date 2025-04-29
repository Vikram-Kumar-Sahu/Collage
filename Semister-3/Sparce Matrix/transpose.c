#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void accept(int arr[MAX][MAX], int c, int r) {
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void printMatrix(int arr[MAX][MAX], int c, int r) {
    printf("The matrix is:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

bool isSparse(int arr[MAX][MAX], int c, int r) {
    int z = 0, nz = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (arr[i][j] == 0) {
                z++;
            } else {
                nz++;
            }
        }
    }
    return z > nz;
}

void printTriplet(int triplet[MAX][3], int k) {
    printf("Sparse Matrix in Triplet Form:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

int Sparse(int arr[MAX][MAX], int c, int r, int triplet[MAX][3]) {
    int k = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (arr[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = arr[i][j];
                k++;
            }
        }
    }
    return k;
}

void transpose(int transpose[MAX][3], int triplet[MAX][3], int k) {
    for (int i = 0; i < k; i++) {
        transpose[i][0] = triplet[i][1];
        transpose[i][1] = triplet[i][0];
        transpose[i][2] = triplet[i][2];
    }
}

int main() {
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    
    int arr[MAX][MAX];
    accept(arr, c, r);
    printMatrix(arr, c, r);
    
    if (isSparse(arr, c, r)) {
        printf("The matrix is sparse.\n");
        int triplet[MAX][3];
        int k = Sparse(arr, c, r, triplet);
        printTriplet(triplet, k);

        int transposeMatrix[MAX][3];
        transpose(transposeMatrix, triplet, k);
        
        printf("Transpose of Sparse Matrix in Triplet Form:\n");
        printTriplet(transposeMatrix, k);
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}
