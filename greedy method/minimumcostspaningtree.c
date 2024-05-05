#include <stdio.h>
#include <stdlib.h>


struct Edge {
    int src, dest, weight;
};


int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionVertices(int parent[], int x, int y) {
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);
    parent[xRoot] = yRoot;
}


void kruskalMST(struct Edge edges[], int V, int E) {
    struct Edge result[V];
    int parent[V];
    for (int i = 0; i < V; ++i)
        parent[i] = -1;

    qsort(edges, E, sizeof(struct Edge), compare);

    int count = 0;
    for (int i = 0; i < E; ++i) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        if (findParent(parent, src) != findParent(parent, dest)) {
            result[count++] = edges[i];
            unionVertices(parent, src, dest);
        }
    }

    printf("Edges in MST:\n");
    for (int i = 0; i < count; ++i)
        printf("%d -- %d (weight: %d)\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    struct Edge edges[] = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} };

    kruskalMST(edges, V, E);

    return 0;
} 

