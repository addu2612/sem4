#include<stdio.h>

int main(){
    int i,j,k,n,m;
    n=5;  //number of processes
    m=3;  //number of resources
    int alloc[n][m];    //allocation matrix
    int max[n][m];      //max matrix
    int avail[m];       //available resources
    int need[n][m];     //need matrix

    printf("Enter the Allocation Matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter Element {%d ,%d}:",i+1,j+1);
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the Max Matrix\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter Element {%d ,%d}:",i+1,j+1);
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter the Available resources:\n");
    for(i=0;i < m;i++){
            printf("Enter Element %d:",i+1);
            scanf("%d",&avail[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    int f[n],ans[n],ind=0;
    //f[n] is an array that keeps track of whether a process has been marked as "finished" or not
    // ans[n] is an array that stores the sequence of processes that are found to be in the safe sequence
    // ind is an index variable indicating the current position in the ans array where the next process should be stored.

    for(i=0;i<n;i++){
        f[i]=0;
    }
    
    int y=0;
    for(k=0;k<5;k++){
        for(i=0;i<n;i++){
            if(f[i]==0){
                int flag=0;
                for(j=0;j<m;j++){
                    if(need[i][j]>avail[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[ind++]=i;
                    for(y=0;y<m;y++){
                        avail[y]+=alloc[i][y];
                        f[i]=1;
                    }
                }
            }
        }

    }
    int flag=1;
    for(i=0;i<n;i++){
        if(f[i]==0){
            flag=0;
            printf("The following system is not safe");
            break;
        }
    }

    if(flag==1){
        printf("Following is the SAFE Sequence\n");
        for (i = 0; i < n - 1; i++){
            printf(" P%d ->", ans[i]);
        }
        printf(" P%d", ans[n - 1]);

    }

    return 0;
}