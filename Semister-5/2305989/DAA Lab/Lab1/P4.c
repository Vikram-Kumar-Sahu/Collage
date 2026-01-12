#include <stdio.h>

void EXCHANGE(int *p, int *q) 
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) 
{
    int i;
    for (i = p2 - 1; i > 0; i--) 
    {
        EXCHANGE(&p1[i], &p1[i - 1]);
    }
}

int main() 
{
    int N = 9;
    int A[9];
    int i;
    printf("Enter an array A of size N (9): ");
    for (i = 0; i < N; i++) 
    {
        scanf("%d", &A[i]);
    }
    printf("Before ROTATE: ");
    for (i = 0; i < N; i++) 
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    ROTATE_RIGHT(A, 5);
    printf("After ROTATE: ");
    for (i = 0; i < N; i++) 
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}