#include <stdio.h>
#include <string.h>
void lcs(const char* c1, const char* c2);

int main()
{
    lcs("CHIMPANZEE", "HUMAN");
}

void lcs(const char* c1, const char* c2)
{
    int c1_len = strlen(c1);
    int c2_len = strlen(c2);

    int c[c1_len + 1][c2_len + 1];
    char b[c1_len + 1][c2_len + 1];

    for(int i = 0; i <= c1_len; i++)
    {
        c[i][0] = 0;
    }
    for(int i = 0; i <= c2_len; i++)
    {
        c[0][i] = 0;
    }

    for(int i = 1; i <= c1_len; i++)
    {
        for(int j = 1; j <= c2_len; j++)
        {
            if(c1[i - 1] == c2[j - 1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D';
            }
            else
            {
                if (c[i-1][j] >= c[i][j-1])
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = 'U';
                }
                else
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 'L';
                }
            }
        }
    }

    printf("%d ", c[c1_len][c2_len]);

    int i = c1_len, j = c2_len;
    int k = c[c1_len][c2_len];
    while(k > 0)
    {
        if(b[i][j] == 'D')
        {
            printf("%c", c1[i - 1]);
            i--;
            j--;
            k--;
        }
        else if(b[i][j] == 'L')
        {
            j--;
        }
        else
        {
            i--;
        }
    }
}