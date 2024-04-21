#include<stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void main()
{
    int bt[100],at[100],pro[100],ct[100],tat[100],wt[100],n,i,j,k,temp,temp1,temp2,ttat=0,twt=0;
    float attat,awt;
    printf("enter number of processes ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter arrival time and burst time of process %d ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        pro[i]=i+1;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(at[j]>at[j+1])
            {
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&pro[j],&pro[j+1]);
            }
        }
    }
    int prevBt=0;
    //ct
    for(i=0;i<n;i++)
    {
        ct[i]=prevBt+bt[i];
        prevBt=ct[i];
    }
    //tat wt
    for(i=0;i<n;i++)
    {
    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];
    }
    printf("Output\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT");
    for(i=0;i<n;i++)
    {
        ttat+=tat[i];
        twt+=wt[i];
    }
    awt=(float)twt/n;
    attat=(float)ttat/n;
    for(i=0;i<n;i++)
    printf("\n\t%d\t%d\t%d\t%d\t%d\t%d\n",pro[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("\nAvg TAT=%f\nAvg WT=%f",attat,awt);
    printf("\nGantt Chart \n0");
    for(i=0;i<n;i++)
    {
        printf("|P%d| %d|",pro[i],ct[i]);
    }
}
