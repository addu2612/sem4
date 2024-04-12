#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 99999

typedef struct {
    int d;  // Shortest distance estimate
    int pi; // Parent
} Vertex;

// Function to initialize single source
void InitializeSingleSource(Vertex G[], int n, int s) {
    // Initialize shortest distance estimates and predecessors
    for (int i = 0; i < n; i++) {
        G[i].d = INF; // Infinity
        G[i].pi = -1; // NIL
    }
    G[s].d = 0;  // Set distance of source vertex to 0
}

void Relax(Vertex* u, Vertex* v, int w) {
    if (v->d > u->d + w) {
        v->d = u->d + w;  // Update shortest distance estimate of v
        v->pi = u->pi;    // Update parent of v
    }
}

void BellmanFord(Vertex G[],int w,int s){
    InitializeSingleSource(G,s);
    for(int i=1;G.Vertex-1)

}

int main(){
    BellmanFord();
    return 0;
}