#include <stdio.h>
void selectionsort(int arr[], int n);
int  main()
{
    int arr[100], n, i, j;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionsort(arr, n);
    printf("The sorted array is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void selectionsort(int arr[], int n)
{
    printf("Bubble sort \n");
    int temp;
    for(int i = 0; i < n; i++)
    {
        int min_idx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}