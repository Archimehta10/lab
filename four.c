#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void insertion(long a[], int n)
{
    int i, j;
    int temp = 0;
    // unsorted list of elements
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    printf("Sorted:");
    for (i = 0; i < n; i++)
    {
        printf("%ld", a[i]);
    }
}

int main()
{
    long a[10];
    int i, n;
    clock_t starttime, endtime;
    double clk;

    printf("Enter n value: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = 9000000000 + (rand() % 9999999) + 1;
    }
    printf("the phone numbers are: ");
    for (i = 0; i < n; i++)
    {
        printf("%ld\n", a[i]);
    }
    starttime = clock();
    insertion(a, n);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The runtime is : %f", clk);
}
