#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define MAX_VERTICES 100

void readGraphFromFile5990(int graph[MAX_VERTICES][MAX_VERTICES], int n, const char* filename)
{
    FILE* file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(fscanf(file, "%d", &graph[i][j]) != 1)
            {
                printf("Error reading from file \n");
                exit(1);
            }
            if(i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }
    fclose(file);
}

void floydWarshall5990(int graph[MAX_VERTICES][MAX_VERTICES], int dist[MAX_VERTICES][MAX_VERTICES], int next[MAX_VERTICES][MAX_VERTICES], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            dist[i][j] = graph[i][j];
            if (graph[i][j] != INF && i != j) 
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

void printPath5990(int dist[MAX_VERTICES][MAX_VERTICES], int next[MAX_VERTICES][MAX_VERTICES], int u, int v, int n) 
{
    if (next[u - 1][v - 1] == -1) 
    {
        printf("No path exists between vertex %d and vertex %d\n", u, v);
        return;
    }

    printf("Shortest Path from vertex %d to vertex %d: %d", u, v, u);
    int current = u - 1;
    while (current != v - 1) 
    {
        current = next[current][v - 1];
        printf("-->%d", current + 1);
    }
    printf("\n");
    printf("Path weight: %d\n", dist[u-1][v-1]);
}

void printMatrix5990(int matrix[MAX_VERTICES][MAX_VERTICES], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (matrix[i][j] == INF) 
                printf("%7s", "INF");
            else
                printf("%7d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int dist[MAX_VERTICES][MAX_VERTICES];
    int next[MAX_VERTICES][MAX_VERTICES];
    int source, dest;

    printf("Number of Vertices: ");
    scanf("%d", &n);

    readGraphFromFile5990(graph, n, "inDiAdjMat2.dat");
    floydWarshall5990(graph, dist, next, n);

    printf("Enter the source and destination vertex: ");
    scanf("%d %d", &source, &dest);

    printf("\n");
    printMatrix5990(dist, n);
    printf("\n");

    printPath5990(dist, next, source, dest, n);

    return 0;
}