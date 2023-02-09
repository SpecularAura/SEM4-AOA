#include <stdio.h>
#include <stdlib.h>
#include <sortingalgorithms.h>
#include <time.h>
int main()
{
    int arr[100], n;
    printf("Enter the number of elements");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    // bubblesort(arr, n);
    // selectionsort(arr,n);
	clock_t start = clock();
    insertionsort(arr,n);
	clock_t end   = clock();
    printf("After Sorting: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
	double time_taken = (double)(start - end) / CLOCKS_PER_SEC;
	printf("\n Time Taken to Sort: %lf", time);
}