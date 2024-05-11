#include <stdio.h>

int max(int a ,int b){
    return (a > b) ? a : b;
}

void knapSack(int maxweight, int wt[], int val[], int n){
    int dp[n+1][maxweight+1];
    int selected[n+1][maxweight+1];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=maxweight;w++){
            if(i==0 || w==0){
                dp[i][w]=0;
                selected[i][w]=0; // Initialize all items as not selected
            }
            else if(wt[i-1]<=w){
                int including_current = val[i-1] + dp[i-1][w-wt[i-1]];
                int excluding_current = dp[i-1][w];
                if (including_current > excluding_current) {
                    dp[i][w] = including_current;
                    selected[i][w] = 1; // Mark item as selected
                } else {
                    dp[i][w] = excluding_current;
                    selected[i][w] = 0; // Mark item as not selected
                }
            }
            else{
                dp[i][w]=dp[i-1][w];
                selected[i][w]=0; // Mark item as not selected
            }
        }
    }

    // Printing the DP table
    printf("DP Table:\n");
    for(int i=0;i<=n;i++){
        for(int w=0;w<=maxweight;w++){
            printf("%d\t",dp[i][w]);
        }
        printf("\n");
    }

    // Printing the selected sequence
    printf("\nSelected sequence:\n");
    int i = n, w = maxweight;
    while (i > 0 && w > 0) {
        if (selected[i][w]) {
            printf("Item %d (weight %d, value %d) is selected.\n", i, wt[i - 1], val[i - 1]);
            w -= wt[i - 1];
        }
        i--;
    }

    // Printing the maximum profit
    printf("Max profit: %d\n", dp[n][maxweight]);
}

int main(){
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int maxweight = 50;
    
    int n = sizeof(profit)/sizeof(profit[0]);
    knapSack(maxweight, weight, profit, n);
    return 0;
}
