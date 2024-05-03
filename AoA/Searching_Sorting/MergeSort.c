#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int a[], int low, int mid, int high)
{
    int b[10000];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {

        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= high)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    if (j > high)
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void merge_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid;
        mid = (low + high) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main()
{
    clock_t start, end;
    double time1;
    start = clock();
    int a[10000], low, high, n;
    printf("Enter number of elements");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // printf("Enter value");
        // scanf("%d",&a[i]);
        a[i] = rand();
    }
    low = 0;
    high = n - 1;
    merge_sort(a, low, high);
    // for(int i=0;i<n;i++)
    // {
    // printf("%d\t",a[i]);
    // }
    end = clock();
    time1 = (double)(end - start);
    printf("\n time taken is %f", time1);

    return 0;
}