#include <stdio.h>

#define SIZE 5

void _2305989_printCounter(int A[]) {
    for (int i = SIZE - 1; i >= 0; i--)
        printf("%d ", A[i]);
}

int _2305989_incrementCounter(int A[]) {
    int i = 0, cost = 0;
    while (i < SIZE && A[i] == 1) {
        A[i] = 0;
        cost++;
        i++;
    }
    if (i < SIZE) {
        A[i] = 1;
        cost++;
    }
    return cost;
}

int _2305989_resetCounter(int A[]) {
    int cost = 0;
    for (int i = 0; i < SIZE; i++) {
        if (A[i] == 1) {
            A[i] = 0;
            cost++;
        }
    }
    return cost;
}

int main() {
    int A[SIZE] = {0};
    int cost;

    printf("Bit4 Bit3 Bit2 Bit1 Bit0\tOperation\tCost\n");
    _2305989_printCounter(A);
    printf("\tInitial\t\t0\n");

    cost = _2305989_incrementCounter(A);
    _2305989_printCounter(A);
    printf("\tIncrement\t%d\n", cost);

    cost = _2305989_incrementCounter(A);
    _2305989_printCounter(A);
    printf("\tIncrement\t%d\n", cost);

    cost = _2305989_resetCounter(A);
    _2305989_printCounter(A);
    printf("\tReset\t\t%d\n", cost);

    cost = _2305989_incrementCounter(A);
    _2305989_printCounter(A);
    printf("\tIncrement\t%d\n", cost);

    cost = _2305989_resetCounter(A);
    _2305989_printCounter(A);
    printf("\tReset\t\t%d\n", cost);

    return 0;
}
