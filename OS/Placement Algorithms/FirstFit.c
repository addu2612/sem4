#include <stdio.h>

int firstFit(int processSize[],int m,int blockSize[],int n){
    int i,j;
    int allocation[m];
    //int occupied[n];
    int total=0;
    for(i=0;i<m;i++){
        allocation[i]=-1;
    }
    
    /*for(i=0;i<n;i++){
        occupied[i]=0;
    }*/
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(blockSize[j]>=processSize[i]){
                allocation[i]=j;
                /*occupied[j]=1;*/
                
                blockSize[j]=blockSize[j]-processSize[i];
                total=total+blockSize[j];
                
                break;
            }
        }
    }
    
    printf("\n Process No \t Process Size \t Block no. \n");
    for(i=0;i<m;i++){
        printf("%i \t\t\t",i+1);
        printf("%i \t\t\t",processSize[i]);
        if(allocation[i]!=-1){
            printf("%i",allocation[i]+1);
        }
        else{
            printf("Not allocated");
        }
        printf("\n");
    }
    
    return total;
}

int main(){
    int m;
    int n;
    int blockSize[]={500};
    int processSize[]={400,60};
    m=sizeof(blockSize)/sizeof(blockSize[0]);
    n=sizeof(processSize)/sizeof(processSize[0]);
    
    int s=firstFit(processSize,n,blockSize,m);
    printf("\n %d total internal fragmentation",s);
    
    return 0;
}





