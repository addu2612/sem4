#include <stdio.h>
#include <stdbool.h>

bool doesPageExist(int frame[], int nf, int page) {
    for (int i = 0; i < nf; i++) {
        if (frame[i] == page) {
            return true;
        }
    }
    return false;
}

int nextOccurrence(int pages[], int st, int end, int target) {
    for (int i = st; i <= end; i++) {
        if (pages[i] == target) {
            return i;
        }
    }
    return -1;
}

void Optimal(int pages[], int np, int nf) {
    int HitCount = 0, faultCount = 0;
    int frames[100] = {0};

    for (int i = 0; i < nf; i++) {
        if (doesPageExist(frames, nf, pages[i])) {
            HitCount++;
            printf("Page No %d --> Frame [", pages[i]);
            for (int j = 0; j < nf; j++) {
                printf("%d ", frames[j]);
            }
            printf("] => HIT\n");
        } else {
            frames[i] = pages[i];
            printf("Page No %d --> Frame [", pages[i]);
            for (int j = 0; j < nf; j++) {
                printf("%d ", frames[j]);
            }
            printf("] => FAULT\n");
            faultCount++;
        }
    }

    for (int i = nf; i < np; i++) {
        if (doesPageExist(frames, nf, pages[i])) {
            HitCount++;
            printf("Page No %d --> Frame [", pages[i]);
            for (int j = 0; j < nf; j++) {
                printf("%d ", frames[j]);
            }
            printf("] => HIT\n");
        } else {
            int mostOptimal = -1;
            int farthest = -1;
            for (int j = 0; j < nf; j++) {
                int occurrence = nextOccurrence(pages, i, np - 1, frames[j]);
                if (occurrence == -1) {
                    mostOptimal = j;
                    break;
                } else {
                    if (occurrence > farthest) {
                        farthest = occurrence;
                        mostOptimal = j;
                    }
                }
            }
            frames[mostOptimal] = pages[i];
            printf("Page No %d --> Frame [", pages[i]);
            for (int j = 0; j < nf; j++) {
                printf("%d ", frames[j]);
            }
            printf("] => FAULT\n");
            faultCount++;
        }
    }

    printf("Hit Ratio: %.2f%%\n", (float)HitCount / np * 100.0);
    printf("Fault Ratio: %.2f%%\n", (float)faultCount / np * 100.0);
    printf("Total Hits: %d\n", HitCount);
    printf("Total Faults: %d\n", faultCount);
}

int main() {
    int nf, np;
    printf("Enter The Number Of Pages: ");
    scanf("%d", &np);

    printf("Enter The Number Of Frames: ");
    scanf("%d", &nf);

    int pages[np];
    printf("Enter The Pages: ");
    for (int i = 0; i < np; i++) {
        scanf("%d", &pages[i]);
    }
    Optimal(pages, np, nf);
    return 0;
}
