#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LinearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a[1000];
    int n;
    int e;
    time_t start, end;
    float t;

    start = clock();

    printf("Enter number of components: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &a[i]);
    }

    printf("Element you want to search:");
    scanf("%d", &e);

    int searchIndex = LinearSearch(a, n, e);

    if (searchIndex == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element %d was found at position %d", e, searchIndex);
    }

    end = clock();

    t = (float)(end - start) / CLOCKS_PER_SEC;

    printf("\nTime taken: %f seconds\n", t);

    return 0;
}
