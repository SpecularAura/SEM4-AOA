#include <stdio.h>
void bubblesort(int arr[], int n);
int  main()
{
    int arr[100], n, i, j;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    printf("The sorted array is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void bubblesort(int arr[], int n)
{
    printf("Bubbles sort \n");
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}