#include <stdio.h>
#include <stdlib.h>

typedef struct Bag{
    int id;
    int profit;
    int weight;
}Bag;
int comparator(const void* a, const void* b)
{
    Bag b1 = *(const Bag*)a;
    Bag b2 = *(const Bag*)b;
    if((b1.profit / b1.weight) > (b2.profit / b2.weight))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int knapsack(Bag bags[], int noOfBags, int maxWeight);
int dynamicKnapsack(Bag bags[], int noOfBags, int maxWeight);
int main()
{
    Bag bags[] = 
    {
        {0, 60, 4}, 
        {1, 100, 15}, 
        {2, 120, 30}
    };

    int W = 50;

    knapsack(bags, 3, W);
}

int knapsack(Bag bags[], int noOfBags, int maxWeight)
{
    double selected[noOfBags];
    for(int i = 0; i < noOfBags; i++){selected[i] = 0;}
    qsort(bags, noOfBags, sizeof(bags[0]), comparator);
    for(int i = 0; i < noOfBags; i++)
    {
        printf("%d, %d, %d\n", bags[i].id, bags[i].weight, bags[i].profit);
    }
    int w = 0;
    int i = 0;
    double profit = 0;
    while(w + bags[i].weight <= maxWeight && i < noOfBags)
    {
        selected[bags[i].id] = 1.0;
        w += bags[i].weight;
        profit += bags[i].profit;
        i++;
    }
    int remainingWeight = maxWeight - w;
    if(i < noOfBags)
    {
        selected[bags[i].id] = (double)remainingWeight / (double)bags[i].weight;
        profit += (remainingWeight / bags[i].weight) * bags[i].profit;
    }
    printf("The selected items are: \n");
    for(int i = 0; i < noOfBags; i++)
    {
        printf("%d: %lf\n", i, selected[i]);
    }
    printf("The profit is: %lf\n", profit);
    return profit;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int dynamicKnapsack(Bag bags[], int noOfBags, int maxWeight)
{
    int knapsack[noOfBags + 1][maxWeight + 1];
    for(int i = 0; i <= noOfBags; i++){knapsack[i][0] = 0;}
    for(int i = 0; i <= maxWeight; i++){knapsack[0][i] = 0;}

    for(int i = 1; i <= noOfBags; i++ )
    {
        for(int w = 1; w <= maxWeight; w++)
        {
            if(bags[i - 1].weight <= w)
            {
                knapsack[i][w] = max(
                    knapsack[i - 1][w],
                    knapsack[i - 1][w - bags[i - 1].weight] + bags[i - 1].profit
                );
            }
            else
            {
                knapsack[i][w] = knapsack[i - 1][w];
            }
        }
    }
    int w = maxWeight;
    for(int i = noOfBags; i > 0; i--)
    {
        if(knapsack[i][w] != knapsack[i - 1][w])
        {
            w = w - bags[i - 1].weight;
            printf("%d: 1\n", i);
        }
        else
        {
            printf("%d: 0\n", i);
        }
    }
    return knapsack[noOfBags][maxWeight];
}