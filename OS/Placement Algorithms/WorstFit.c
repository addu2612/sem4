#include <stdio.h>
#include <stdlib.h>

int process_sizes[10];
int mem_sizes[10];
int visited[10];
int mem_loc[10];
int temp;

int main(){
int n_mem;
printf("Enter number of memory partitions:\n");
scanf("%d", &n_mem);

for (int i = 0; i < n_mem; i++)
{
    printf("Enter size:");
    scanf("%d", &mem_sizes[i]);
}

int n_proc;
printf("Enter number of processes:\n");
scanf("%d", &n_proc);

for (int i = 0; i < n_proc; i++)
{
    printf("Enter size:");
    scanf("%d", &process_sizes[i]);
}

for(int i=0;i<n_mem;i++){
    visited[i]=0;
}

for(int i=0;i<n_mem-1;i++){
    for(int j=i+1;j<n_mem;j++){
        if(mem_sizes[i]<mem_sizes[j]){
            temp=mem_sizes[i];
            mem_sizes[i]=mem_sizes[j];
            mem_sizes[j]=temp;
        }
    }
}

int index=0;
for(int i=0;i<n_proc;i++){
    if(process_sizes[i]<=mem_sizes[index]){
        mem_loc[i]=index;
        index++;
    }
    else{
        mem_loc[i]=-1;
    }
}

for(int i=0;i<n_proc;i++){
    if(mem_loc[i]!=-1){
        printf("Process size = %d goes in location %d\n",process_sizes[i],mem_sizes[mem_loc[i]]);
    }
    else{
        printf("%d not allocated memory\n",process_sizes[i]);
    }
}

return 0;
}