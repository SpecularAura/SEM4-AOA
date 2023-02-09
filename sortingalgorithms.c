void bubblesort(int arr[], int n)
{
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selectionsort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int max=0;
        for(int j = 1; j < n - i; j++)
        {
            if(arr[j] > arr[max])
            {
                max = j;
            }
        }
        int temp = arr[n - i - 1];
        arr[n - i - 1] = arr[max];
        arr[max] = temp;
    }
}
void insertionsort(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		
		while(key < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
		
	}
}