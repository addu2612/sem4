#include <stdio.h>
#include <limits.h>

// Function to find minimum number of coins required to make a given amount
int minCoins(int coins[], int n, int amount) {
    // Create an array to store minimum number of coins required for each amount
    int dp[amount + 1];
    
    // Initialize values in dp array to infinity
    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX;
    
    // Base case: 0 coins needed for amount 0
    dp[0] = 0;
    
    // Compute minimum number of coins required for each amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
        }
    }
    
    return dp[amount];
}

// Main function
int main() {
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    
    int n;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);
    
    int coins[n];
    printf("Enter the coin denominations: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    
    int result = minCoins(coins, n, amount);
    printf("Minimum number of coins required: %d\n", result);
    
    return 0;
}
