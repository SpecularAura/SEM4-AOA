#include <stdio.h>
typedef struct BAG {
    int id;
    int profit;
    int weight;
} Bag;

int knapsack(Bag bags[],int noOfBags, int W);
int max(int a, int b) { return (a > b) ? a : b; }

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
    int knapSack[noOfBags + 1][W + 1];
    int elements[noOfBags];
    for(int i = 0; i <= noOfBags; i++)
    {
        elements[i] = 0;
    }
    for(int i = 0; i <= noOfBags; i++)
    {
        knapSack[i][0] = 0;
    }
    for(int w = 0; w <= W; w++)
    {
        knapSack[0][w] = 0;
    }
    for(int i = 1; i <= noOfBags; i++)
    {
        for(int w = 1; w <= W; w++)
        {
            if (bags[i - 1].weight <= w)
            {
                knapSack[i][w] = max(
                    knapSack[i - 1][w],
                    knapSack[i - 1][w - bags[i - 1].weight] + bags[i - 1].profit
                );
            }
            else
            {
                knapSack[i][w] = knapSack[i - 1][w];
            }
        }
    }
    printf("%d\n", knapSack[noOfBags][W]);
    int i = noOfBags, k = W;
    while(i > 0 && k > 0)
    {
        if (knapSack[i-1][k] != knapSack[i][k])
        {
            elements[bags[i - 1].id] = 1;
            k = k - bags[i - 1].weight;
        }
        else
        {
            i = i - 1;
        }
    }
    for(int i = 0; i < noOfBags; i++)
    {
        printf("%d: %d\n", bags[i].id, elements[i]);
    }
    return knapSack[noOfBags][W];
}