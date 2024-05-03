#include<stdio.h>
#include<time.h> // Include time.h for timing

void SelectionSort(int a[], int n) {
    int i, j, k;
    int temp = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = k = i; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int a[1000];
    int n;

    printf("Enter number of components: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &a[i]);
    }

    clock_t start = clock(); // Record start time
    SelectionSort(a, n);
    clock_t end = clock(); // Record end time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time taken in seconds

    printf("\nTime taken by SelectionSort: %lf seconds\n", time_taken);

    return 0;
}
