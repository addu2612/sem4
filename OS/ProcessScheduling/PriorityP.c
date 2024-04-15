#include<stdio.h>

int maxPri(int pri[],int bt[],int at[],int t,int n)
{
    int max = -999,max_index = -1;
    for(int i=0;i<n;i++)
    {
        if(at[i]<=t && pri[i]>max && bt[i]>0)
        {
            max = pri[i];
            max_index = i;
        }
    }
    return max_index;
}

void main()
{
    int n=7,i,j,count=0,t=0,maxInd,temp,ind=0,ttat=0,twt=0;
    float awt,atat;
    int gant[100]={0},cgant[100];
    int pri[]={2,4,6,10,8,12,9};
    int pro[]={1,2,3,4,5,6,7};
    int at[]={0,1,2,3,4,5,6};
    int bt[]={4,2,3,5,1,4,6};
    int wt[n],tat[n],rt[n],ct[n],ogbt[n];
    for(i=0;i<n;i++)
    {
        ogbt[i]=bt[i];    
    }
    while(count!=n)
    {
        maxInd = maxPri(pri,bt,at,t,n);
        if(pro[maxInd]!=gant[ind-1])
        {
            gant[ind] = pro[maxInd];
            cgant[ind] = t;
            ind++;
        }
        else
        {
            cgant[ind] = t;
        }
        bt[maxInd]--;
        t++;
        if(bt[maxInd]==0)
        {
            count++;
            ct[maxInd] = t;
            tat[maxInd]=ct[maxInd]-at[maxInd];
            wt[maxInd]=tat[maxInd]-ogbt[maxInd];
            ttat+=tat[maxInd];
            twt+=wt[maxInd];            
        }
    }
    awt=(float)twt/n;
    atat=(float)ttat/n;
    printf("Process\tprio\tAT\tBT\tCT\tTAT\tWT");    
    for(i=0;i<n;i++)
    printf("\n\t%d\t%d\t\t%d\t%d\t%d\t%d\t%d\n",pro[i],pri[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    printf("\nAvg TAT=%f\nAvg WT=%f",atat,awt);
    printf("\nGant Chart \n");
    for(int i=0;i<n;i++)
    {
        printf(" [%d|P%d] ",cgant[i],gant[i]);
    }
    printf(" %d",ct[maxInd]);
}
