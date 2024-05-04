#include<stdio.h>
#include <stdlib.h>

int main(){
    int n,max_weight;
    float gain=0.0;
    printf("Enter number of weights:");
    scanf("%d",&n);
    int weight[n],profit[n];
    float pw[n],frac[n];
    printf("Enter Profits:");
    for(int i=0;i<n;i++){
        printf("Enter profit %d:",i);
        scanf("%d",&profit[i]);
    }
    printf("Enter Weights:");
    for(int i=0;i<n;i++){
        printf("Enter weight %d:",i);
        scanf("%d",&weight[i]);
    }
    printf("Enter max weight of knapsack:");
    scanf("%d",&max_weight);


    for(int i=0;i<n;i++){
        pw[i]=(float) profit[i]/weight[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(pw[i]<pw[j]){
                float temp=pw[i];
                pw[i]=pw[j];
                pw[j]=temp;

                int temp2=profit[i];
                profit[i]=profit[j];
                profit[j]=temp2;

                int temp3=weight[i];
                weight[i]=weight[j];
                weight[j]=temp3;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(weight[i]<=max_weight){
            frac[i]=1.0;
            gain+=profit[i];
            max_weight-=weight[i];
        }
        else if(weight[i]>max_weight && max_weight!=0){
            frac[i]=(float)max_weight/weight[i];
            gain+=max_weight*pw[i];
            break;

        }
    }
    printf("\n");    
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", weight[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%.2f\t", frac[i]);
    }
    printf("\n");
    printf("Max Profit: %.2f", gain);
    return 0;
}