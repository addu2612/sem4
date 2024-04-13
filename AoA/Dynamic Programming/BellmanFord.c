#include <stdio.h>
#define SIZE 5
int graph[SIZE][SIZE] = {
    {0, 6, 0, 7, 0},  // a
    {0, 0, 5, 8, -4}, // b
    {0, -2, 0, 0, 0}, // c
    {0, 0, -3, 0, 9}, // d
    {2, 0, 7, 0, 0}   // e
};
int distance[SIZE], parent[SIZE];
int inf = 999;

void printResults() {
    printf("Vertex\tDist\tParent\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d\t%d\t%d\n", i, distance[i], parent[i]);
    }
}

void initializeSingleSource() {
    for (int i = 0; i < SIZE; i++) {
        distance[i] = inf;
        parent[i] = -1;
    }
    distance[0] = 0;
}

void relaxEdges() {
    for (int u = 0; u < SIZE; u++) {
        for (int v = 0; v < SIZE; v++) {
            if (graph[u][v] != 0 && distance[v] > distance[u] + graph[u][v]) {
                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

int main() {
    initializeSingleSource();
    for (int i = 0; i < SIZE - 1; i++) {
        relaxEdges();
    }
    // Perform one more iteration to check for negative cycles
    for (int u = 0; u < SIZE; u++) {
        for (int v = 0; v < SIZE; v++) {
            if (graph[u][v] != 0 && distance[v] > distance[u] + graph[u][v]) {
                printf("Negative cycle detected!\n");
                return 0;
            }
        }
    }
    printf("No negative cycle detected.\n");
    printResults();
    return 0;
}
