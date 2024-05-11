#include<stdio.h>
#define n 7

int at[n], bt[n], priority[n];
int ct[n], tat[n], wt[n];
int pro[n];
int visited[n];
int original_bt[n];

int main() {
    for(int i = 0; i < n; i++) {
        printf("Enter AT, BT, and Priority for Process %d:", i+1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        original_bt[i] = bt[i];
        pro[i] = i+1;
    }

    // Priority Preemptive
    int time = 0, completed = 0, highest_priority = 9999;
    int current_proc = -1;
    printf("\n\nGantt Chart\n0");
    while(completed < n) {
        highest_priority = 9999;
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && priority[i] < highest_priority && bt[i] > 0) {
                highest_priority = priority[i];
                current_proc = i;
            }
        }
        if(current_proc == -1) {
            time++;
            printf(" Idle %d", time);
            continue;
        }

        bt[current_proc]--;
        time++;

        if(bt[current_proc] == 0) {
            completed++;
            ct[current_proc] = time;
            tat[current_proc] = ct[current_proc] - at[current_proc];
            wt[current_proc] = tat[current_proc] - original_bt[current_proc];
        }
        printf(" P%d %d", pro[current_proc], time);
    }

    // Calculate waiting time for processes which haven't completed yet
    //i dont think this for section below is needed 
    //try more examples
    for(int i = 0; i < n; i++) {
        if(ct[i] == 0) { // Process hasn't completed yet
            wt[i] = time - at[i] - original_bt[i]; // Waiting time = Current time - Arrival time - Original burst time
        }
    }

    printf("\n\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pro[i], at[i], original_bt[i], priority[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
