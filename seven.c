#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void heapify(int a[], int n, int i)
{
    int temp;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}
void heapsort(int a[], int n)
{
    int temp;
    for (int i = n / 2 - 1; i >= 0; i--) // builds the max heap
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
int main()
{
    clock_t starttime, endtime;
    double clk;
    int a[100];
    int i, n;
    printf("enter value of n\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    printf("the no are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%ld\n", a[i]);
    }
    starttime = clock();
    heapsort(a, n);
    endtime = clock();
    printf("sorted:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("total time taken is %f\n", clk);
}