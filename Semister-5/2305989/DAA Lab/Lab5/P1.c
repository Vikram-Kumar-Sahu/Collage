#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
} ITEM;

void swap_items(ITEM *a, ITEM *b) 
{
    ITEM tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(ITEM arr[], int n, int i) 
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = l;
    if (r < n && arr[r].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = r;
    if (largest != i) 
    {
        swap_items(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort_by_ratio(ITEM arr[], int n) 
{
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Extract elements to sort (produces ascending order)
    for (int i = n - 1; i >= 1; i--) 
    {
        swap_items(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
    // Reverse to get non-increasing (descending) order
    for (int i = 0, j = n - 1; i < j; i++, j--)
        swap_items(&arr[i], &arr[j]);
}

int main(void) 
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM *items = (ITEM*)malloc(sizeof(ITEM) * n);
    if (!items) 
        return 0;

    for (int i = 0; i < n; i++) 
    {
        double p, w;
        printf("Enter the profit and weight of item no %d: ", i+1);
        if (scanf("%lf %lf", &p, &w) != 2) 
        { 
            free(items); 
            return 0; 
        }
        items[i].item_id = i + 1;
        items[i].item_profit = p;
        items[i].item_weight = w;
        if (w > 0.0)
            items[i].profit_weight_ratio = p / w;
        else
            items[i].profit_weight_ratio = 0.0; // guard against divide by zero
    }

    double capacity;
    printf("Enter the capacity of knapsack: ");
    if (scanf("%lf", &capacity) != 1) 
    {
        free(items); 
        return 0; 
    }

    heap_sort_by_ratio(items, n);

    double *amount = (double*)calloc(n, sizeof(double));
    double max_profit = 0.0;
    double remaining = capacity;

    for (int i = 0; i < n; ++i) 
    {
        if (remaining <= 0.0 || items[i].item_weight <= 0.0) 
        {
            amount[i] = 0.0;
            continue;
        }
        if (items[i].item_weight <= remaining) 
        {
            amount[i] = 1.0;
            remaining -= items[i].item_weight;
            max_profit += items[i].item_profit;
        } 
        else 
        {
            amount[i] = remaining / items[i].item_weight;
            max_profit += items[i].item_profit * amount[i];
            remaining = 0.0;
            break;
        }
    }

    printf("ItemNo.\t\tprofit\t\tWeight\t\tAmount to be taken\n");
    for (int i = 0; i < n; i++) 
        printf("%d\t %.6f\t %.6f\t %.6f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, amount[i]);

    printf("Maximum profit: %.6f\n", max_profit);

    free(items);
    free(amount);
    return 0;
}