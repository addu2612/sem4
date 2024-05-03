#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BinarySearch(int a[], int n, int key)
{

    int low = 0, high = n - 1, mid;

    while (low <= high)
    {

        mid = (low + high) / 2;

        if (a[mid] == key)
        {

            return mid;
        }

        if (a[mid] < key)
        {

            low = mid + 1;
        }

        else
        {

            high = mid - 1;
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

    int searchIndex = BinarySearch(a, n, e);

    if (searchIndex == -1)
    {

        printf("Element not found");
    }

    else
    {

        printf("Element %d was found at position %d", e, searchIndex);
    }

    end = clock();

    t = start - end;

    printf("%f", &t);

    return 0;
}
