#include <stdio.h>
#include <stdlib.h>

typedef struct Job
{
    int id;
    int deadline;
    int profit;
}Job;

int comparator(const void* a, const void* b)
{
    Job j1 = *(const Job*)a;
    Job j2 = *(const Job*)b;

    return j2.profit - j1.profit;
}

int sequeuncing(Job jobs[], int noOfJobs, int noOfSlots);

int main()
{
    Job arr[] = { { 1, 2, 100 },
                  { 2, 1, 19 },
                  { 3, 2, 27 },
                  { 4, 1, 25 },
                  { 5, 3, 15 } };
    sequeuncing(arr, 5, 4);
}

int sequeuncing(Job jobs[], int noOfJobs, int noOfSlots)
{
    int slots[noOfSlots];
    int profit = 0;
    for(int i = 0; i < noOfSlots; i++){slots[i] = -1;}
    qsort(jobs, noOfJobs, sizeof(jobs[0]), comparator);
    for(int i = 0; i < noOfJobs; i++)
    {
        printf("%d, %d, %d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    for(int i = 0; i < noOfJobs; i++)
    {
        Job curJob = jobs[i];
        int j = (noOfSlots < curJob.deadline ? noOfSlots : curJob.deadline) - 1;
        while(j >= 0) 
        {
            if(slots[j] == -1)
            {
                slots[j] = curJob.id;
                profit += curJob.profit;
                break;
            }
            j--;
        }
    }
    printf("The sequence is: \n");
    for(int i = 0; i < noOfSlots; i++)
    {
        printf("%d ", slots[i]);
    }
    return profit;
}