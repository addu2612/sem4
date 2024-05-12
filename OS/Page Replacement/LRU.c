#include <stdio.h>

#define MAX_FRAMES 100

int doesPageExist(int page, int frames[], int noOfFrames) {
    for (int i = 0; i < noOfFrames; i++) {
        if (frames[i] == page) {
            return 1;
        }
    }
    return 0;
}

int findLastOccurrenceInRange(int pages[], int start, int end, int page) {
    for (int i = end; i >= start; i--) {
        if (pages[i] == page) {
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
        if (doesPageExist(pages[i], frames, noOfFrames)) {
            hitCount++;
            printf("Page No %d --> Frame [", pages[i]);
            for (int j = 0; j < noOfFrames; j++) {
                printf("%d ", frames[j]);
            }
            printf("] => HIT\n");
        } else {
            frames[i] = pages[i];
            printf("Page No %d --> Frame [", pages[i]);
            for (int j = 0; j < noOfFrames; j++) {
                printf("%d ", frames[j]);
            }
            printf("] => FAULT\n");
        }
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

    printf("Total Hits: %d\n", hitCount);
}

int main() {
    int noOfPg = 10;
    int pages[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};
    int noOfFrames = 3;

    printf("Page Reference String: ");
    for (int i = 0; i < noOfPg; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n");

    printf("Number of Frames: %d\n", noOfFrames);

    printf("LRU Page Replacement:\n");
    performLRU(noOfPg, pages, noOfFrames);

    return 0;
}
