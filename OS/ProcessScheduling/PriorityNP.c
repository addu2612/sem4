#include<stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void main()
{
    int ct[100],tat[100],wt[100],n=7,i,j,temp,temp1,temp2,ttat=0,twt=0,ind=0,cgant[7];
    int gant[7];
    float attat,awt;
    int at[7]={0,1,3,4,5,6,10};
    int bt[7]={8,2,4,1,6,5,1};
    int pr[7]={3,4,4,5,2,6,1};
    int v[7]={0,0,0,0,0,0,0};
    int pro[7]={1,2,3,4,5,6,7};
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(pr[j]<pr[j+1])
            {
                swap(&pr[j],&pr[j+1]);                
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&pro[j],&pro[j+1]);
            }
        }
    }
    int executed = 0;
    int t = 0; //time
    int index = 0;
    while(executed!=n)
    {
        int isExecuted = 0;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=t && v[i]==0)
            {
                ct[i] = t + bt[i];
                t = ct[i];
                gant[index] = pro[i];
                cgant[index] = ct[i];
                v[i] = 1;
                executed++;
                isExecuted = 1;
                index++;
                break;
            }
        }
        if(isExecuted==0)
        {
            t++;
        }
    }
    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        ttat += tat[i];
        wt[i] = tat[i] - bt[i];
        twt += wt[i];
    }
    awt=(float)twt/n;
    attat=(float)ttat/n;
    printf("Process\tprio\tAT\tBT\tCT\tTAT\tWT");    
    for(i=0;i<n;i++)
    printf("\n\t%d\t%d\t\t%d\t%d\t%d\t%d\t%d\n",pro[i],pr[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("\nAvg TAT=%f\nAvg WT=%f",attat,awt);
    printf("\nGant Chart \n");
    for(int i=0;i<n;i++)
    {
        printf(" [P%d|%d] ",gant[i],cgant[i]);
    } 
}
