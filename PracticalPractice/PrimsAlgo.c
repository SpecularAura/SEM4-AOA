#include <stdio.h>
#include <stdbool.h>

#define INF __INT_MAX__
#define V 5

typedef struct Graph
{
    int G[V][V];
    int n;
} Graph;

Graph PrimsAlgo(Graph G);

int main()
{
    Graph G = {
        {{0, 0, 3, 0, 0},
         {0, 0, 10, 4, 0},
         {3, 10, 0, 2, 6},
         {0, 4, 2, 0, 1},
         {0, 0, 6, 1, 0}},
         5};
    Graph MCST = PrimsAlgo(G);
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(MCST.G[i][j] != 0)
            {
                printf("%d - %d: %d\n", i, j, MCST.G[i][j]);
            }
        }
    }
}

Graph PrimsAlgo(Graph graph)
{
    Graph MCST;
    MCST.n = 5;
    int G[V][V];
    bool isAdded[V];
    int cost = 0;
    for (int i = 0; i < V; i++)
    {
        isAdded[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            G[i][j] = graph.G[i][j];
            MCST.G[i][j] = 0;
        }
    }
    isAdded[0] = true;
    for (int k = 0; k < V - 1; k++)
    {
        int min = INF;
        int x, y;
        for (int i = 0; i < V; i++)
        {
            if (isAdded[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if(!isAdded[j] && G[i][j] != 0)
                    {
                        if(min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cost = cost + min;
        printf("%d - %d: %d\n", x, y, G[x][y]);
        isAdded[y] = true;
        MCST.G[x][y] = min;
        // MCST.G[y][x] = min;
    }
    return MCST;
}