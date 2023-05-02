#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define d 256

void RabinKarp(const char* pattern, const char * string, int q);

int main()
{
    int q = INT_MAX;
    char pattern[] = "AUM";
    char string[] = "MUAMUAAUMMUAAUM";
    RabinKarp(pattern, string, q);
}

void RabinKarp(const char* pattern, const char * string, int q)
{
    int pt_length = strlen(pattern);
    int str_length = strlen(string);
    int pt_hash = 0;
    int str_hash = 0;
    int pow = 1;

    for(int i = 0; i < pt_length - 1; i++)
    {
        pow = (d * pow) % q;
    }

    for(int i = 0; i < pt_length; i++)
    {
        pt_hash = (d * pt_hash + pattern[i]) % q;
        str_hash = (d * str_hash + string[i]) % q;
    }

    int j;
    for(int i = 0; i <= str_length - pt_length; i++)
    {
        if(pt_hash == str_hash)
        {
            for(j = 0; j < pt_length; j++)
            {
                if(string[i + j] != pattern[j])
                {
                    break;
                }
            }
            if(j == pt_length)
            {
                printf("Patter Matched at: %d\n", i);
            }
        }

        str_hash = (d * (str_hash - pow * string[i]) + string[i + pt_length]) % q;
    }
}