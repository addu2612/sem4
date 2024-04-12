#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int NaiveStringMatch(const char T[], const char P[]) {
    int n = strlen(T);
    int m = strlen(P);
    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
            if (T[i + j] != P[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i; 
        }
    }
    return -1; 
}


int main(){
    char T[100], P[100];
    int status;
    printf("*** Naive String Matching Algorithm ***\n");

    printf("Enter the String:\n");
    scanf("%s",T);

    printf("Enter the Pattern:\n");
    scanf("%s",P);

    status=NaiveStringMatch(T,P);
    if (status == -1)
        printf("\nNo match found");
    else
        printf("Match has been found on %d position.", status);

}