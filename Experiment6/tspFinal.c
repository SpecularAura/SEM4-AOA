#include <stdio.h>
#define V 4
typedef struct Arr {
  int S[V];
  int size;
}Arr;
int tsp(int G[][V]);
int g(int i, Arr Set, int G[][V]);
Arr remove_vertex(Arr Set, int k);
Arr remove_start(Arr Set, int k, int l);

int main(){
  int G[][V] = { { 0, 10, 15, 20 },
                       { 5, 0, 35, 10 },
                       { 6, 13, 0, 12 },
                       { 8, 8, 9, 0 } };
                      
  printf("Minimum cost: %d\n",tsp(G));
}
int g(int i, Arr Set, int G[][V]){
  int cost = __INT_MAX__;
  for(int j = 0; j < Set.size; j++)
  {
    int newcost = G[i][Set.S[j]] + g(Set.S[j], remove_vertex(Set, Set.S[j]), G);
    if(newcost < cost)
    {
      cost = newcost;
    }
  }
  if(Set.size == 0)
  {
    cost = G[i][0];
  }
  return cost;
}

int tsp(int G[][V]){
  Arr Set;
  int cost = __INT_MAX__;
  Set.size = V;
  for(int i = 0; i < V; i++)
  {
    Set.S[i] = i;
  }
  for(int i = 1; i < V; i++)
  {
    int newcost = G[0][i] + g(i, remove_start(Set, 0, i), G);
    if(newcost < cost)
    {
      cost = newcost;
    }
  }
  
  return cost;
}

Arr remove_start(Arr Set, int k, int l){
  int j = 0;
  Arr newSet;
  newSet.size = V - 2;
  for(int i = 0; i < V; i++)
  {
    if(i == k || i == l)
    {
      continue;
    }
    newSet.S[j] = Set.S[i];
    j++;
  }
  return newSet;
}

Arr remove_vertex(Arr Set, int k){
  int j = 0;
  Arr newSet;
  for(int i = 0; i < Set.size; i++)
  {
    if(Set.S[i] == k)
    {
      continue;
    }
    newSet.S[j] = Set.S[i];
    j++;
  }
  newSet.size = Set.size - 1;
  return newSet;
}