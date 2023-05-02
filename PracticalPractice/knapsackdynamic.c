#include <stdio.h>
typedef struct Bag
{
    int cost, weight;
} Bag;

void Knapsack(const Bag bags[], int noOfBags, int maxWeight);

int main()
{
    Bag bags[] = 
    {
        {60, 10}, 
        {100, 15}, 
        {120, 30}
    };

    int W = 50;

    Knapsack(bags, 3, W);
}

void Knapsack(const Bag bags[], int noOfBags, int maxWeight)
{
    int knapsack[noOfBags + 1][maxWeight + 1];
    for(int i = 0; i <= noOfBags; i++)
    {
        knapsack[i][0] = 0;
    }
    for(int i = 0; i <= maxWeight; i++)
    {
        knapsack[0][i] = 0;
    }
    for (int i = 1; i <= noOfBags; i++)
    {
        Bag curBag = bags[i - 1];
        for (int w = 1; w <= maxWeight; w++)
        {
            if(curBag.weight <= w)
            {
                if(curBag.cost + knapsack[i - 1][w - curBag.weight] > knapsack[i - 1][w])
                {
                    knapsack[i][w] = curBag.cost + knapsack[i - 1][w - curBag.weight];
                }
                else 
                {
                    knapsack[i][w] = knapsack[i - 1][w];
                }
            }
            else
            {
                knapsack[i][w] = knapsack[i - 1][w];
            }
        }
    }
    printf("The maximum profit is: %d\n", knapsack[noOfBags][maxWeight]);
    int w = maxWeight;
    printf("The bags in the knapsack are: \n");
    for(int i = noOfBags; i > 0; i--)
    {
        if(knapsack[i][w] != knapsack[i - 1][w])
        {
            printf("%d: 1 ", i);
            w = w - bags[i - 1].weight;
        }
        else
        {
            printf("%d: 0 ", i);
        }
    }
}
