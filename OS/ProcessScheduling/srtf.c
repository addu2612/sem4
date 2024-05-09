#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter number of processes:");
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    int ttat = 0, twt = 0;
    float atat = 0, awt = 0;
    int pro[n];

    // Array to store the original burst times
    int original_bt[n];

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for process %d:", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        original_bt[i] = bt[i]; // Store original burst time
        pro[i] = i + 1;
    }

    // Implementing SRTF
    int time = 0, completed = 0, current_process = -1, shortest_burst = 9999;
    while (completed < n) {
        shortest_burst = 9999;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && bt[i] < shortest_burst && bt[i] > 0) {
                shortest_burst = bt[i];
                current_process = i;
            }
        }
        if (current_process == -1) {
            time++;
            continue;
        }

        bt[current_process]--;
        time++;

        if (bt[current_process] == 0) {
            completed++;
            ct[current_process] = time;
            tat[current_process] = ct[current_process] - at[current_process];
            wt[current_process] = tat[current_process] - original_bt[current_process]; // Corrected
            ttat += tat[current_process];
            twt += wt[current_process];
        }
    }

    // Printing output
    printf("\nOutput\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", pro[i], at[i], original_bt[i], ct[i], tat[i], wt[i]); // Print original burst time
    }
    awt = (float)twt / n;
    atat = (float)ttat / n;
    printf("\nAvg TAT = %f\nAvg WT = %f\n", atat, awt);


    return 0;
}
