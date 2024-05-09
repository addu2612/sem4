#include <stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int n;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n];
    int ttat=0,twt=0;
    float atat=0,awt=0;
    int pro[n];

    for(int i=0;i<n;i++){
        printf("Enter AT and BT for process %d:",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        pro[i]=i+1;
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(at[j]>at[j+1]){
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&pro[j],&pro[j+1]);
            }
        }
    }

    int prevBT=0;

    //CT
    for(int i=0;i<n;i++){
        int MaxArrival=(prevBT >at[i])?prevBT: at[i];
        ct[i]=MaxArrival+bt[i];
        prevBT=ct[i];
    }
    printf("\nOutput\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");   

    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pro[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        ttat+=tat[i];
        twt+=wt[i];

    }
    awt = (float)twt / n;
    atat = (float)ttat / n;
    printf("\nAvg TAT = %f\nAvg WT = %f\n", atat, awt);

    printf("Gantt Chart \n 0");
    for(int i=0;i<n;i++){
        printf("|P %d| %d",pro[i],ct[i]);
    }

    return 0;
}