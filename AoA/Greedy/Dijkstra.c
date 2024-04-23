#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

int graph[SIZE][SIZE];
int distances[SIZE], parents[SIZE];
int inf = 999;
int n; // Variable to store the size of the matrix

void InitializeSingleSource(){
    for(int i = 0; i < SIZE; i++){
        distances[i] = inf;
        parents[i] = -1;
    }
}

void Relax(int u, int v){
    if(distances[v] > distances[u] + graph[u][v]){
        distances[v] = distances[u] + graph[u][v];
        parents[v] = u;
    }
}

void Dijkstra(int source){
    InitializeSingleSource();
    bool visited[SIZE] = {false}; // Array to keep track of visited vertices
    distances[source] = 0; // Distance from source to itself is 0

    for(int count = 0; count < SIZE - 1; count++){
        int u = -1; // Initialize u to an invalid vertex
        // Find the vertex with the minimum distance that has not been visited
        for(int i = 0; i < SIZE; i++){
            if(!visited[i] && (u == -1 || distances[i] < distances[u])){
                u = i;
            }
        }

        visited[u] = true; // Mark the vertex as visited

        // Relax all adjacent vertices of the current vertex
        for(int v = 0; v < SIZE; v++){
            if(graph[u][v] != 0){
                Relax(u, v);
            }
        }
    }
}

void printResults(){
    printf("Vertex\tDist\tParent\n");
    for(int i = 0; i < SIZE; i++){
        printf("%d\t%d\t%d\n", i, distances[i], parents[i]);
    }
}

int main(){
    printf("Dijkstra Algorithm\n");
    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    printf("Enter the weights for each row:\n");
    for(int i = 0; i < n; i++){
        printf("Row %d: ", i + 1);
        for(int j = 0; j < n; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    Dijkstra(source);

    printf("Shortest paths from source vertex %d:\n", source);
    printResults();

    return 0;
}
