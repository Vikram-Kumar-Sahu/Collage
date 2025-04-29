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
bool isSparce(int arr[MAX][MAX], int c, int r,int nz) {
    int i, j, z = 0;
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
void Sparce(int arr[MAX][MAX], int c, int r,int triplet[MAX][3], int *size) {
    int i, j, k = 1;
    

    triplet[0][0] = c;
    triplet[0][1] = r;
    triplet[0][2] = 0; 

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
    triplet[0][2] = k - 1; 
    *size = k;

    printf("Sparse Matrix in Triplet Form:\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}
void printTriplet(int triplet[MAX][3], int size) {
    printf("Sparse Matrix in Triplet Form:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

addSparce(int result[MAX][3],int triplet1[MAX][MAX],int triplet2[MAX][MAX],int *size1,int *size2,int *resultSize){
        if (triplet1[0][0] != triplet2[0][0] || triplet1[0][1] != triplet2[0][1]) {
        printf("Matrices dimensions do not match for addition!\n");
        return;
    }
    int i = 1, j = 1, k = 1;
    result[0][0] = triplet1[0][0];
    result[0][1] = triplet1[0][1];
    while (i < size1 && j < size2) {
        if (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] == triplet2[j][1]) {
            result[k][0] = triplet1[i][0];
            result[k][1] = triplet1[i][1];
            result[k][2] = triplet1[i][2] + triplet2[j][2];
            i++;
            j++;
        } while (i < size1 && j < size2) {
        if (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] == triplet2[j][1]) {
            result[k][0] = triplet1[i][0];
            result[k][1] = triplet1[i][1];
            result[k][2] = triplet1[i][2] + triplet2[j][2];
            i++;
            j++;
        } else if (triplet1[i][0] < triplet2[j][0] || (triplet1[i][0] == triplet2[j][0] && triplet1[i][1] < triplet2[j][1])) {
            result[k][0] = triplet1[i][0];
            result[k][1] = triplet1[i][1];
            result[k][2] = triplet1[i][2];
            i++;
        } else {
            result[k][0] = triplet2[j][0];
            result[k][1] = triplet2[j][1];
            result[k][2] = triplet2[j][2];
            j++;
        }
        k++;
    }

    while (i < size1) {
        result[k][0] = triplet1[i][0];
        result[k][1] = triplet1[i][1];
        result[k][2] = triplet1[i][2];
        i++;
        k++;
    }

    while (j < size2) {
        result[k][0] = triplet2[j][0];
        result[k][1] = triplet2[j][1];
        result[k][2] = triplet2[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;
    *resultSize = k;
}
}
int main() {
    int c, r,nz=0;
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    int *size1,*size2,*resultSize;
    int arr1[MAX][MAX];  
    int arr2[MAX][MAX]; 
    int triplet1[MAX][3]; 
    int triplet2[MAX][3]; 
    int result[MAX][3];
    accept(arr1, c, r);
    accept(arr2, c, r);
    printMatrix(arr1,c,r);
    printMatrix(arr2,c,r);
    if (isSparce(arr1, c, r,nz)&&isSparce(arr2, c, r,nz) ){
        printf("The matrix is sparse.\n");
        Sparce(arr1, c, r,triplet1, &size1);
        Sparce(arr2, c, r,triplet2, &size2);
        
         printf("First matrix in triplet form:\n");
        printTriplet(triplet1, size1);

        printf("Second matrix in triplet form:\n");
        printTriplet(triplet2, size2);

        addSparce(triplet1, triplet2, result, size1, size2, &resultSize);
        printf("Resultant matrix after addition in triplet form:\n");
        printTriplet(result, resultSize);
    } else {
        printf("The matrix is not sparse.\n");
    }
    return 0;
}
