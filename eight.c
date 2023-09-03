#include <stdio.h>
#include <string.h>
#define MAX 500
int t[MAX];
void shifttable(char *p)
{
    int i, j, m;
    m = strlen(p);
    for (i = 0; i < MAX; i++) // default value of all the letters in general
        t[i] = m;
    for (j = 0; j < m - 1; j++) // for the letters in the pattern
        t[p[j]] = m - 1 - j;
}
int horspool(char src[], char p[])
{
    int i, m, k, n; // k stores the number of matched characters
    i = m - 1;      // index from where the pattern search should start
    m = strlen(p);
    n = strlen(src);
    while (i < n)
    {
        k = 0;
        while (k < m && p[m - 1 - k] == src[i - k]) // while the last letter matches
            k++;
        if (k == m) // if all the values match
            return i - m + 1;
        else
            i += t[src[i]]; // move to the next element
    }
    return -1;
}
int main()
{
    int pos;
    char src[100], p[100];
    printf("Enter the text:");
    gets(src);
    printf("Enter the pattern:");
    gets(p);
    shifttable(p);
    pos = horspool(src, p);
    if (pos >= 0)
        printf("The string was found at %d", pos + 1);
    else
        printf("The pattern was not found");
    return 0;
}
