#include <stdio.h>

#define N 4

int graph[N][N] = {
    {0,4,2,0},
    {4,0,0,5},
    {2,0,0,3},
    {0,5,3,0}
};

void initialize_pheromone(double pheromone[N][N])
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            pheromone[i][j] = 1.0;
        }
    }
}

int calculate_cost(int path[], int length)
{
    int cost = 0;
    int i;

    for(i=0;i<length-1;i++)
    {
        cost += graph[path[i]][path[i+1]];
    }

    return cost;
}

void evaporate_pheromone(double pheromone[N][N], double rho)
{
    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            pheromone[i][j] = (1-rho)*pheromone[i][j];
        }
    }
}

int main()
{
    double pheromone[N][N];

    initialize_pheromone(pheromone);

    printf("Initial pheromone values:\n");

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%.2f ", pheromone[i][j]);
        }
        printf("\n");
    }

    return 0;
}
