#include <stdio.h>
#include <stdlib.h>
typedef struct JOB {
    int id;
    int deadline;
    int profit;
} Job;

void jobSequencing(Job jobs[], int n);
int compare(const void* x, const void* y)
{
    Job* j1 = (Job*) x;
    Job* j2 = (Job*) y;
    return (j2->profit - j1->profit);

}

int main()
{
    Job arr[] = { { 1, 2, 100 },
                  { 2, 1, 19 },
                  { 3, 2, 27 },
                  { 4, 1, 25 },
                  { 5, 3, 15 } };
    jobSequencing(arr, 5);
}

void jobSequencing(Job jobs[], int n)
{
    int sequence[n];
    int slot[n];

    qsort(jobs, n, sizeof(Job), compare);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", jobs[i].profit);
    }
    for(int i = 0; i < n; i++)
    {
        slot[i]  = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int j = (n < jobs[i].deadline ? n : jobs[i].deadline) - 1;
        while(j >= 0)
        {
            if(slot[j] == 0)
            {
                sequence[j] = jobs[i].id;
                slot[j] = 1;
                break;
            }
            j--;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(slot[i] == 1)
        {
            printf("%d ", sequence[i]);
        }
    }
}