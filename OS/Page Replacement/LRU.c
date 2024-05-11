#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 100

bool doesPageExist(int page, int frames[], int noOfFrames) {
    for (int i = 0; i < noOfFrames; i++) {
        if (frames[i] == page) {
            return true; // Page exists
        }
    }
    return false; // Page doesn't exist
}

int findLastOccurrenceInRange(int pages[], int st, int end, int target) {
    for (int i = end; i >= st; i--) {
        if (target == pages[i]) {
            return i;
        }
    }
    return -1;
}

void performLRU(int noOfPg, int pages[], int noOfFrames) {
    int hitCount = 0;
    int frames[MAX_FRAMES] = {0};
    
    // Initializing frames with first page references
    for (int i = 0; i < noOfFrames; i++) {
        frames[i] = pages[i];
        printf("Page No %d --> Frame [", pages[i]);
        for (int j = 0; j < noOfFrames; j++) {
            printf("%d ", frames[j]);
        }
        printf("] => FAULT\n");
    }

    for (int i = noOfFrames; i < noOfPg; i++) {
        if (doesPageExist(pages[i], frames, noOfFrames)) {
            hitCount++;
            printf("Page No %d --> Frame [", pages[i]);
            for (int j = 0; j < noOfFrames; j++) {
                printf("%d ", frames[j]);
            }
            printf("] => HIT\n");
        } else {
            int leastRecently = findLastOccurrenceInRange(pages, 0, i - 1, frames[0]);
            int frameIdxToBeRemoved = 0;
            for (int k = 1; k < noOfFrames; k++) {
                int currentLRU = findLastOccurrenceInRange(pages, 0, i - 1, frames[k]);
                if (currentLRU < leastRecently) {
                    frameIdxToBeRemoved = k;
                    leastRecently = currentLRU;
                }
            }
            frames[frameIdxToBeRemoved] = pages[i];
            printf("Page No %d --> Frame [", pages[i]);
            for (int j = 0; j < noOfFrames; j++) {
                printf("%d ", frames[j]);
            }
            printf("] => FAULT\n");
        }
    }

    printf("Hit Ratio: %.2f%%\n", (float)hitCount / noOfPg * 100.0);
    printf("Fault Ratio: %.2f%%\n", (float)(noOfPg - hitCount) / noOfPg * 100.0);
    printf("Total Hits: %d\n", hitCount);
    printf("Total Faults: %d\n", noOfPg - hitCount);
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

    performLRU(noOfPg, pages, noOfFrames);

    return 0;
}
