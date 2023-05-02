#include <stdio.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n);
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
    selectionSort(arr, n);
    // mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - l;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++)
    {
        R[i] = arr[m + i + 1];
    }
    int i = 0, j = 0, k = l;
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

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int Partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for(int j = l; j < h; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[j], &arr[i]);
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
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(arr[j] < arr[j - 1])
        {
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}

void selectionSort(int arr[], int n)
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
        swap(&arr[i], &arr[minIdx]);
    }
}