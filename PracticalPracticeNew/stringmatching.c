#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256
#define d 256
typedef struct PI
{
    int pi[MAX];
    int n;
} PI;
PI ComputePrefixFuntion(const char *pattern);
void KMP(const char *pattern, const char *string);
void RabinKarp(const char *pattern, const char *string);
int main()
{
    RabinKarp("AAB","AAABAAAAB");
}

PI ComputePrefixFuntion(const char *pattern)
{
    int pt_length = strlen(pattern);
    PI p;
    p.pi[0] = -1;
    int k = -1;
    for (int i = 1; i < pt_length; i++)
    {
        while (k >= 0 && pattern[k + 1] != pattern[i])
        {
            k = p.pi[k];
        }
        if (pattern[k + 1] == pattern[i])
        {
            k = k + 1;
        }
        p.pi[i] = k;
    }
    return p;
}
void KMP(const char *pattern, const char *string)
{
    int pt_length = strlen(pattern);
    int str_length = strlen(string);
    PI p = ComputePrefixFuntion(pattern);
    int q = -1;
    for (int i = 0; i < str_length; i++)
    {
        while (q >= 0 && pattern[q + 1] != string[i])
        {
            q = p.pi[q];
        }
        if (pattern[q + 1] == string[i])
        {
            q = q + 1;
        }
        if (q == pt_length - 1)
        {
            printf("Pattern Matched at %d", i - pt_length + 1);
            q = p.pi[q];
        }
    }
}
void RabinKarp(const char *pattern, const char *string)
{
    int q = INT_MAX;
    int pt_length = strlen(pattern);
    int str_length = strlen(string);
    int pt_hash = 0;
    int str_hash = 0;
    int pow = 1;
    for(int k = 0; k < pt_length - 1; k++)
    {
        pow = (pow * d) % q;
    }
    for(int k = 0; k < pt_length; k++)
    {
        pt_hash = (d * pt_hash + pattern[k]) % q;
        str_hash = (d * str_hash + string[k]) % q;
    }
    for(int i = 0; i < str_length - pt_length + 1; i++)
    {
        if(pt_hash == str_hash)
        {
            int j;
            for(j = 0; j < pt_length; j++)
            {
                if(string[i + j] != pattern[j])
                {
                    break;
                }
            }
            if(j == pt_length)
            {
                printf("String matched at: %d\n", i);
            }
        }

        str_hash = (d * (str_hash - pow * string[i]) + string[i + pt_length]) % q; 
    }
}
