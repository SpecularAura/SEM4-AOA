#include <stdio.h>
#include <math.h>
#define N 9
int x[N];
void NQueens(int k, int n);
int Place(int k, int i);
int main()
{
    NQueens(0, N);
}

int Place(int k, int i)
{
    for (int j = 0; j < k; j++)
    {
        if (
            x[j] == i ||
            abs(j - k) == abs(x[j] - i)
        )
        {
            return 0;
        }
    }
    return 1;
}

void NQueens(int k, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (Place(k, i))
        {
            x[k] = i;
            if (k == n - 1)
            {
                for (int k = 0; k < n; k++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        printf("%c ", ((j == x[k]) ? 'x' : 'o'));
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