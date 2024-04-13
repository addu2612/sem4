#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Some error when printing the values of min_colours.CHECK

int colours[100];
int graph[100][100];
int n_vertices; //number of vertices
int n_edges;     //number of edges

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


bool graphColouring(int vertex) {
    // if we reach the last vertex, it means all colours have been assigned
    if (vertex == n_vertices) {
        return true;
    }
    // we use colors 1 to m, 0 is no color
    for (int i = 1; i <= n_vertices; i++) {
        if (isValid(vertex, i)) {
            colours[vertex] = i;
            if (graphColouring(vertex + 1)) // true is returned continuously till some node, ensures that color can be placed till current node
            {
                return true;
            }
            //if false is returned by v+1 then the given v is assigned invalid color so reset and try other colors
            colours[vertex] = 0;
        }
    }
    return false;
}

int main() {
    int i, j;
    printf("Graph Colouring Algorithm\n");
    printf("Enter number of vertices:");
    scanf("%d", &n_vertices);
    printf("Enter number of edges:");
    scanf("%d", &n_edges);

    //initialize colours and graph to 0
    for (i = 0; i < n_vertices; i++) {
        colours[i] = 0;
        for (int j = 0; j < n_vertices; j++) {
            graph[i][j] = 0;
        }
    }

    //mark valid edges 1
    for (i = 0; i < n_edges; i++) {
        int u, v;
        printf("Enter the edge %d (both vertices) : ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    // Find the minimum number of colors needed
    int min_colours = 1;
    while (!graphColouring(0)) {
        min_colours++;
        for (int i = 0; i < n_vertices; i++) {
            colours[i] = 0; // Reset colours for the next attempt
        }
    }


    printf("The vertices can be coloured with %d colours\n", min_colours);
    printf("Vertices \t Colours\n");
    for (i = 0; i < n_vertices; i++) {
        printf("Vertex %d :\t%d\n", i, colours[i]);
    }

    return 0;
}
