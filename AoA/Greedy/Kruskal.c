#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int parent[10];

int findParent(int i){
    while(parent[i]){
        i=parent[i];
    }
    return i;
}

int unionSets(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main(){
    int cost[10][10],minCost=999,totalCost=0;
    int numVertices;
    printf("Enter number of vertices: ");
    scanf("%d",&numVertices);
    printf("Enter the elements of cost matrix");
    for(int i=0;i<numVertices;i++){
        for(int j=0;j<numVertices;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0){
                cost[i][j]=999;
            }
        }
    }

    int numEdges=0;
    int vertexA,vertexB,parentA,parentB;
    while(numEdges <numVertices -1){
        minCost=999;
        for(int i=0;i<numVertices;i++){
            for(int j=0;j<numVertices;j++){
                if(cost[i][j]<minCost){
                    minCost=cost[i][j];
                    vertexA=parentA=i;
                    vertexB=parentB=j;
                }
            }
        }
        parentA=findParent(parentA);
        parentB=findParent(parentB);
        if(unionSets(parentA,parentB)){
            printf("Vertex %d Edges %d-%d\n",numEdges,vertexA,vertexB);
            printf("Min %d\n",minCost);
            totalCost +=minCost;
        }
        cost[vertexA][vertexB]=cost[vertexB][vertexA]=999;
        numEdges++;
    }
    printf("Minimum cost : %d\n",totalCost);

    return 0;
}