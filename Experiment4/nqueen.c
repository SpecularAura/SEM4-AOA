#include <stdio.h>
#include <math.h>
#define N 4
int x[N];
int Place(int k, int i)
{
    for (int j = 0; j < k - 1; j++)
    {
        if(x[j] == i
            || abs(x[j] - i) == abs(j - k))
        {
            return 0;
        }
    }
    return 1;
}
void NQueens(int k, int n)
{
    for(int i = 0; i < n; i++)
    {
        if (Place(k, i) == 1)
        {
            x[k] = 1;
            if(k == n - 1)
            {
                for(int z = 0; z < n; z++)
                {
                    printf("%d ", x[z]);
                }
                printf("\n");
            }
            else
            {
                NQueens(k+1, n);
            }
        }
    }
}

int main()
{
    NQueens(0, N);
}