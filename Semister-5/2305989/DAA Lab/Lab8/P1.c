#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void inputDimensions5990(int p[], int *n) 
{
    printf("Enter number of matrices: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) 
    {
        int row, col;
        printf("Enter row and col size of A%d: ", i + 1);
        scanf("%d %d", &row, &col);
        if (i == 0) 
            p[0] = row;
        else if (p[i] != row) 
        {
            printf("Incompatible dimensions between A%d and A%d!\n", i, i + 1);
            exit(1);
        }
        p[i + 1] = col;
    }
}

void matrixChainOrder5990(int p[], int n, int m[10][10], int s[10][10]) 
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;
    for (int L = 2; L <= n; L++) 
    {
        for (int i = 1; i <= n - L + 1; i++) 
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) 
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) 
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printTable5990(int table[10][10], int n, const char *name) 
{
    printf("%s:\n", name);
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (j < i)
                printf("0 ");
            else
                printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

void printOptimalParens5990(int s[10][10], int i, int j, int n) 
{
    if (i == j)
        printf(" A%d ", i);
    else 
    {
        printf("(");
        printOptimalParens5990(s, i, s[i][j], n);
        printOptimalParens5990(s, s[i][j] + 1, j, n);
        printf(")");
    }
}

int main() 
{
    int n, p[11], m[10][10] = {0}, s[10][10] = {0};
    inputDimensions5990(p, &n);
    matrixChainOrder5990(p, n, m, s);

    printTable5990(m, n, "M Table");
    printTable5990(s, n, "S Table");

    printf("Optimal parenthesization: ");
    printOptimalParens5990(s, 1, n, n);
    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);
    return 0;
}