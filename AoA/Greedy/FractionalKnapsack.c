#include <stdio.h>

int main() 
{
    int n;
    float profit = 0.0;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int wt[n], pr[n];
    float frac[n], pw[n];
    int W;
    
    printf("Enter the weights of the items:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }
    
    printf("Enter the profits of the items:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }
    
    printf("Enter the maximum weight allowed: ");
    scanf("%d", &W);
    
    for(int i = 0; i < n; i++)
    {
        pw[i] = (float)pr[i] / wt[i];
    }
    
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(pw[j] > pw[i])
            {
                float temp = pw[i];
                pw[i] = pw[j];
                pw[j] = temp;
                
                int temp2 = pr[i];
                pr[i] = pr[j];
                pr[j] = temp2;
                
                int temp3 = wt[i];
                wt[i] = wt[j];
                wt[j] = temp3;                 
            }
        }        
    }
    
    for(int i = 0; i < n; i++)
    {
        if(wt[i] <= W)
        {
            frac[i] = 1.0;
            printf("Selected %d\t", wt[i]);
            profit += pr[i];
            printf("Profit %.2f\n", profit);            
            W -= wt[i];
        }
        else if(wt[i] > W && W != 0)
        {
            printf("Selected partially %d\t", wt[i]);            
            frac[i] = (float)W / wt[i];
            profit += W * pw[i];
            printf("Profit %.2f\n", profit);             
            break;
        }
    }
    printf("\n");    
    for(int i = 0; i < n; i++)
    {
        printf("%d\t\t", wt[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%.2f\t", frac[i]);
    }
    printf("\n");
    printf("Max Profit: %.2f", profit);
    return 0;
}
