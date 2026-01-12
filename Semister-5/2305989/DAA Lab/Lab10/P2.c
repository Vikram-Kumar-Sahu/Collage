#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_FIB 93
#define FITSTR_LEN (MAX_FIB+1)

unsigned long long fib[MAX_FIB];

void generateFibonacci5990() 
{
    fib[0] = 1ULL;
    fib[1] = 2ULL;
    for (int i = 2; i < MAX_FIB; i++) 
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void incrementFitstring5990(char *fitstring) 
{
    unsigned long long n = 0ULL;
    for (int i = 0; fitstring[i] != '\0' && i < MAX_FIB; i++) 
    {
        if (fitstring[i] == '1') 
        {
            n += fib[i];
        }
    }

    n++;

    int highest = -1;
    for (int i = MAX_FIB - 1; i >= 0; i--) 
    {
        if (fib[i] <= n) 
        {
            fitstring[i] = '1';
            n -= fib[i];
            if (highest < i) highest = i;
        } 
        else 
        {
            fitstring[i] = '0';
        }
    }

    if (highest >= 0) 
    {
        if (highest + 1 < FITSTR_LEN) fitstring[highest + 1] = '\0';
        else fitstring[FITSTR_LEN - 1] = '\0';
    } 
    else 
    {
        fitstring[0] = '0';
        fitstring[1] = '\0';
    }
}

void decrementFitstring5990(char *fitstring) 
{
    unsigned long long n = 0ULL;
    for (int i = 0; fitstring[i] != '\0' && i < MAX_FIB; i++) 
    {
        if (fitstring[i] == '1') 
        {
            n += fib[i];
        }
    }

    if (n > 0) 
    {
        n--;

        int highest = -1;
        for (int i = MAX_FIB - 1; i >= 0; i--) 
        {
            if (fib[i] <= n) 
            {
                fitstring[i] = '1';
                n -= fib[i];
                if (highest < i) highest = i;
            } 
            else 
            {
                fitstring[i] = '0';
            }
        }

        if (highest >= 0) 
        {
            if (highest + 1 < FITSTR_LEN) fitstring[highest + 1] = '\0';
            else fitstring[FITSTR_LEN - 1] = '\0';
        } 
        else 
        {
            fitstring[0] = '0';
            fitstring[1] = '\0';
        }
    }
    else
    {
        fitstring[0] = '0';
        fitstring[1] = '\0';
    }
}

int main() 
{
    char fitstring[FITSTR_LEN] = "101110";
    generateFibonacci5990();
    
    printf("Original fitstring: %s\n", fitstring);
    
    incrementFitstring5990(fitstring);
    printf("After increment: %s\n", fitstring);
    
    decrementFitstring5990(fitstring);
    printf("After decrement: %s\n", fitstring);
    
    return 0;
}
