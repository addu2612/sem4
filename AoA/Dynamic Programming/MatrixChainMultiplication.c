#include<stdio.h>
#include<limits.h>

// Function to find minimum number of multiplications needed to multiply matrices
int matrixChainOrder(int p[], int n) {
    // Create a 2D array to store minimum number of multiplications
    int m[n][n];
    
    // Initialize all values in the array to zero
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    
    // l is the chain length.
    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                // q = cost/scalar multiplications
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

// Main function
int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the dimensions of matrices: ");
    for(int i = 0; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Minimum number of multiplications is: %d\n", matrixChainOrder(arr, n + 1));
    return 0;
}
