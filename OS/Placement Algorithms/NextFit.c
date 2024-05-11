#include <stdio.h>

void nextFit(int blockSize[],int m,int processSize[],int n){
    int allocation[n];
    int t=m-1,j;
    
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    
    for(int i=0;i<n;i++){
        while(j<m){
            if(blockSize[j]>=processSize[i]){
                allocation[i]=j;
                blockSize[j]=blockSize[j]-processSize[i];
                
                t=(j-1)%m;
                break;
            }
            if(t==j){
                t=(j-1)%m;
                break;
            }
            
         j=(j+1)%m;
        }
       
    }
    
    printf("\n");
    printf("Pid\tsize\tblockallocated\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d",i+1,processSize[i]);
        if(allocation[i]!=-1){
            printf("\t%d\n",allocation[i]+1);
        }
        else{
            printf("\tNot allocated.");
        }
    }
}

int main(){
    int n,m;
    
    int blockSize[50], processSize[50];
    
    printf("Enter the number of blocks:");
    scanf("%d",&n);
    
    printf("blocks:");
    for(int i=0;i<n;i++){
        scanf("%d",&blockSize[i]);
    }
    
    printf("Enter the number of processes:");
    scanf("%d",&m);
    
    printf("processes:");
    for(int j=0;j<m;j++){
        scanf("%d",&processSize[j]);
    }
    
    nextFit(blockSize,n,processSize,m);
    
    return 0;
    
}
