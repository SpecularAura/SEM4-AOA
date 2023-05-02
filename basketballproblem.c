#include <stdio.h>
#include <math.h>
int main()
{
    int vac_nums[] = {180, 172, 178, 185, 190, 195, 192, 200, 210, 190};
    int n = sizeof(vac_nums) / sizeof(int);
    double avg = 0, stdDev = 0;
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += vac_nums[i];
    }
    avg = sum / n;
    sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += pow(vac_nums[i] - avg, 2);
    }
    double var = sum / n;
    stdDev = sqrt(var);
    for(int i = 0; i < n; i++)
    {
        int val = vac_nums[i];
        if(val <= stdDev + avg && val >= avg - stdDev)
        {
            printf("%d: %d\n", i, val);
        }
    }
}