#include <stdio.h>
#define SIZE 5
int A[SIZE];

void MaxMin(int A[], int i, int j, int *max, int *min) {
    int max1, min1, max2, min2, mid;
    if (i == j) {
        *max = *min = A[i];
    } else if (i == j - 1) {
        if (A[i] < A[j]) {
            *min = A[i];
            *max = A[j];
        } else {
            *min = A[j];
            *max = A[i];
        }
    } else {
        mid = (i + j) / 2;
        MaxMin(A, i, mid, &max1, &min1);
        MaxMin(A, mid + 1, j, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}


int main() {
    int max, min;
    printf("Enter %d numbers for the array:\n", SIZE);
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &A[i]);
    }
    MaxMin(A, 0, SIZE - 1, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
