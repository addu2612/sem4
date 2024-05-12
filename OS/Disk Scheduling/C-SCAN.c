#include <stdio.h>
#include<stdlib.h>

int main(){
    int n,total;
    int tot_mov=0;
    char dir;
    
    printf("Enter number of device requests:");
    scanf("%d",&n);
    int req[n];
    for(int i=0;i<n;i++){
        printf("Enter request {%d}",i+1);
        scanf("%d",&req[i]);
    }
    int head;
    printf("Enter position of head:");
    scanf("%d",&head);

    printf("Enter total no of cylinders:");
    scanf("%d",&total);

    printf("Enter direcction (u for up or d for down)");
    scanf(" %c",&dir);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(req[i]>req[j]){
                int temp=req[i];
                req[i]=req[j];
                req[j]=temp;
            }
        }
    }

    int min=999;
    int last_index=0;


    if (dir == 'u')
    {
        for(int i=0;i<n;i++){
            if(head>req[i] && min>abs(head-req[i])){
                min=abs(head-req[i]);
                last_index=i;
            }
            else{
                break;
            }
        }
        // If direction is up
        tot_mov=(total-head)+total+req[last_index];
        
    }
    
    else if (dir == 'd')
    {   int index_ahead=0;
        for(int i=0;i<n;i++){
            if (req[i] > head) {
                index_ahead = i;
                break; // Stop looping as soon as we find the first request ahead of the head
    }
            else{
                break;
            }
        }
        // If direction is down
        tot_mov = head+total+(total-req[index_ahead]);
    }
    else
    {
        printf("Invalid direction.\n");
    }

    

    printf("Total movement is : %d",tot_mov);



    return 0;
}