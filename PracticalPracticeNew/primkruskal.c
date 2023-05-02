#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF INT_MAX
#define MAX 30
typedef struct Edge
{
    int src;
    int dest;
    int wt;
} Edge;

typedef struct EdgeList
{
    Edge edges[MAX];
    int noOfEdges;
} EdgeList;

typedef struct Graph
{
    int G[MAX][MAX];
    int noOfVertices;
} Graph;

typedef struct UFArr
{
    int p[MAX];
    int n;
} UFArr;

int Find(UFArr *parent, int v)
{
    if (parent->p[v] < 0)
    {
        return v;
    }

    return Find(parent, parent->p[v]);
}

void Union(UFArr *parent, int v1, int v2)
{
    int p1 = Find(parent, v1);
    int p2 = Find(parent, v2);

    parent->p[p1] = p2;
}

int comparator(const void* a, const void* b)
{
    Edge e1 = *(const Edge*)a;
    Edge e2 = *(const Edge*)b;
    return e1.wt - e2.wt;
}
void PrimsAlgo(Graph graph);
void KruskalsAlgo(Graph graph);

int main()
{
    Graph G = {
        {{0, 1, 0, 0, 5},
         {1, 0, 2, 0, 6},
         {0, 2, 0, 7, 4},
         {0, 0, 7, 0, 8},
         {5, 6, 4, 8, 0}},
        5};

    KruskalsAlgo(G);
}

void PrimsAlgo(Graph graph)
{
    bool selected[graph.noOfVertices];
    for (int i = 0; i < graph.noOfVertices; i++)
    {
        selected[i] = false;
    }
    selected[0] = true;
    int cost = 0;
    for (int k = 0; k < graph.noOfVertices - 1; k++)
    {
        int min = INF;
        int x, y;
        for (int i = 0; i < graph.noOfVertices; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < graph.noOfVertices; j++)
                {
                    if (!selected[j] && graph.G[i][j])
                    {
                        if (graph.G[i][j] < min)
                        {
                            min = graph.G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cost += min;
        printf("%d - %d: %d\n", x, y, min);
        selected[y] = true;
    }
    printf("Minimum Cost: %d", cost);
}

void KruskalsAlgo(Graph graph)
{
    EdgeList elist;
    UFArr parent;
    for(int i = 0; i < graph.noOfVertices; i++)
    {
        parent.p[i] = -1;
    }
    elist.noOfEdges = 0;
    for(int i = 0; i < graph.noOfVertices; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(graph.G[i][j])
            {
                elist.edges[elist.noOfEdges] = (Edge){i, j, graph.G[i][j]};
                elist.noOfEdges++;
            }
        }
    }
    qsort(elist.edges, elist.noOfEdges, sizeof(elist.edges[0]), comparator);
    for(int i = 0; i < elist.noOfEdges; i++)
    {
        printf("%d -> %d: %d\n", elist.edges[i].src, elist.edges[i].dest, elist.edges[i].wt);
    }

    int cost = 0;
    int count = 0;
    for(int i = 0; count < graph.noOfVertices - 1; i++)
    {
        Edge curEdge = elist.edges[i];
        int p1 = Find(&parent, curEdge.src);
        int p2 = Find(&parent, curEdge.dest);
        if(p1 != p2)
        {
            Union(&parent, curEdge.src, curEdge.dest);
            cost += curEdge.wt;
            count++;
        }
    }
    printf("The minimum cost is: %d", cost);
}
