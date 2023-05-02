#include <stdio.h>

#define MAX 30

typedef struct Graph{
    int G[MAX][MAX];
    int noOfVertices;
}Graph;

void floydWarshall(Graph graph);

int main()
{

}

void floydWarshall(Graph graph)
{
    for(int k = 0; k < graph.noOfVertices; k++)
    {
        for(int i = 0; i < graph.noOfVertices; i++)
        {
            for(int j = 0; j < graph.noOfVertices; j++)
            {
                if(graph.G[i][j] && graph.G[i][k] + graph.G[k][j] < graph.G[i][j])
                {
                    graph.G[i][j] = graph.G[i][k] + graph.G[k][j];
                }
            }
        }
    }
}

