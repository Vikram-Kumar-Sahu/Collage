#include <stdio.h>
#include <stdlib.h>

#define INF 9999
#define MAX 100

int n;                     // number of vertices
int cost[MAX][MAX];        // cost adjacency matrix
int dist[MAX][MAX];        // shortest path matrix
int next[MAX][MAX];        // path reconstruction matrix

// -------------------- Function Prototypes --------------------
void readMatrixFromFile(char *filename);
void floydWarshall();
void printDistanceMatrix();
void printPath(int u, int v);

// -------------------- MAIN FUNCTION --------------------
int main() {
    int u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    readMatrixFromFile("inDiAdjMat2.dat");
    floydWarshall();

    printf("\nShortest Path Weight Matrix:\n");
    printDistanceMatrix();

    printf("\nEnter the source and destination vertex: ");
    scanf("%d %d", &u, &v);

    printf("\nShortest Path from vertex %d to vertex %d: ", u, v);
    printPath(u - 1, v - 1);
    printf("\nPath weight: %d\n", dist[u - 1][v - 1]);

    return 0;
}

// -------------------- READ MATRIX FROM FILE --------------------
void readMatrixFromFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &cost[i][j]);
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF; // no direct edge
        }
    }

    fclose(fp);
}

// -------------------- FLOYD–WARSHALL ALGORITHM --------------------
void floydWarshall() {
    // Initialize dist and next matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = cost[i][j];
            if (cost[i][j] != INF && i != j)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    // Core Algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

// -------------------- PRINT DISTANCE MATRIX --------------------
void printDistanceMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// -------------------- RECONSTRUCT PATH --------------------
void printPath(int u, int v) {
    if (next[u][v] == -1) {
        printf("No path exists");
        return;
    }

    printf("%d", u + 1);
    while (u != v) {
        u = next[u][v];
        printf("-->%d", u + 1);
    }
}
