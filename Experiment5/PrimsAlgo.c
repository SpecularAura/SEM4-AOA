#include <stdio.h>
#include <stdbool.h>
#define INF 9999999
// number of vertices in graph
#define V 5

int G[V][V] = {
    {0, 0, 3, 0, 0},
    {0, 0, 10, 4, 0},
    {3, 10, 0, 2, 6},
    {0, 4, 2, 0, 1},
    {0, 0, 6, 1, 0}};

int main()
{
  int no_edge;
  int selected[V];
  memset(selected, false, sizeof(selected));
  no_edge = 0;
  selected[0] = true;
  int x, y;
  int cost = 0;
  while (no_edge < V - 1)
  {
    int min = INF;
    x = 0;
    y = 0;
    for (int i = 0; i < V; i++)
    {
      if (selected[i])
      {
        for (int j = 0; j < V; j++)
        {
          if (!selected[j] && G[i][j])
          {
            if (min > G[i][j])
            {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }

    cost = cost + G[x][y];
    printf("%d - %d: %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }
  printf("\nSpanning tree cost: %d", cost);
  return 0;
}