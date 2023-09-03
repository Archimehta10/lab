#include <stdio.h>
#include <time.h>
struct edge
{
    int u, v, cost;
};
typedef struct edge edge;
int find(int parent[], int v) // vertex ka parent finding
{
    if (parent[v] != v)
        v = parent[v];
    return v;
}
void union_ij(int i, int j, int parent[])
{
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}
void kruskal(int n, int m, edge e[])
{
    edge temp;
    int sum = 0;
    int parent[10];
    int t[10][2];
    for (int i = 0; i < m; i++) // length wise sorting (bubble sort)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (e[j].cost > e[j + 1].cost)
            {
                temp.u = e[j].u;
                temp.v = e[j].v;
                temp.cost = e[j].cost;
                e[j].u = e[j + 1].u;
                e[j].v = e[j + 1].v;
                e[j].cost = e[j + 1].cost;
                e[j + 1].u = temp.u;
                e[j + 1].v = temp.v;
                e[j + 1].cost = temp.cost;
            }
        }
    }
    for (int i = 0; i < n; i++)
        parent[i] = i; // parent of themselves
    int p = 0;
    int count = 0;
    int k = 0;
    while (count != n - 1)
    {
        int u = e[p].u;
        int v = e[p].v;
        int i = find(parent, u);
        int j = find(parent, v);
        if (i != j) // parent should not be the same
        {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum = +e[p].cost;       // total cost
            union_ij(i, j, parent); // joining u and v
        }
        p++;
    }
    if (count == n - 1)
    {
        printf("Spanning tree exists");
        for (int i = 0; i < n - 1; i++)
        {
            printf("%d %d\n", t[i][0], t[i][1]);
        }
        printf("Weight of spanning tree=%d", sum);
    }
    else
        printf("Spanning tree doesn't exist");
}
int main()
{
    edge e[20];
    clock_t starttime, endtime;
    int n, m;
    printf("Enter number of vertices=");
    scanf("%d", &n);
    printf("Enter number of edges=");
    scanf("%d", &m);
    printf("Enter the edgelist(u v cost)=\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].cost);
    }
    starttime = clock();
    kruskal(n, m, e);
    endtime = clock();
}
