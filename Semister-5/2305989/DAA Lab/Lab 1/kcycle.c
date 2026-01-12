#include<stdio.h>

void rotate(int arr[],int n,int a){
    for(int i=0; i<a-1;i++){
        int temp= arr[i+1];
        arr[i+1]= arr[0];
        arr[0]=temp;
    }
    
}

int main() {
    int n, a;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of rotations: ");
    scanf("%d", &a);

    rotate(arr, n, a);

    printf("Array after %d left rotations:\n", a);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}