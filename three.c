#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binsearch(int a[], int first, int last, int key)
{
    int mid = (first + last) / 2;
    if (first <= last)
    {
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            return binsearch(a, mid + 1, last, key);
        else
            return binsearch(a, first, mid - 1, key);
    }
    else
        return -1;
}

int main()
{
    clock_t starttime, endtime;
    double clk;
    int a[1000], id, res, i, j, temp, n;
    printf("Enter the no. of products: ");
    scanf("%d", &n);
    printf("Unsorted array elements\n:");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    // sorting
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    // print sorted
    printf("Sorted elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    printf("Enter id to be searched:\n");
    scanf("%d", &id);
    starttime = clock();
    res = binsearch(a, 0, n, id);
    if (res)
    {
        printf("Found at %d\n", res);
    }
    else
    {
        printf("not found");
    }
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The runtime is :%f\n", clk);
}