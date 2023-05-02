#include <stdio.h>
#include <math.h>
#define N 4
int x[N];

void NQueens(int k, int n);
int Place(int k, int i);

int main()
{
    NQueens(0, N);
}

void NQueens(int k, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(Place(k, i) == 1)
        {
            x[k] = i;
            if(k == n - 1)
            {
                for(int j = 0; j < n; j++)
                {
                    for(int k = 0; k < n; k++)
                    {
                        printf("%c ", (x[j] == k ? 'x' : 'o'));
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else
            {
                NQueens(k + 1, n);
            }
        }
    }
}
int Place(int k, int i)
{
    for(int j = 0; j < k; j++)
    {
        if(
            x[j] == i ||
            abs(x[j] - i) == abs(k - j)
        )
        {
            return 0;
        }
    }
    return 1;
}