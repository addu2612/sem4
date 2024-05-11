#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 99999

void FloydWarshall() {
    int v;
    printf("Enter number of vertices: ");
    scanf("%d", &v);

    int distance[v][v];
    int parent[v][v]; // Parent matrix for reconstructing shortest paths

    printf("Enter the Weights:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            printf("Enter Weight of {%d,%d}: ", i, j);
            scanf("%d", &distance[i][j]);
            parent[i][j] = i; // Initialize parent matrix with direct edges
        }
    }

    // Initialize distances
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i == j)
                distance[i][j] = 0;
            else if(distance[i][j] == 0)
                distance[i][j] = INF;
        }
    }

    // Floyd Warshall Algorithm
    for(int k = 0; k < v; k++) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                if(distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    parent[i][j] = parent[k][j]; // Update parent matrix
                }
            }
        }
    }

    // Print the shortest distances and parent matrix
    printf("Shortest distances between vertices:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(distance[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", distance[i][j]);
        }
        printf("\n");
    }

    printf("\nParent matrix for shortest paths:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            printf("%d\t", parent[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Floyd Warshall Algorithm\n");
    FloydWarshall();
    return 0;
}
