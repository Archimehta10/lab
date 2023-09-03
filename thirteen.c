// PROGRAM:

// backtracking
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[20];
int place(int k, int i)
{
    int j;
    for (j = 1; j < k; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }
    return 1;
}

void nqueens(int k, int n)
{
    int i, a;
    for (i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                for (a = 1; a <= n; a++)
                    printf("%d\t", x[a]);
                printf("\n");
                return;
            }
            else
                nqueens(k + 1, n);
        }
    }
}
void main()
{
    int n;
    printf("\nEnter the number of queens:");
    scanf("%d", &n);
    printf("\n The solution to N Queens problem is: \n");
    nqueens(1, n);
}