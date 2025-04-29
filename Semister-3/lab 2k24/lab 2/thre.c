#include <stdio.h>

void convertToTuple(int vikram_2305989_sparse[][10], int vikram_2305989_rows, int vikram_2305989_cols) {
    int count = 0;
    for (int i = 0; i < vikram_2305989_rows; i++) {
        for (int j = 0; j < vikram_2305989_cols; j++) {
            if (vikram_2305989_sparse[i][j] != 0) {
                count++;
            }
        }
    }
    int tuple[count + 1][3];
    tuple[0][0] = vikram_2305989_rows;
    tuple[0][1] = vikram_2305989_cols;
    tuple[0][2] = count;
    int k = 1;
    for (int i = 0; i < vikram_2305989_rows; i++) {
        for (int j = 0; j < vikram_2305989_cols; j++) {
            if (vikram_2305989_sparse[i][j] != 0) {
                tuple[k][0] = i;
                tuple[k][1] = j;
                tuple[k][2] = vikram_2305989_sparse[i][j];
                k++;
            }
        }
    }
    printf("3-Tuple Representation:\n");
    for (int i = 0; i < count + 1; i++) {
        printf("%d %d %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }
}

int main() {
    int vikram_2305989_rows, vikram_2305989_cols;
    printf("Enter the number of rows: ");
    scanf("%d", &vikram_2305989_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &vikram_2305989_cols);
    int vikram_2305989_sparse[10][10];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < vikram_2305989_rows; i++) {
        for (int j = 0; j < vikram_2305989_cols; j++) {
            scanf("%d", &vikram_2305989_sparse[i][j]);
        }
    }
    convertToTuple(vikram_2305989_sparse, vikram_2305989_rows, vikram_2305989_cols);
    return 0;
}