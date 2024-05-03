#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, pos, tot_movement = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[100];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter position of head: ");
    scanf("%d", &pos);

    // Initialize an array to keep track of visited requests
    int visited[100];

    // Loop until all requests are visited
    for (int i = 0; i < n; i++) {
        int min_diff = 9999; // Initialize minimum difference to a large value
        int next_index = -1; // Initialize index of the next request to -1

        // Find the next request with the shortest seek time
        for (int j = 0; j < n; j++) {
            if (!visited[j]) { // If request is not visited
                int diff = abs(req[j] - pos); // Calculate seek time difference from the current position
                if (diff < min_diff) { // If seek time difference is smaller than current minimum
                    min_diff = diff; // Update minimum difference
                    next_index = j; // Update index of the next request
                }
            }
        }

        // Mark the next request as visited
        visited[next_index] = 1;

        // Update total movement with seek time to the next request
        tot_movement += min_diff;

        // Move head to the next request
        pos = req[next_index];
    }

    printf("Total distance: %d\n", tot_movement);

    return 0;
}
