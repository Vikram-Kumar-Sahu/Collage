#include <stdio.h>

typedef struct {
    int id;
    float profit, weight, ratio;
} ITEM;

void swap(ITEM *a, ITEM *b) { ITEM t = *a; *a = *b; *b = t; }

void heapify(ITEM arr[], int n, int i) {
    int largest = i, l = 2*i+1, r = 2*i+2;
    if (l < n && arr[l].ratio > arr[largest].ratio) largest = l;
    if (r < n && arr[r].ratio > arr[largest].ratio) largest = r;
    if (largest != i) { swap(&arr[i], &arr[largest]); heapify(arr, n, largest); }
}

void heapSort(ITEM arr[], int n) {
    for (int i = n/2-1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n-1; i >= 0; i--) { swap(&arr[0], &arr[i]); heapify(arr, i, 0); }
}

int main() {
    int n; float cap, total = 0;
    ITEM a[20];
    printf("Enter the number of items: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i+1);
        scanf("%f %f", &a[i].profit, &a[i].weight);
        a[i].id = i+1;
        a[i].ratio = a[i].profit / a[i].weight;
    }
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &cap);

    heapSort(a, n); // sort by ratio ascending
    // reverse order (non-increasing)
    for (int i = 0; i < n/2; i++) swap(&a[i], &a[n-1-i]);

    printf("\nItem No\tProfit\tWeight\tAmount to be taken\n");
    for (int i = 0; i < n && cap > 0; i++) {
        float take = (a[i].weight <= cap) ? 1.0 : cap / a[i].weight;
        total += a[i].profit * take;
        printf("%d\t%.6f\t%.6f\t%.6f\n", a[i].id, a[i].profit, a[i].weight, take);
        cap -= a[i].weight * take;
    }
    printf("Maximum profit: %.6f\n", total);
    return 0;
}
