#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 30
#define INF INT_MAX

typedef struct UFArr {
    int P[MAX];
    int n;
}UFArr;

typedef struct Edge {
    int src;
    int dest;
    int wt;
}Edge;


typedef struct EdgeList {
    Edge edges[MAX];
    int noOfEdges;
}EdgeList;

typedef struct Graph {
    int G[MAX][MAX];
    int noOfVertices;
}Graph;

int Find(UFArr* parent, int v)
{
    if(parent->P[v] < 0)
    {
        return v;
    }

    parent->P[v] = Find(parent, parent->P[v]);
    return parent->P[v];
}

void Union(UFArr* parent, int v1, int v2)
{
    int p1 = Find(parent, v1);
    int p2 = Find(parent, v2);
    parent->P[p1] = p2;
}

comparator(const void* a, const void* b)
{
    Edge e1 = *(const Edge*)a;
    Edge e2 = *(const Edge*)b;

    return e1.wt - e2.wt;
}

void KruskalAlgo(Graph G)
{
    UFArr parent;
    parent.n = 0;
    for(int i = 0; i < G.noOfVertices; i++)
    {
        parent.P[i] = -1;
        parent.n += 1;
    }
    EdgeList elist;
    elist.noOfEdges = 0;
    for(int i = 0; i < G.noOfVertices; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(G.G[i][j] != 0)
            {
                elist.edges[elist.noOfEdges] = (Edge){i, j, G.G[i][j]};
                elist.noOfEdges += 1;
            }
        }
    }
    qsort(elist.edges, elist.noOfEdges, sizeof(elist.edges[0]), comparator);
    int count = 0, ans = 0;
    for(int i = 0; count < G.noOfVertices - 1; i++)
    {
        Edge curEdge = elist.edges[i];
        int p1 = Find(&parent, curEdge.src);
        int p2 = Find(&parent, curEdge.dest);
        if(p1 != p2)
        {
            Union(&parent, p1, p2);
            count++;
            ans += curEdge.wt;
        }
    }
    printf("The answer is: %d\n", ans);
}

void PrimsAlgo(Graph graph)
{
    bool selected[graph.noOfVertices];
    for(int i = 0; i < graph.noOfVertices; i++)
    {
        selected[i] = false;
    }
    int G[graph.noOfVertices][graph.noOfVertices];
    for(int i = 0; i < graph.noOfVertices; i++)
    {
        for(int j = 0; j < graph.noOfVertices; j++)
        {
            G[i][j] = graph.G[i][j];
        }
    }
    int cost = 0;
    selected[0] = true;
    for(int k = 0; k < graph.noOfVertices - 1; k++)
    {
        int min = INF;
        int x,y;
        for(int i = 0; i < graph.noOfVertices; i++)
        {
            if(selected[i])
            {
                for(int j = 0; j < graph.noOfVertices; j++)
                {
                    if(!selected[j] && G[i][j] != 0)
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
        cost += min;
        selected[y] = true;
        printf("%d - %d: %d\n", x, y, min);
    }
    printf("Answer is: %d", cost);
}

int main()
{
    Graph G = {
        {{0, 1, 0, 0, 5},
         {1, 0, 2, 0, 6},
         {0, 2, 0, 7, 4},
         {0, 0, 7, 0, 8},
         {5, 6, 4, 8, 0}},
        5};

    KruskalAlgo(G);
    PrimsAlgo(G);
}