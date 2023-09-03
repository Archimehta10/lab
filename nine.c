
#include <stdio.h>
#include <time.h>
double clk;
clock_t starttime, endtime;

int min(int a, int b) // checks for minimum value
{
    if (a < b)
        return a;
    else
        return b;
}

void floyd(int n, int W[10][10], int D[10][10])
{
    int i, j, k;                // W stores the values of the original matrix
                                // D is the shortest path Matrix
    for (i = 0; i < n; i++)     // inserts the values to the shortest path matrix
        for (j = 0; j < n; j++) // from a weighted matrix given by user
            D[i][j] = W[i][j];
    for (k = 0; k < n; k++) // performs the main step of the floyd algorithm where
    {                       // it compares and changes to minimum values
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]); // comparison
            }
        }
    }
}

void main()
{
    int i, j, n, D[10][10], W[10][10];
    printf("Enter no.of vertices: \n");
    scanf("%d", &n);
    printf("Enter the cost matrix: \n");
    for (i = 0; i < n; i++) // inserting matrix
        for (j = 0; j < n; j++)
            scanf("%d", &W[i][j]);
    starttime = clock();
    floyd(n, W, D);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("All pair shortest path matrix is\n");
    for (i = 0; i < n; i++) // printing final matrix
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", D[i][j]);
        }
        printf("\n");
    }
    printf("\nThe run time is %f\n", clk);
}