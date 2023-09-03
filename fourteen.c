
#include <stdio.h>
#include <stdlib.h>
int count = 0;
int x[10], w[10], sum, n;
int subset(int cs, int k, int r)
    
{
    x[k] = 1;
    if (cs == sum)
    {
        printf("Solution Number=%d\n", ++count);
        for (int i = 0; i < n; i++)
        {
            if (x[i] == 1)
                printf("%d\n", w[i]);
        }
    }
    else
    {
        for (int i = k + 1; i < n; i++)
        {
            if (cs + w[i] <= sum)
            {
                subset(cs + w[i], i, r - w[i]);
            }
        }
    }
    x[k] = 0;
}
int main()
{
    printf("Enter number of elements=");
    scanf("%d", &n);
    printf("Enter elements in ascending order=");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }
    printf("Enter sum required=");
    scanf("%d", &sum);
    subset(0, -1, sum);
    return 0;
}
