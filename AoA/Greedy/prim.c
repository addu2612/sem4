#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INFINITY 999

int cost[MAX][MAX];
int list[MAX];
int nodes[MAX];
int distance[MAX], parent[MAX];

void initialize(int n) {
    int i;
    for (i = 0; i < n; i++) {
        list[nodes[i]] = 0;
        distance[nodes[i]] = INFINITY;
        parent[nodes[i]] = INFINITY;
    }
    distance[nodes[0]] = 0;
}

void relax(int u, int v) {
    distance[v] = (distance[v] > distance[u] + cost[u][v]) ? distance[u] + cost[u][v] : distance[v];
}

int extractMin(int n) {
    int i;
    int min = MAX;
    int mini = -1;
    for (i = 0; i < n; i++) {
        if (distance[nodes[i]] < min && list[nodes[i]] != 1) {
            mini = nodes[i];
            min = distance[nodes[i]];
        }
    }
    if (mini != -1)
        list[mini] = 1;
    return mini;
}

void prims(int n) {
    int i, j, k, u, v;
    u = extractMin(n);
    while (u != -1) {
        for (i = 0; i < n; i++) {
            if (cost[u][nodes[i]] != INFINITY && list[nodes[i]] != 1) {
                distance[nodes[i]] = cost[u][nodes[i]];
            }
        }
        u = extractMin(n);
    }
}

int main() {
    int i, j, k, n, e, u, v, a, b, w;
    int l;
    printf("Number of nodes:\n");
    scanf("%d", &n);
    printf("Enter nodes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &nodes[i]);
    }
    printf("Number of edges:\n");
    scanf("%d", &e);
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            cost[i][j] = INFINITY;
        }
    }
    printf("Enter the startnode endnode weight:\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &a, &b, &w);
        cost[a][b] = w;
        cost[b][a] = w;
    }
    
    initialize(n);
    prims(n);
    printf("The final distances are:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", distance[nodes[i]]);
    }
    return 0;
}
