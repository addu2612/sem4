#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int x[16];

bool Place(int k,int i){
    
    for (int j=1;j<=k-1;j++){
        if(x[j]==i || abs(x[j]-i)==abs(j-k)){
            return false;
        }
    }
    return true;
}

void NQueen(int k,int n){
    for(int i=1;i<=n;i++){
        if(Place(k,i)){
            x[k]=i;
            if(k==n){
                for (int j = 1; j <= n; j++) {
                    printf("%d ", x[j]);
                }
                printf("\n");
            }
            else{
                NQueen(k+1,n);
            }
        }
    }
}

int main(){
    NQueen(1,4);
}