#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int minDistance5990(int dist[], bool sptSet[], int V);
void printPath5990(int parent[], int j);
void printSolution5990(int dist[], int V, int parent[], int src);
void dijkstra5990(int graph[][100], int src, int V);

void dijkstra5990(int graph[][100], int src, int V)
{
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance5990(dist, sptSet, V);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSolution5990(dist, V, parent, src);
}

int minDistance5990(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath5990(int parent[], int j)
{
    if (parent[j] == -1)
        return;

    printPath5990(parent, parent[j]);
    printf("->%d", j + 1);
}

void printSolution5990(int dist[], int V, int parent[], int src)
{
    printf("\nVertex\t Distance\tPath");
    for (int i = 0; i < V; i++)
    {
        if (i != src)
        {
            printf("\n%d\t %d\t\t%d", i + 1, dist[i], src + 1);
            printPath5990(parent, i);
        }
    }
    printf("\n");
}

int main()
{
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];
    FILE *fp = fopen("inDiAdjMat.dat", "r");
    if (fp == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            fscanf(fp, "%d", &graph[i][j]);
    }
    fclose(fp);

    int src;
    printf("Enter the source vertex (1 to %d): ", V);
    scanf("%d", &src);
    src--;

    dijkstra5990(graph, src, V);
    return 0;
}
