#include <stdio.h>
#define MAX 20
#define INF __INT_MAX__
typedef struct adjMat {
    int cost[MAX][MAX];
    int n;
}adjMat;
void floydWarshall(adjMat mat);
int main()
{
    adjMat mat = {
        .cost = {
            { 0, 5, INF, 10 },
            { INF, 0, 3, INF },
            { INF, INF, 0, 1 },
            { INF, INF, INF, 0 }
        },
        .n = 4 
    };
    floydWarshall(mat);
}

void floydWarshall(adjMat mat)
{
    for(int k = 0; k < mat.n; k++ )
    {
        for(int i = 0; i < mat.n; i++)
        {
            for(int j = 0; j < mat.n; j++)
            {
                if(mat.cost[i][j] > (mat.cost[i][k] + mat.cost[k][j])
                    && mat.cost[i][k] != INF
                    && mat.cost[k][j] != INF)
                {
                    mat.cost[i][j] = mat.cost[i][k] + mat.cost[k][j];
                }
            }
        }
    }

    for(int i = 0; i < mat.n; i++)
    {
        for(int j = 0; j < mat.n; j++)
        {
            if (mat.cost[i][j] == INF)
                printf("INF ");
            else
                printf("%d   ", mat.cost[i][j]);
        }
        printf("\n");
    }
}