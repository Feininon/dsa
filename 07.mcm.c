#include <stdio.h>
#include <limits.h>


int matrixChain(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int min = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = matrixChain(p, i, k)
                 + matrixChain(p, k + 1, j)
                 + p[i - 1] * p[k] * p[j];
        if (cost < min)
            min = cost;
    }
    return min;
}

int main()
{
    int n;
    printf("Entre no. of mats");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter dimentions: ");
    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);
    printf("the optimal number of mul:%d", matrixChain(p, 1, n));

    return 0;
}