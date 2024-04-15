#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int bt[100], at[100], pro[100], ct[100], tat[100], wt[100], n, ttat = 0, twt = 0, v[100], gant[100], cgant[100];
    float attat, awt;
    printf("Enter number of processes ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of process %d ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        pro[i] = i + 1;
        v[i] = 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
                swap(&pro[j], &pro[j + 1]);
            }
        }
    }
    int executed = 0;
    int t = 0; // time
    int index = 0;
    while (executed != n)
    {
        int isExecuted = 0;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= t && v[i] == 0)
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
        if (isExecuted == 0)
        {
            t++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        ttat += tat[i];
        wt[i] = tat[i] - bt[i];
        twt += wt[i];
    }
    awt = (float)twt / n;
    attat = (float)ttat / n;
    printf("Process\tAT\tBT\tCT\tTAT\tWT");
    for (int i = 0; i < n; i++)
        printf("\n\t%d\t%d\t%d\t%d\t%d\t%d\n", pro[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    printf("\nAvg TAT=%f\nAvg WT=%f", attat, awt);
    printf("\nGantt Chart \n0");
    for (int i = 0; i < n; i++)
    {
        printf(" [P%d|%d] ", gant[i], cgant[i]);
    }
}
