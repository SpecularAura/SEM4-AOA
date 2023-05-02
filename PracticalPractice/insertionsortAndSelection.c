#include <stdio.h>
void swap(int* a1, int* a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
void insertionSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
int Partition(int arr[], int l, int h);
void quickSort(int arr[], int l, int h);
int main()
{
    int n;
    printf("Enter the size of the array");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    // insertionSort(arr, n);
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(arr[j] < arr[j - 1] && j > 0)
        {
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionSortAgain(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(arr[j] < arr[j - 1] && j > 0)
        {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}

void selectionSortAgain(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int minIdx = i;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + ((r - l) / 2);
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(i = 0,j = l; i < n1; i++, j++)
    {
        L[i] = arr[j];
    }
    for(i = 0,j = m + 1; i < n2; i++, j++)
    {
        R[i] = arr[j];
    }

    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int Partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = (l - 1);
    for(int j = l; j < h; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void quickSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int pi = Partition(arr, l, h);
        mergeSort(arr, l, pi - 1);
        mergeSort(arr, pi + 1, h);
    }
}
