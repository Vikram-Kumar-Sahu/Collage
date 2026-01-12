#include <stdio.h>
#include <limits.h>

#define MAX 10  

int m[MAX][MAX];
int s[MAX][MAX]; 

void printOptimalParenthesis2305989(int i, int j, int n, char *name) {
    if (i == j) {
        printf("%c", name[i - 1]); 
        return;
    }
    printf("(");
    printOptimalParenthesis2305989(i, s[i][j], n, name);
    printOptimalParenthesis2305989(s[i][j] + 1, j, n, name);
    printf(")");
}

void matrixChainOrder2305989(int p[], int n) {
  
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;


    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

// Function to print tables
void printTables2305989(int n) {
    printf("\nM Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i > j)
                printf("%7d ", 0);
            else
                printf("%7d ", m[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%7d ", s[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int p[MAX]; // store matrix dimensions

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    // Reading matrix dimensions
    int rows, cols;
    for (int i = 0; i < n; i++) {
        printf("Enter row and column size of A%d: ", i + 1);
        scanf("%d %d", &rows, &cols);

        if (i == 0)
            p[i] = rows;
        p[i + 1] = cols;
    }

    // Compute M and S tables
    matrixChainOrder2305989(p, n);

    // Print tables
    printTables2305989(n);

    // Print Optimal Parenthesization
    char name[MAX];
    for (int i = 0; i < n; i++)
        name[i] = 'A' + i;

    printf("\nOptimal parenthesization: ");
    printOptimalParenthesis2305989(1, n, n, name);

    printf("\nThe optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);

    return 0;
}
