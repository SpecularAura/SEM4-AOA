#include <stdio.h>
#include <stdlib.h>

#define INF INT_MAX
#define MAX 30

typedef struct Graph {
    int G[MAX][MAX];
    int n;
}Graph;

void floydWarshall(Graph G);

int main()
{
    Graph G = {
        {
            { 0, 5, INF, 10 },
            { INF, 0, 3, INF },
            { INF, INF, 0, 1 },
            { INF, INF, INF, 0 }
        }, // Adjacency Matrix
        4
    };
    floydWarshall(G);

}

void floydWarshall(Graph G)
{
    for(int k = 0; k < G.n; k++)
    {
        for(int i = 0; i < G.n; i++)
        {
            for(int j = 0; j < G.n; j++)
            {
                if(
                    G.G[i][j] > G.G[i][k] + G.G[k][j]
                    && G.G[i][k] != INF
                    && G.G[k][j] != INF
                )
                {
                    G.G[i][j] = G.G[i][k] + G.G[k][j];
                }
            }
        }
    }
    for(int i = 0; i < G.n; i++)
    {
        for(int j = 0; j < G.n; j++)
        {
            if (G.G[i][j] == INF)
                printf("INF ");
            else
                printf("%d   ", G.G[i][j]);
        }
        printf("\n");
    }
}