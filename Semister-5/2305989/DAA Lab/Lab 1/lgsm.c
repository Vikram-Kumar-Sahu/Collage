#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("input.txt","r");
    if( fp == NULL ){
        printf("Error opening file. \n");
        return 1;
    }
    int n;
    fscanf(fp, "%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i=0;i<n;i++){
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    int min = arr[0], second_min = __INT_MAX__;
    int max = arr[0], second_max = -__INT_MAX__;
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            second_min = min;
            min = arr[i];
        } else if (arr[i] < second_min && arr[i] != min) {
            second_min = arr[i];
        }
        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }

    printf("Second smallest: %d\n", second_min);
    printf("Second largest: %d\n", second_max);

    free(arr);
    return 0;

}
