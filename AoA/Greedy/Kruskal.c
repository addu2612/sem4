#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int parent[MAX_VERTICES];
int rank[MAX_VERTICES];

int find(int);
void unionSets(int, int);

void kruskals(int n, int cost[][MAX_VERTICES]) {
    int ne = 0, mincost = 0, a = 0, b = 0, u = 0, v = 0, min;

    // Initialize parent and rank arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");

    while (ne < n - 1) {
        min = 999; // Initialize min to a large value
        a = b = -1; // Initialize a and b to invalid values
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // Iterate only over the upper triangle of the cost matrix
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        if (a == -1 || b == -1) {
            printf("No more edges found or graph disconnected.\n");
            break; // Break the loop if no valid edges are found or the graph is disconnected
        }

        u = find(u);
        v = find(v);

        if (u != v) {
            printf("Edge %d: (%d, %d) cost: %d\n", ne + 1, a, b, min);
            ne++;
            mincost += min;
            unionSets(u, v);
        }

        cost[a][b] = cost[b][a] = 999; // Mark the edge as visited
    }

    printf("\nMinimum cost of spanning tree: %d\n", mincost);
}

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSets(int i, int j) {
    if (rank[i] > rank[j]) {
        parent[j] = i;
    } else if (rank[i] < rank[j]) {
        parent[i] = j;
    } else {
        parent[j] = i;
        rank[i]++;
    }
}

int main() {
    int n, cost[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    kruskals(n, cost);

    return 0;
}
