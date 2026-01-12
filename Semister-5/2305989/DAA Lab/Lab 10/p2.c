#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 50

void print_fitstring_2395989(int fit[], int n) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        printf("%d", fit[i]);
    }
}

int get_value_2395989(int fit[], int n) {
    int fib[MAX_BITS];
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    int value = 0;
    for (int i = 0; i < n; i++) {
        if (fit[i]) {
            value += fib[i];
        }
    }
    return value;
}

void normalize_2395989(int fit[], int n) {
    for (int i = 0; i < n - 2; i++) {
        if (fit[i] == 1 && fit[i+1] == 1) {
            fit[i] = 0;
            fit[i+1] = 0;
            fit[i+2] = 1;
        }
    }
}

void increment_fitstring_2395989(int fit[], int n) {
    if (fit[0] == 0 && fit[1] == 0) {
        fit[0] = 1;
    } else if (fit[0] == 1 && fit[1] == 0) {
        fit[0] = 0;
        fit[1] = 1;
    } else if (fit[0] == 0 && fit[1] == 1) {
        fit[0] = 1;
        fit[1] = 1;
        normalize_2395989(fit, n);
    } else {
        fit[0] = 0;
        fit[1] = 0;
        fit[2] = 1;
        normalize_2395989(fit, n);
    }
}

void decrement_fitstring_2395989(int fit[], int n) {
    if (fit[0] == 1 && fit[1] == 0) {
        fit[0] = 0;
    } else if (fit[0] == 0 && fit[1] == 1) {
        fit[0] = 1;
        fit[1] = 0;
    } else if (fit[0] == 1 && fit[1] == 1) {
        fit[0] = 0;
        fit[1] = 1;
    } else {
        int i = 1;
        while (i < n && fit[i] == 0) {
            i++;
        }
        if (i < n) {
            fit[i] = 0;
            fit[i-1] = 1;
            fit[i-2] = 1;
        }
    }
}

int main() {
    int n = 10;
    int fit[MAX_BITS] = {0};
    
    printf("Fitstring Increment Operations:\n");
    printf("%-20s %-10s\n", "Fitstring", "Value");
    printf("%-20s %-10d\n", "000000", get_value_2395989(fit, n));
    
    for (int i = 0; i < 5; i++) {
        increment_fitstring_2395989(fit, n);
        printf("");
        print_fitstring_2395989(fit, n);
        printf("%10d\n", get_value_2395989(fit, n));
    }
    
    printf("\nFitstring Decrement Operations:\n");
    printf("%-20s %-10s\n", "Fitstring", "Value");
    for (int i = 0; i < 5; i++) {
        print_fitstring_2395989(fit, n);
        printf("%10d\n", get_value_2395989(fit, n));
        decrement_fitstring_2395989(fit, n);
    }
    
    return 0;
}
