#include <stdio.h>
#include <stdlib.h>

typedef struct { int u, v, w; } Edge;
Edge edges[100];
int parent[100];

int find(int i) { return (parent[i] == i) ? i : (parent[i] = find(parent[i])); }
void unionSet(int a, int b) { parent[find(a)] = find(b); }

int cmp(const void *a, const void *b) { return ((Edge*)a)->w - ((Edge*)b)->w; }

int main() {
    int n, m, total = 0;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (int i = 1; i <= n; i++) parent[i] = i;
    qsort(edges, m, sizeof(Edge), cmp);

    printf("\nEdge\tCost\n");
    for (int i = 0, e = 0; i < m && e < n - 1; i++) {
        int a = find(edges[i].u), b = find(edges[i].v);
        if (a != b) {
            printf("%d--%d\t%2d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            unionSet(a, b);
            e++;
        }
    }
    printf("Total Weight of the Spanning Tree: %d\n", total);
    return 0;
}
