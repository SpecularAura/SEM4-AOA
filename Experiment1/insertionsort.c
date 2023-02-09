#include <stdio.h>

void insertionsort(int arr[], int n);
int  main()
{
    int arr[100], n, i, j;
    printf("Enter the number of elements in the array: \n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionsort(arr, n);
    printf("The sorted array is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void insertionsort(int arr[], int n)
{
    printf("Insertion sort \n");
    int temp;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}