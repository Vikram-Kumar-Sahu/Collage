#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int u, v, w;
} Edge;

int compare(const void *a, const void *b)
{
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(int parent[], int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void kruskalMST5990(int n, int m, Edge edges[])
{
    int parent[n + 1];
    for (int i = 0; i <= n; i++)
        parent[i] = -1;

    qsort(edges, m, sizeof(edges[0]), compare);

    printf("Selected edges in the Minimum Spanning Tree:\n");
    int totalCost = 0;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int x = find(parent, u);
        int y = find(parent, v);

        if (x != y)
        {
            printf("%d -- %d == %d\n", u, v, w);
            totalCost += w;
            unionSets(parent, x, y);
        }
    }
    printf("Total cost of the Minimum Spanning Tree: %d\n", totalCost);
}

int main()
{
    int n, m;
    FILE *file = fopen("inUnAdjMat1.dat", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file\n");
        return 1;
    }

    fscanf(file, "%d %d", &n, &m);
    
    Edge edges[m];
    for (int i = 0; i < m; i++)
    {
        fscanf(file, "%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    fclose(file);
    kruskalMST5990(n, m, edges);
    return 0;
}