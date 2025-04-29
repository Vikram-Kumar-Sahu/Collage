#include <stdio.h>
#define MAX 100

void readMatrix(int matrix[MAX][MAX], int *rows, int *cols) {
    printf("Enter the number of rows: ");
    scanf("%d", rows);
    printf("Enter the number of columns: ");
    scanf("%d", cols);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void convertToTriplet(int matrix[MAX][MAX], int rows, int cols, int triplet[MAX][3], int *size) {
    int k = 1; 
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = 0; 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    triplet[0][2] = k - 1; 
    *size = k;
}

void printTriplet(int triplet[MAX][3]) {
    int num_nonzero = triplet[0][2];

    printf("Row\tCol\tValue\n");
    for (int i = 0; i <= num_nonzero; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

void multiplyTriplet(int a[MAX][3], int b[MAX][3], int result[MAX][3], int sa, int sb, int *sr) {
    if (a[0][1] != b[0][0]) {
        printf("Matrices dimensions do not match for multiplication!\n");
        return;
    }

    result[0][0] = a[0][0];
    result[0][1] = b[0][1];
    int k = 1;

    for (int i = 1; i < sa; i++) {
        for (int j = 1; j < sb; j++) {
            if (a[i][1] == b[j][0]) {
                int row = a[i][0];
                int col = b[j][1];
                int value = a[i][2] * b[j][2];

                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (result[x][0] == row && result[x][1] == col) {
                        result[x][2] += value;
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    result[k][0] = row;
                    result[k][1] = col;
                    result[k][2] = value;
                    k++;
                }
            }
        }
    }

    result[0][2] = k - 1;
    *sr = k;
}

int main() {
    int matrix1[MAX][MAX], matrix2[MAX][MAX];
    int triplet1[MAX][3], triplet2[MAX][3], result[MAX][3];
    int rows1, cols1, size1;
    int rows2, cols2, size2;
    int sr;

    printf("Enter the first matrix:\n");
    readMatrix(matrix1, &rows1, &cols1);
    convertToTriplet(matrix1, rows1, cols1, triplet1, &size1);
    printf("First matrix triplet representation:\n");
    printTriplet(triplet1);

    printf("Enter the second matrix:\n");
    readMatrix(matrix2, &rows2, &cols2);
    convertToTriplet(matrix2, rows2, cols2, triplet2, &size2);
    printf("Second matrix triplet representation:\n");
    printTriplet(triplet2);

    printf("Multiplication of matrices:\n");
    multiplyTriplet(triplet1, triplet2, result, size1, size2, &sr);
    printTriplet(result);

    return 0;
}
