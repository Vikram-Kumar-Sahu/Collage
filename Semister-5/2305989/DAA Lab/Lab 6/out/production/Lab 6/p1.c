#include <stdio.h>

typedef struct {
    int item_id;
    int item_profit;
    int item_weight;
    float profit_weight_ratio;
} ITEM;

// Heapify function for heap sort
void heapify(ITEM arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = l;
    if (r < n && arr[r].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = r;

    if (largest != i) {
        ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

// Heap sort function
void heapSort(ITEM arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n-1; i >= 0; i--) {
        ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i+1);
        scanf("%d %d", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i+1;
        items[i].profit_weight_ratio = (float)items[i].item_profit / items[i].item_weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    heapSort(items, n);

    float max_profit = 0.0;
    int remaining = capacity;

    for (int i = 0; i < n && remaining > 0; i++) {
        if (items[i].item_weight <= remaining) {
            max_profit += items[i].item_profit;
            remaining -= items[i].item_weight;
        } else {
            max_profit += items[i].profit_weight_ratio * remaining;
            remaining = 0;
        }
    }

    printf("Maximum profit nearest to but not exceeding knapsack capacity: %.2f\n", max_profit);
    return 0;
}