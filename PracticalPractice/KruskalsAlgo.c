#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 30

typedef struct Graph
{
    int G[MAX][MAX];
    int n;
} Graph;

typedef struct Edge
{
    int src, dest, wt;
} Edge;

typedef struct EdgeList
{
    Edge edges[MAX];
    int n;
} EdgeList;

typedef struct UFArr
{
    int P[MAX];
    int n;
} UFArr;

void Union(UFArr *parent, int v1, int v2);
int Find(UFArr *parent, int v);

Graph KruskalsAlgo(Graph G);

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

int comparator(const void *p, const void *q)
{
    const Edge *pt_e1 = (const Edge *)p;
    const Edge *pt_e2 = (const Edge *)q;

    Edge e1 = *(pt_e1);
    Edge e2 = *(pt_e2);

    return e1.wt - e2.wt;
}

void Union(UFArr *parent, int v1, int v2)
{
    int p1 = Find(parent, v1);
    int p2 = Find(parent, v2);

    int weight1 = -parent->P[p1];
    int weight2 = -parent->P[p2];
    if (weight1 < weight2)
    {
        parent->P[p1] = p2;
        parent->P[p2] = -(weight2 + weight1);
    }
    else
    {
        parent->P[p2] = p1;
        parent->P[p1] = -(weight2 + weight1);
    }

    // parent->P[p1] = p2;
    for (int i = 0; i < parent->n; i++)
    {
        printf("%d, ", parent->P[i]);
    }
    printf("\n");
}

int Find(UFArr *parent, int v)
{
    if (parent->P[v] < 0)
    {
        return v;
    }
    parent->P[v] = Find(parent, parent->P[v]);
    return parent->P[v];
    // return Find(parent, parent->P[v]);
}

Graph KruskalsAlgo(Graph G)
{
    EdgeList elist;
    UFArr parent;
    parent.n = G.n;
    for (int i = 0; i < parent.n; i++)
    {
        parent.P[i] = -1;
    }

    elist.n = 0;
    for (int i = 0; i < G.n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (G.G[i][j] != 0)
            {
                printf("src: %d, dest: %d, weight: %d\n", i, j, G.G[i][j]);
                elist.edges[elist.n].src = i;
                elist.edges[elist.n].dest = j;
                elist.edges[elist.n].wt = G.G[i][j];
                elist.n += 1;
            }
        }
    }
    printf("\n");
    qsort(elist.edges, elist.n, sizeof(elist.edges[0]),comparator);

    for (int i = 0; i < elist.n; i++)
    {
        printf("src: %d, dest: %d, weight: %d\n", elist.edges[i].src, elist.edges[i].dest, elist.edges[i].wt);
    }

    int count = 0, ans = 0;
    for (int i = 0; count < (G.n - 1); i++)
    {
        Edge curEdge = elist.edges[i];
        int p1 = Find(&parent, curEdge.src);
        int p2 = Find(&parent, curEdge.dest);

        if (p1 != p2)
        {
            printf("Union is called: %d, %d\n", p1, p2);
            Union(&parent, curEdge.src, curEdge.dest);
            count++;
            ans += curEdge.wt;
        }
    }
    printf("The Anwer is: %d", ans);
    return G;
}