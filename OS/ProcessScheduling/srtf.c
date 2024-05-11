#include<stdio.h>
#define n 4

int at[n], bt[n];
int ct[n], tat[n], wt[n];
int pro[n];
int visited[n];
int original_bt[n];

int main() {
    for(int i = 0; i < n; i++) {
        printf("Enter AT and BT for Process %d:", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        original_bt[i] = bt[i];
        pro[i] = i+1;
    }

    //srtf
    int time = 0, completed = 0, current_proc = -1, shortest_burst = 9999;
    printf("\nGantt Chart\n0"); // Print the initial time 0
    while(completed < n) {
        shortest_burst = 9999;
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && shortest_burst > bt[i] && bt[i] > 0) {
                shortest_burst = bt[i];
                current_proc = i;
            }
        }
        if(current_proc == -1) {
            time++;
            printf(" Idle %d", time); // Print 'Idle' if no process is being executed
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

        printf(" P%d %d", pro[current_proc], time); // Print the process number and the time it finishes
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pro[i], at[i], original_bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
