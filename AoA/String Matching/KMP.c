#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void Compute_Prefix(const char P[], int pi[]) {
    int m = strlen(P);
    pi[0] = -1;
    pi[1] = 0;
    int k = 0;

    for (int q = 2; q < m; q++) {
        while (k >= 0 && P[k] != P[q - 1]) {
            k = pi[k];
        }
        if (P[k] == P[q - 1]) {
            k = k + 1;
        }
        pi[q] = k;
    }
}

void KMP(const char T[], const char P[]) {
    int n = strlen(T);
    int m = strlen(P);
    int *pi = (int *)malloc(m * sizeof(int));
    Compute_Prefix(P, pi);
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) {
            q = pi[q];
        }
        if (P[q] == T[i]) {
            q = q + 1;
        }
        if (q == m) {
            printf("Pattern occurs with shift %d\n", i - m + 1);
            q = pi[q];
        }
    }
    free(pi);
}

int main() {
    char T[100], P[100];
    printf("*** Knuth-Morris-Pratt Algorithm ***\n");

    printf("Enter the Text:\n");
    scanf("%s", T);

    printf("Enter the Pattern:\n");
    scanf("%s", P);

    KMP(T, P);

    return 0;
}
