#include <stdio.h>

void main()
{
    int n, req[100], pos, total, temp;
    char dir;
    int tot_movement = 0; // Initialize total movement

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }
    printf("Enter position of head: ");
    scanf("%d", &pos);
    printf("Total number of cylinders: ");
    scanf("%d", &total);
    printf("Enter direction (u for up, d for down): ");
    scanf(" %c", &dir); // Notice the space before %c to consume any whitespace characters

    // Sort the requests
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (req[i] > req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Calculate total track movement based on direction
    if (dir == 'u')
    {
        // If direction is up
        tot_movement= (total-pos)+(total-req[0]);
    }
    else if (dir == 'd')
    {
        // If direction is down
        tot_movement = pos + req[n - 1];
    }
    else
    {
        printf("Invalid direction.\n");
        return; 
    }

    printf("Total track movement = %d\n", tot_movement);
}
