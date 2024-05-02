#include <stdio.h>
#include <stdlib.h>

void add(int n, int A[][n], int B[][n], int C[][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int A[][n], int B[][n], int C[][n]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    
    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize], P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
    
    for(int i = 0; i < newSize; i++) {
        for(int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    
    // P1 = (A11 + A22)(B11 + B22)
    add(newSize, A11, A22, C11);
    add(newSize, B11, B22, C12);
    strassen(newSize, C11, C12, P1);
    
    // P2 = (A21 + A22)B11
    add(newSize, A21, A22, C11);
    strassen(newSize, C11, B11, P2);
    
    // P3 = A11(B12 - B22)
    subtract(newSize, B12, B22, C11);
    strassen(newSize, A11, C11, P3);
    
    // P4 = A22(B21 - B11)
    subtract(newSize, B21, B11, C11);
    strassen(newSize, A22, C11, P4);
    
    // P5 = (A11 + A12)B22
    add(newSize, A11, A12, C11);
    strassen(newSize, C11, B22, P5);
    
    // P6 = (A21 - A11)(B11 + B12)
    subtract(newSize, A21, A11, C11);
    add(newSize, B11, B12, C12);
    strassen(newSize, C11, C12, P6);
    
    // P7 = (A12 - A22)(B21 + B22)
    subtract(newSize, A12, A22, C11);
    add(newSize, B21, B22, C12);
    strassen(newSize, C11, C12, P7);
    
    // C11 = P1 + P4 - P5 + P7
    add(newSize, P1, P4, C11);
    subtract(newSize, C11, P5, C11);
    add(newSize, C11, P7, C11);
    
    // C12 = P3 + P5
    add(newSize, P3, P5, C12);
    
    // C21 = P2 + P4
    add(newSize, P2, P4, C21);
    
    // C22 = P1 - P2 + P3 + P6
    subtract(newSize, P1, P2, C22);
    add(newSize, C22, P3, C22);
    add(newSize, C22, P6, C22);
    
    for(int i = 0; i < newSize; i++) {
        for(int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the size of square matrices: ");
    scanf("%d", &n);
    
    int A[n][n], B[n][n], C[n][n];
    
    printf("Enter the elements of matrix A:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Enter the elements of matrix B:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    strassen(n, A, B, C);
    
    printf("Resultant matrix C:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
