#include <stdio.h>
#include <string.h>

void inputStrings5990(char X[], char Y[]) 
{
    printf("Enter the first string into an array: ");
    scanf("%s", X);
    printf("Enter the second string into an array: ");
    scanf("%s", Y);
}

int lcsLength5990(char X[], char Y[], int m, int n, int c[100][100], int b[100][100]) 
{
    for (int i = 0; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (X[i - 1] == Y[j - 1]) 
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            } 
            else if (c[i - 1][j] >= c[i][j - 1]) 
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            } 
            else 
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }
    }
    return c[m][n];
}

void printLCS5990(char X[], int b[100][100], int i, int j, char lcs[], int *index) 
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1) 
    {   
        printLCS5990(X, b, i - 1, j - 1, lcs, index);
        lcs[(*index)++] = X[i - 1];
    }
    else if (b[i][j] == 2) 
        printLCS5990(X, b, i - 1, j, lcs, index);
    else 
        printLCS5990(X, b, i, j - 1, lcs, index);
}

int main() 
{
    char X[100], Y[100], lcs[100];
    int c[100][100], b[100][100];
    inputStrings5990(X, Y);
    int m = strlen(X);
    int n = strlen(Y);
    int length = lcsLength5990(X, Y, m, n, c, b);
    int index = 0;
    printLCS5990(X, b, m, n, lcs, &index);
    lcs[index] = '\0';
    printf(" LCS: %s\n", lcs);
    printf(" LCS Length: %d\n", length);
    return 0;
}