#include <stdio.h>
#include <string.h>

void LCS(const char* str1, const char* str2);

int main()
{
    LCS("12345678", "87456321");
}

void LCS(const char* str1, const char* str2)
{
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    int table[str1_len + 1][str2_len + 1];
    char direction[str1_len][str2_len];

    for(int i = 0; i <= str1_len; i++)
    {
        table[i][0] = 0;
    }
    for(int i = 0; i <= str2_len; i++)
    {
        table[0][i] = 0;
    }

    for(int i = 1; i <= str1_len; i++)
    {
        for(int j = 1; j <= str2_len; j++)
        {
            if(str1[i - 1] == str2[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
                direction[i - 1][j - 1] = 'D';
            }
            else if(table[i - 1][j] > table[i][j - 1])
            {
                table[i][j] = table[i - 1][j];
                direction[i - 1][j - 1] = 'U';
            }
            else
            {
                table[i][j] = table[i][j - 1];
                direction[i - 1][j - 1] = 'L';
            }
        }
    }
    printf("Length of LCS is: %d", table[str1_len][str2_len]);
}