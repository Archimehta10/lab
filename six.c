#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quicksort(a, low, partitionIndex - 1);
        quicksort(a, partitionIndex + 1, high);
    }
}

int main()
{
    clock_t start, end;
    double clk;
    int i, j, n;
    int a[100];
    printf("Enter the value of n:\n");
    scanf("%d", &n);
    printf("Enter the array:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();
    printf("sorted: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("The runtime is %f", clk);
}