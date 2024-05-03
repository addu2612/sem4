#include <stdio.h>

int main(){
    int n;
    int req[100];
    int pos,temp;
    int total_movement=0;
    printf("Enter number of requests\n");
    scanf("%d",&n);
    printf("Enter the requests\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }

    printf("Enter position of head:\n");
    scanf("%d",&pos);

    total_movement+=abs(pos-req[0]); 

     for(int i=1;i<n;i++)
    {
        total_movement+=abs(req[i]-req[i-1]); 
    }
    printf("Total track movement = %d",total_movement);

}