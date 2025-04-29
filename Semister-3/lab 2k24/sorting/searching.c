#include <stdio.h>

void linear(int a[], int n, int data) {
    int i;
    for (i = 0; i < n; i++) {
        if (a[i] == data) {
            printf("Element %d found at index %d (Linear Search)\n", data, i);
            return;
        }
    }
    printf("Element %d not found (Linear Search)\n", data);
}

int binary(int a[], int n, int data) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (data == a[mid])
            return mid;
        else if (data < a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

void bubble(int a[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void insert(int a[],int n){
    int temp,i,j;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    
}

void selection(int a[],int n){
    int j,i;
    for(i=0;i<n;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
            if(min!=i){
                int temp=a[i];
                a[i]=a[min];
                a[min]=temp;
            }
        }
    }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int data;

    printf("Enter element to search: ");
    scanf("%d", &data);

    // Perform linear search
    linear(arr, n, data);

    // Perform binary search
    int index = binary(arr, n, data);
    if (index != -1)
        printf("Element %d found at index %d (Binary Search)\n", data, index);
    else
        printf("Element %d not found (Binary Search)\n", data);

    return 0;
}
