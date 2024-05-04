#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void RK(const char T[], const char P[], int d, int q) {
    int n = strlen(T);
    int m = strlen(P);
    //int h = d ^ (m - 1) % q;
    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    int p = 0, t = 0;
    int ts = 0; // Variable to keep track of ts

    for (int i = 0; i < m; i++) {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    for (int s = 0; s <= n - m; s++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (T[s + j] != P[j])
                    break;
            }
            if (j == m) {
                printf("Pattern occurs with shift %d\n", s);
            }
        }
        if (s < n - m) {
            t = (d * (t - T[s] * h) + T[s + m]) % q;
            if (t < 0) // Ensure t is positive
                t = t + q;
        }
    }
}

int main() {
    char T[100], P[100];
    int d = 256; // A prime number
    int q = 101; // Another prime number

    printf("*** Rabin Karp Algorithm ***\n");

    printf("Enter the Text:\n");
    scanf("%s", T);

    printf("Enter the Pattern:\n");
    scanf("%s", P);

    RK(T, P, d, q);

    return 0;
}
