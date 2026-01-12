#include <stdio.h>
#include <limits.h>

#define MAX 50
int n;

int minKey(int key[], int mstSet[])
{
    int min = INT_MAX, idx = -1;
    for (int i = 0; i < n; i++)
        if (!mstSet[i] && key[i] < min)
        {
            min = key[i];
            idx = i;
        }
    return idx;
}

void primMST(int g[MAX][MAX], int start)
{
    int parent[MAX], key[MAX], mstSet[MAX], mst[MAX][MAX] = {0}, total = 0;
    for (int i = 0; i < n; i++) 
    {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[start] = 0; parent[start] = -1;

    for (int c = 0; c < n - 1; c++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++)
            if (g[u][v] && !mstSet[v] && g[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = g[u][v];
            }
    }

    for (int i = 0; i < n; i++)
        if (parent[i] != -1) 
        {
            mst[i][parent[i]] = g[i][parent[i]];
            mst[parent[i]][i] = g[i][parent[i]];
            total += g[i][parent[i]];
        }

    printf("\nCost Adjacency Matrix of MST:\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) printf("%d ", mst[i][j]);
        printf("\n");
    }
    printf("\nTotal Weight of the Spanning Tree: %d\n", total);
}

int main()
{
    FILE *fp = fopen("inUnAdjMat.dat", "r");
    if (!fp) return printf("File error\n"), 1;
    
    int g[MAX][MAX], start;
    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);
    printf("Enter the Starting Vertex (1 to %d): ", n);
    scanf("%d", &start);
    
    if (start < 1 || start > n) 
    {
        printf("Invalid starting vertex.\n");
        fclose(fp);
        return 1;
    }
    
    start--;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(fp, "%d", &g[i][j]);
    fclose(fp);

    primMST(g, start);
    return 0;
}