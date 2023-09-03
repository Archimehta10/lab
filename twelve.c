#include <stdio.h>
#include <time.h>

int choose(int n, int dist[], int selected[])
{                         // min is a random distance initialized
    int j = 1, min = 100; // i is iteration through vertices , j being the one with min dist
    for (int i = 1; i <= n; i++)
    {
        if ((dist[i] < min) && (!selected[i]))
        {
            min = dist[i];
            j = i;
        }
    }
    // returning the index of minimum distance vertex form source
    return j;
}

void spath(int n, int cost[n + 1][n + 1], int source, int dist[])
{
    int selected[n + 1], i;
    for (i = 1; i <= n; i++)
    {
        selected[i] = 0;
        dist[i] = cost[source][i];
    }
    // except source we have to find for all so loop starts from 2
    for (int num = 2; num <= n; num++)
    {
        int cur_source = choose(n, dist, selected); // find current source
        selected[cur_source] = 1;                   // mark the current source as visited
        for (int i = 1; i <= n; i++)
        {
            if (((dist[cur_source] + cost[cur_source][i]) < dist[i]) && (!selected[i]))
            {
                dist[i] = dist[cur_source] + cost[cur_source][i];
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    int cost[n + 1][n + 1];
    printf("Enter the cost of adjacency matrix : \n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    int source;
    printf("Enter the source vertices: ");
    scanf("%d", &source);

    int dist[n + 1];
    clock_t start = clock();
    spath(n, cost, source, dist);
    clock_t end = clock();
    double clk = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Shortest path from %d to all vertices is : \n", source);
    for (int i = 1; i <= n; i++)
    {
        printf("%d to %d = %d\n", source, i, dist[i]);
    }
    printf("The run time is %f\n", clk);

    return 0;
}