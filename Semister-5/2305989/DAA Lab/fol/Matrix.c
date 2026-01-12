#include <stdio.h>
#include <limits.h>


void printOptimalParens(int s[20][20], int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else{
        printf("(");
        printOptimalParens(s,i,s[i][j]);
        printf(" ");
        printOptimalParens(s,s[i][j]+1,j);
        printf(")");
    }
}


int main()
{
    int n;
    int p[20];       
    int m[20][20];   
    int s[20][20];   

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int rows, cols;
    for (int i = 1; i <= n; i++)
    {
        printf("Enter row and col size of A%d: ", i);
        scanf("%d %d", &rows, &cols);

        if (i == 1)
            p[0] = rows;
        p[i] = cols;    
    }

 
    for (int i = 1; i < n; i++)
    {
        if (p[i - 1 + 1] != p[i])
        {
  
            continue;
        }
    }


    for (int i = 1; i <= n; i++)
        m[i][i] = 0; 

    for (int L = 2; L <= n; L++)
    {
        for (int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
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


    printf("\nM Table:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                printf("%7d", 0);
            else
                printf("%7d", m[i][j]);
        }
        printf("\n");
    }


    printf("\nS Table:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= i)
                printf("%7d", 0);
            else
                printf("%7d", s[i][j]);
        }
        printf("\n");
    }


    printf("\nOptimal parenthesization: ");
    printOptimalParens(s, 1, n);

    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);

    return 0;
}
