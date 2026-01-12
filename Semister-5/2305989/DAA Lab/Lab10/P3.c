#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 16

typedef struct {
    int* bits;
    int size;
    int highest_one;
} BinaryCounter;

BinaryCounter* initCounter_5990(int size)
{
    BinaryCounter* counter = (BinaryCounter*)malloc(sizeof(BinaryCounter));
    counter->bits = (int*)calloc(size, sizeof(int));
    counter->size = size;
    counter->highest_one = -1;
    return counter;
}

void printCounter_5990(BinaryCounter* counter)
{
    for(int i = counter->size - 1; i >= 0; i--)
    {
        printf("%d ", counter->bits[i]);
    }
    printf("\n");
}

int increment_5990(BinaryCounter* counter)
{
    int cost = 0;
    int i = 0;
    
    while(i < counter->size && counter->bits[i] == 1)
    {
        counter->bits[i] = 0;
        cost++;
        i++;
    }
    
    if(i < counter->size)
    {
        counter->bits[i] = 1;
        cost++;
        if(i > counter->highest_one)
        {
            counter->highest_one = i;
        }
    }
    
    return cost;
}

int reset_5990(BinaryCounter* counter)
{
    int cost = 0;
    for(int i = 0; i <= counter->highest_one; i++)
    {
        if(counter->bits[i] == 1)
        {
            counter->bits[i] = 0;
            cost++;
        }
    }
    counter->highest_one = -1;
    return cost;
}

int main()
{
    BinaryCounter* counter = initCounter_5990(5);
    int total_cost = 0;
    
    printf("Initial state: ");
    printCounter_5990(counter);
    
    printf("\nIncrement 1: ");
    total_cost += increment_5990(counter);
    printCounter_5990(counter);
    
    printf("Increment 2: ");
    total_cost += increment_5990(counter);
    printCounter_5990(counter);
    
    printf("Reset 1: ");
    total_cost += reset_5990(counter);
    printCounter_5990(counter);
    
    printf("Increment 3: ");
    total_cost += increment_5990(counter);
    printCounter_5990(counter);
    
    printf("Reset 2: ");
    total_cost += reset_5990(counter);
    printCounter_5990(counter);
    
    printf("\nTotal cost of operations: %d\n", total_cost);
    
    free(counter->bits);
    free(counter);
    return 0;
}