#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int a[], int mid, int low, int high)
{
    int b[100];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] > a[j])
        {
            b[k] = a[j];
            j++;
        }   
        else
        {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    if (j > high)
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    else
    {
        while (j <= high)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

int mergesort(int a[], int low, int high)
{
    if (high > low)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

int main()
{
    int a[100];
    clock_t starttime, endtime;
    double clk;
    int i, n;
    printf("Enter n value: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    printf("The numbers are : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    starttime = clock();
    mergesort(a, 0, n - 1);
    endtime = clock();
    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("the run time is : %lf\n", clk);
}