#include <stdio.h>
#include <limits.h>

#define MAX 100

int m[MAX][MAX];   // Stores minimum multiplication cost
int s[MAX][MAX];   // Stores the index where optimal split occurs

// Function to print the optimal parenthesization
void printOptimalParenthesis(int i, int j)
{
    if (i == j)
    {
        printf("%c", 'A' + i-1);
        return;
    }

    printf("(");
    printOptimalParenthesis(i, s[i][j]);
    printOptimalParenthesis(s[i][j] + 1, j);
    printf(")");
}

// Function to calculate minimum multiplication cost
void matrixChainOrder(int p[], int n)
{
    int i, j, k, L, q;
    // Cost is zero for one matrix
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
    // L = Chain length
    for (L = 2; L <= n; L++)
    {
        for (i = 1; i <= n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[MAX];

    printf("Enter the dimensions array (%d values):\n", n + 1);

    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    matrixChainOrder(p, n);

    printf("\nMinimum number of scalar multiplications = %d\n", m[1][n]);

    printf("Optimal Parenthesization = ");

    printOptimalParenthesis(1, n);

    printf("\n");

    return 0;
}