#include <stdio.h>
int in(int, int[], int);
int next(int, int, int[], int);
int max(int[], int);
void display(int[], int);

int main(){
    int nop, i, pages[30], frames;
    printf("Enter the number of pages : ");
    scanf("%d", &nop);
    printf("Enter the pages : \n");
    for (i = 0; i < nop; i++){
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames : ");
    scanf("%d", &frames);
    
    int memory[10] , next_use[20];
    int j, hits = 0;
    for (int i = 0; i < frames; i++) {
        memory[i] = -1;
        next_use[i] = nop;
    }
    
    for (int i = 0; i < nop; i++) {
        j = in(pages[i], memory, frames);
        if (j != -1) {
            display(memory,frames);
            hits++;
        } 
        else {
            j = max(next_use, frames);
            memory[j] = pages[i];
            display(memory, frames);
        }
        for (int k = 0; k < frames; k++) {
            next_use[k] = next(memory[k], i + 1, pages, nop);
        }
    }
    printf("Total Hits: %d\n", hits);
    printf("Hit ratio: %f\n", (double)hits / nop);
    return 0;
}

int next(int x, int k, int arr[], int n) {
    for (int i = k; i < n; i++) 
    {
        if (arr[i] == x)
        return i;
    }   
    return n;
}

int max(int arr[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[max])
        max = i;
    }
    return max;
}

int in(int x, int arr[], int n){
    for (int i = 0; i < n; i++){
        if (arr[i] == x)
        return i;
    }
    return -1;
}

void display(int arr[], int n){
    printf("[ ");
    for (int i = 0; i < n; i++){
        if (arr[i] != -1){
            printf("%d ", arr[i]);
        }
        else{
            printf("_ ");
        }
        
    }
    printf("]\n");
}


