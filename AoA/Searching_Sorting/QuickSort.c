#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
int main()
{
    srand(time(NULL));
    int arr[1000], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    // printf("Unsorted array:\n");
    // for (int i = 0; i < 1000; i++) {
    // printf("%d ", arr[i]);
    // }
    // printf("\n");
    clock_t start = clock(); // Start time measurement
    quick_sort(arr, 0, n - 1);
    clock_t end = clock(); // End time measurement
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    // printf("Sorted array:\n");
    // for (int i = 0; i < 1000; i++) {
    // printf("%d ", arr[i]);
    // }
    printf("\n");
    printf("Time taken: %f seconds\n", elapsed_time);
    return 0;
}