#include <stdio.h>
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int remainingMemory[m];
    int occupied[m];
    for (int i = 0; i < n; i++){
        allocation[i] = -1;
    }
    for (int i = 0; i < m; i++){
        remainingMemory[i] = blockSize[i];
    }
    
    for(int i=0;i<m;i++){
        occupied[i]=0;
    }
    
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i] && !occupied[j] ) {
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
                }
            }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            occupied[bestIdx]=1;
            blockSize[bestIdx] -= processSize[i];
            remainingMemory[bestIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\tRemaining Memory\n");
    for (int i = 0; i < n; i++) {

        printf(" %d\t\t\t%d\t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\t\t\t\t%d", allocation[i] + 1, remainingMemory[allocation[i]]);
        else
            printf("Not Allocated\t\t-");
        printf("\n");
    }
}
int main() {
    int blockSize[100], processSize[100];
    int m, n;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the size of each process:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &processSize[i]);
    bestFit(blockSize, m, processSize, n);
    return 0;
}




