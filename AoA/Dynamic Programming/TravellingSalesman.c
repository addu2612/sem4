#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int tsp(int cities, int dist[MAX_CITIES][MAX_CITIES], int visited, int current)
{
    if (visited == (1 << cities) - 1)
        return dist[current][0];

    int min_cost = INT_MAX;

    for (int i = 0; i < cities; i++)
    {
        if (!(visited & (1 << i)))
        {
            int new_cost = dist[current][i] + tsp(cities, dist, visited | (1 << i), i);
            if (new_cost < min_cost)
                min_cost = new_cost;
        }
    }

    return min_cost;
}

int main()
{
    int cities;
    printf("Enter the number of cities: ");
    scanf("%d", &cities);

    int dist[MAX_CITIES][MAX_CITIES];
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }

    int min_cost = tsp(cities, dist, 1, 0);
    printf("Minimum cost: %d\n", min_cost);

    return 0;
}