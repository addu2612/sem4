#include <stdio.h>
#include <stdlib.h>

struct process{
    int arrival, burst, completion, turnaround, waiting, completed, r_burst, inQueue;
};
struct process pq[10];

int curqueue[10], front =-1, rear =-1;

void enqueue(int process){
    if(front == -1){
        front++;
        rear++;
        curqueue[rear] = process;
    }
    else if((rear+1)%10 == front){
        printf("\nQueue Full\n");
    }
    else{
        rear = (rear+1)%10;
        curqueue[rear] = process;
    }
}

int dequeue(){
    int val = -1;
    if(front == -1){
        printf("\nQueue Empty\n");
    }
    else if(front == rear){
        val = curqueue[front];
        front = -1;
        rear = -1;
    }
    else{
        val = curqueue[front];
        front = (front+1)%10;
    }
    return val;
}


void main(){
    int total, clock=0, completedProcess=0, timeQuantum;
    float avgTAT=0, avgWT=0;
    printf("This is Round Robin process sheduling\n");
    printf("Enter number of processes : ");
    scanf("%d",&total);
    printf("Enter Time Quantum : ");
    scanf("%d",&timeQuantum);
    
    for (int i=0; i<total; i++){
        printf("Enter process arrival time, burst time : ");
        scanf("%d%d",&pq[i].arrival,&pq[i].burst);
        pq[i].completed = 0;
        pq[i].r_burst = pq[i].burst;
        pq[i].inQueue = 0;
    }
    for(int i=1; i<total; i++){
        int j = i-1;
        struct process key = pq[i];
        while(j >= 0 && key.arrival < pq[j].arrival){
            struct process temp = pq[j];
            pq[j+1] = pq[j];
            pq[j] = temp;
            j--;
        }
        pq[j+1] = key;
    }

    clock = pq[0].arrival;
    enqueue(0);
    pq[0].inQueue = 1;
    while(completedProcess < total){
        int process = dequeue();
        if(pq[process].r_burst > timeQuantum){
            pq[process].r_burst -= timeQuantum ;
            clock += timeQuantum;
        }
        else{
            clock += pq[process].r_burst;
            pq[process].r_burst = 0;
        }
        for(int i=0; i<total; i++){
            if(pq[i].inQueue!=1 && pq[i].arrival<=clock && pq[i].completed!=1){
                enqueue(i);
                pq[i].inQueue = 1;
            }
        }
        if(pq[process].r_burst == 0){
            pq[process].completion = clock;
            pq[process].turnaround = pq[process].completion - pq[process].arrival;
            pq[process].waiting = pq[process].turnaround - pq[process].burst;
            completedProcess += 1;
            pq[process].completed = 1;
        }
        else{
            enqueue(process);
            pq[process].inQueue = 1;
        }
    }
    
    
    printf("Id\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0; i<total; i++){
        avgTAT += pq[i].turnaround;
        avgWT += pq[i].waiting;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, pq[i].arrival, pq[i].burst, pq[i].completion, pq[i].turnaround, pq[i].waiting);
    }
    avgTAT /= total; 
    avgWT /= total; 
    printf("Avg TAT : %.2f, Avg WT : %.2f", avgTAT, avgWT);
}