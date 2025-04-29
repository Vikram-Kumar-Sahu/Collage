#include <stdio.h>

#define MAX 100

void transpose(int arr[MAX][MAX], int c, int r, int nz);
void sparce(int arr[MAX][MAX], int c, int r, int nz);
void print(int arr[MAX][3], int nz);

void transpose(int a[MAX][MAX], int c, int r, int nz) {
    int b[MAX][MAX]; 
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            b[j][i] = a[i][j];
        }
    }
    sparce(b, r, c, nz);  
}

void sparce(int a[MAX][MAX], int c, int r, int nz) {
    int b[MAX][3];
    int k = 1;

    b[0][0] = c;
    b[0][1] = r;
    b[0][2] = nz;

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            if (a[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    print(b, nz);
}

void print(int arr[MAX][3], int nz) {
    printf("Sparse Matrix Representation (row, col, value):\n");
    for (int i = 0; i <= nz; i++) {
        printf("%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}

int main() {
    int r, c;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int a[MAX][MAX];
    int z = 0, nz = 0;

    printf("Enter the matrix elements:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 0) {
                z++;
            } else {
                nz++;
            }
        }
    }

    if (nz > z) {
        printf("Not a sparse matrix.\n");
    } else {
        transpose(a, r, c, nz);
    }

    return 0;
}