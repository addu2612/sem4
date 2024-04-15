#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,req[100],pos,temp;
    int tot_movement=0;
    printf("Enter number of requests\n");
    scanf("%d",&n);
    printf("Enter the requests\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter position of head\n");
    scanf("%d",&pos);
    tot_movement += abs(pos - req[0]);
    for(int i=1;i<n;i++)
    {
        tot_movement += abs(req[i] - req[i-1]);
    }
    printf("Total track movement = %d",tot_movement);
}