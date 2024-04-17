#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 50 // Increased size for input strings

void LCS(char str1[], char str2[], char b[][SIZE], int c[][SIZE]) {
    int m = strlen(str1);
    int n = strlen(str2);
    //initialize b and c
    for (int i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        c[0][j] = 0;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\'; 
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '|'; 
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '-'; 
            }
        }
    }
}

void print_LCS(char b[][SIZE], char str[], int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == '\\') {
        print_LCS(b, str, i - 1, j - 1);
        printf("%c", str[i - 1]);
    } else if (b[i][j] == '|') {
        print_LCS(b, str, i - 1, j);
    } else {
        print_LCS(b, str, i, j - 1);
    }
}

int main() {
    printf("Longest Common Subsequence\n");
    char str1[SIZE], str2[SIZE];
    printf("Enter text1: ");
    scanf("%s", str1);
    printf("Enter text2: ");
    scanf("%s", str2);

    char b[SIZE][SIZE];
    int c[SIZE][SIZE];
    LCS(str1, str2, b, c);

    // Print the DP table
    printf("\nDynamic Programming Table:\n");
    for (int i = 0; i <= strlen(str1); i++) {
        for (int j = 0; j <= strlen(str2); j++) {
            printf("%2d ", c[i][j]);
        }
        printf("\n");
    }

    printf("Longest Common Subsequence: ");
    print_LCS(b, str1, strlen(str1), strlen(str2));
    printf("\n");

    return 0;
}
