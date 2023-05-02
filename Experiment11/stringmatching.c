#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

#define d 256

typedef struct PI
{
    int pi[MAX];
    int n;
}PI;

void KMP(const char* pattern, const char* string);
PI ComputePrefixFunction(const char* pattern);
int main()
{
    char pattern[] = "AUM";
    char string[] = "MUAMUAAUMMUAAUM";
    KMP(pattern, string);
}

void KMP(const char* pattern, const char* string)
{
    int pt_length = strlen(pattern);
    int str_length = strlen(string);
    PI p = ComputePrefixFunction(pattern);
    int q = -1;
    for(int i = 0; i < str_length; i++)
    {
        while(q >= 0 && pattern[q + 1] != string[i])
        {
            q = p.pi[q];
        }
        if(pattern[q + 1] == string[i])
        {
            q = q + 1;
        }
        if(q == pt_length - 1)
        {
            printf("Pattern Matched at: %d", i - pt_length + 1);
            q = p.pi[q];
        }
    }
}

PI ComputePrefixFunction(const char* pattern)
{
    int pt_length = strlen(pattern);
    PI p;
    p.pi[0] = -1;
    int k = -1;
    for(int i = 1; i < pt_length; i++)
    {
        while(k >= 0 && pattern[k + 1] != pattern[i])
        {
            k = p.pi[k];
        }
        if(p.pi[k + 1] == p.pi[i])
        {
            k = k + 1;
        }
        p.pi[i] = k;
    }
    printf("Prefix Function Successful: %s", pattern);
    return p;
}