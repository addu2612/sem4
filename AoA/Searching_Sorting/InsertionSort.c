#include <stdio.h>
#include <time.h>

void InsertionSort(int a[], int n) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = a[i];
        j = i - 1;

        while (j >=0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = x;
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
    InsertionSort(a, n);
    clock_t end = clock(); // Record end time

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate time taken in seconds

    return 0;
}