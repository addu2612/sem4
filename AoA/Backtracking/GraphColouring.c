#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int colours[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];
int n_vertices; //number of vertices
int n_edges;   //number of edges

bool isValid(int vertex, int colour) {
    for (int i = 0; i < n_vertices; i++) {
        // Check if the current vertex is adjacent to vertex i
        // and if the color of vertex i is the same as the given color
        if (graph[vertex][i] && colours[i] == colour) {
            return false;
        }
    }
    return true;
}

int graphColouring() {
    int min_colours = 0; // Initialize the minimum number of colors used
    for (int vertex = 0; vertex < n_vertices; vertex++) { 
        int available[MAX_VERTICES + 1]; // We add one extra slot for colors (from 1 to n_vertices)
        for (int i = 0; i <= n_vertices; i++) { 
            // Initialize all colors as available
            available[i] = true;
        }
        for (int i = 0; i < vertex; i++) { 
            // Check adjacent vertices and mark their colors as unavailable
            if (graph[vertex][i] && colours[i] != -1) {
                available[colours[i]] = false;
            }
        }
        int color;
        for (color = 1; color <= n_vertices; color++) { 
            // Find the lowest available color
            if (available[color]) {
                break;
            }
        }
        colours[vertex] = color; // Assign the lowest available color to the vertex
        if (color > min_colours) { 
            // Update the minimum number of colors used
            min_colours = color;
        }
    }
    return min_colours; 
}


int main() {
    printf("Graph Colouring Algorithm\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n_vertices);
    printf("Enter number of edges: ");
    scanf("%d", &n_edges);

    for (int i = 0; i < n_vertices; i++) {
        colours[i] = -1;
        for (int j = 0; j < n_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < n_edges; i++) {
        int u, v;
        printf("Enter edge %d (both vertices): ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    int min_colours = graphColouring();

    printf("The minimum number of colors needed: %d\n", min_colours);
    printf("Vertices\tColours\n");
    for (int i = 0; i < n_vertices; i++) {
        printf("Vertex %d:\t%d\n", i, colours[i]);
    }

    return 0;
}
