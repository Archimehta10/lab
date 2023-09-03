#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bfs(int a[500][500], int n, int source)
{
    int s[500], q[500], t, v, f = 0, r = -1;
    for (int v = 0; v < n; v++)
    {
        s[v] = 0; // mark everything as unvisited
    }
    q[++r] = source; // push
    s[source] = 1;
    while (f <= r)
    {
        t = q[f++]; // pop
        for (v = 0; v < n; v++)
        {
            if ((a[t][v] == 1) && s[v] == 0)
            {
                q[++r] = v; // push
                printf("%d->%d\n", t, v);
                s[v] = 1;
            }
        }
    }
}

main()
{
    int i, j, a[500][500], n, s;
    double clk;
    clock_t starttime, endtime;
    printf("Enter the number of cities:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = rand() % 2;
        }
    }
    printf("The matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("Enter the souce city:");
    scanf("%d", &s);
    starttime = clock();
    bfs(a, n, s);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The run time is %f", clk);
}