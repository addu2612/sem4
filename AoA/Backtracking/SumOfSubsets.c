#include <stdio.h>

void subset_sum(int weights[], int n, int target_sum, int current_index, int current_sum, int* solution, int solution_size) {
    if (current_sum == target_sum) {
        // Print the solution
        for (int i = 0; i < solution_size; i++) {
            printf("%d ", solution[i]);
        }
        printf("\n");
        return;
    }

    // If current_sum exceeds target or we've processed all weights, backtrack
    if (current_sum > target_sum || current_index >= n) {
        return;
    }

    // Include the current weight in the solution
    solution[solution_size] = weights[current_index];
    subset_sum(weights, n, target_sum, current_index + 1, current_sum + weights[current_index], solution, solution_size + 1);

    // Exclude the current weight (backtracking)
    subset_sum(weights, n, target_sum, current_index + 1, current_sum, solution, solution_size);
}

int main() {
    int n, target_sum;

    printf("Enter the number of weights: ");
    scanf("%d", &n);

    int weights[n];
    printf("Enter the weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &target_sum);

    int solution[n]; // Array to store the solution subset
    subset_sum(weights, n, target_sum, 0, 0, solution, 0);

    return 0;
}
