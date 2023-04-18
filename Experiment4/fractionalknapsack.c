#include <stdio.h>
#include <stdlib.h>
typedef struct BAG {
    int id;
    int profit;
    int weight;
} Bag;

int knapsack(Bag bags[],int noOfBags, int W);
int compare(const void* x, const void* y)
{
    Bag* b1 = (Bag*) x;
    Bag* b2 = (Bag*) y;
    return (b2->profit - b1->profit);
}

int main() 
{
    Bag bags[] = 
    {
        {0, 60, 10}, 
        {1, 100, 15}, 
        {2, 120, 30}
    };

    int W = 50;

    knapsack(bags, 3, W);
}

int knapsack(Bag bags[],int noOfBags, int W)
{
    double knapSack[noOfBags];
    double profit = 0.0;
    for(int i = 0; i < noOfBags; i++)
    {
        knapSack[i] = 0;
    }
    qsort(bags, noOfBags, sizeof(Bag), compare);
    for(int i = 0; i < noOfBags; i++)
    {
        printf("%d ", bags[i].profit);
    }
    printf("\n");
    int i = 0, w = 0;
    while(i < noOfBags && w + bags[i+1].weight <= W)
    {
        knapSack[bags[i].id] = 1.0;
        w += bags[i].weight;
        profit += bags[i].profit;
        i++;
        printf("%d\n", w);
    }
    if( i != noOfBags)
    {
        knapSack[bags[i].id] = ((double) (W - w)) / ((double) bags[i].weight);
        profit += knapSack[bags[i].id] * bags[i].profit;
    }

    for(int i = 0; i < noOfBags; i++)
    {
        printf("%d: %lf ", i, knapSack[i]);
    }
    printf("\n%lf", profit);
    return profit;
}