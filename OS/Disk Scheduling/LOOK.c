#include <stdio.h>

void main()
{
    int n, req[100], pos, temp;
    char dir ='u';
    int tot_movement;
    printf("Enter number of requests\n");
    scanf("%d",&n);
    printf("Enter the requests\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter position of head\n");
    scanf("%d",&pos);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(req[i]>req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
    if(dir=='u')
    {
        tot_movement = 2*req[n-1] - pos - req[0];
    }
    else if (dir == 'd')
    {
        // Calculate total track movement in the 'd' (down) direction
        tot_movement = pos - +req[n-1]-2*req[0];
    }
    printf("Total track movement = %d",tot_movement);
}
