#include <stdio.h>

#define MAX_JOBS 100

void jobSequencing(int ids[], int deadlines[], int profits[], int n) {
    int result[MAX_JOBS];
    int slots[MAX_JOBS] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = deadlines[i] - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                result[j] = i;
                slots[j] = 1;
                break;
            }
        }
    }

    printf("Job Sequence: ");
    for (int i = 0; i < n; i++) {
        if (slots[i]) {
            printf("%d ", ids[result[i]]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    int ids[MAX_JOBS];
    int deadlines[MAX_JOBS];
    int profits[MAX_JOBS];

    printf("Enter the job details (id, deadline, profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &ids[i], &deadlines[i], &profits[i]);
    }

    jobSequencing(ids, deadlines, profits, n);

    return 0;
}