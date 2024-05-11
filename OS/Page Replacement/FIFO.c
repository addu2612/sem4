#include <stdio.h>

#define MAX_FRAMES 100

int doesPageExist(int page, int frames[], int noOfFrames) {
    for (int i = 0; i < noOfFrames; i++) {
        if (frames[i] == page) {
            return 1; // Page exists
        }
    }
    return 0; // Page doesn't exist
}

void performFCFS(int noOfPg, int pages[], int noOfFrames) {
    int isHit, hitCount = 0, faultCount = 0;
    int frames[MAX_FRAMES] = {-1};
    int faultIndex = 0;

    for (int i = 0; i < noOfPg; i++) {
        isHit = 0;
        for (int j = 0; j < noOfFrames; j++) {
            if (frames[j] == pages[i]) {
                isHit = 1;
                hitCount++;
                printf("Page No %d --> Frame [", pages[i]);
                for (int k = 0; k < noOfFrames; k++) {
                    printf("%d ", frames[k]);
                }
                printf("] => HIT\n");
                break;
            }
        }
        if (!isHit) {
            frames[faultIndex] = pages[i];
            printf("Page No %d --> Frame [", pages[i]);
            for (int k = 0; k < noOfFrames; k++) {
                printf("%d ", frames[k]);
            }
            printf("] => FAULT\n");
            faultIndex = (faultIndex + 1) % noOfFrames;
            faultCount++;
        }
    }

    printf("Hit Ratio: %.2f%%\n", (float)hitCount / noOfPg * 100.0);
    printf("Fault Ratio: %.2f%%\n", (float)faultCount / noOfPg * 100.0);
    printf("Total Hits: %d\n", hitCount);
    printf("Total Faults: %d\n", faultCount);
}

int main() {
    int noOfPg, noOfFrames;

    printf("Enter The Number Of Pages: ");
    scanf("%d", &noOfPg);

    printf("Enter The Number Of Frames: ");
    scanf("%d", &noOfFrames);

    int pages[noOfPg];

    printf("Enter The Pages: ");
    for (int i = 0; i < noOfPg; i++) {
        scanf("%d", &pages[i]);
    }

    performFCFS(noOfPg, pages, noOfFrames);

    return 0;
}
