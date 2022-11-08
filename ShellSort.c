int shellSort(int n, int arr[])
{
    int noIterations = 0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                noIterations++;
                printStat(n, arr);
            }
            arr[j] = temp;
        }
    }
    printStat(n, arr);
    return noIterations;
}