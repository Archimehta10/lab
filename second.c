#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a[50][50], i, j, n, reach[50], pos[50], count = 0;
void readmat()
{
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                a[i][j] = rand() % 2;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int adjacent(int i)
{
    for (j = pos[i] + 1; j <= n; j++)
    {
        if (a[i][j] == 1)
        {
            pos[i] = j;
            return j;
        }
    }
    pos[i] = n + 1;
    return 0;
}

int checkreach(int u)
{
    for (i = 1; i <= count; i++)
    {
        if (reach[i] == u)
        {
            return 1;
        }
    }
    return 0;
}

void dfs(int v)
{
    int u;
    reach[++count] = v;
    u = adjacent(v);
    while (u)
    {
        if (checkreach(u) == 0)
        {
            printf("%d->%d\n", v, u);
            dfs(u);
        }
        u = adjacent(v);
    }
}

int main()
{
    int v;
    clock_t starttime, endtime;
    double clk;
    printf("Enter the lands to be surveryed:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        pos[i] = 0;
    }
    readmat();
    printf("Starting land number:");
    scanf("%d", &v);
    starttime = clock();
    dfs(v);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("The runtime is:%f", clk);
    return 0;
}
