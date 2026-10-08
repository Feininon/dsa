#include <stdio.h>
#include <string.h>

#define MAX 100

void LenLCS(char X[], char Y[], int m, int n, int c[MAX][MAX], char b[MAX][MAX])
{
    int i, j;
    for (i = 0; i <= m; i++)
        c[i][0] = 0;

    for (j = 0; j <= n; j++)
        c[0][j] = 0;
        
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';       // Diagonal arrow
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = '^';        // Up arrow
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = '<';        // Left arrow
            }
        }
    }

    for (int j = 0; j < n; j++) printf("  %c", Y[j]);
    printf("\n");
    for (int i = 0; i <= m; i++) {
        if (i == 0) printf("  ");
        else printf("%c ", X[i - 1]);
        for (int j = 0; j <= n; j++) {
            printf("%3d", c[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for (int j = 0; j < n; j++) printf("%c", Y[j]);
    for (int i = 0; i <= m; i++) {
        if (i == 0) printf("  ");
        else printf("%c ", X[i - 1]);
        for (int j = 0; j <= n; j++) {
            printf("%c", b[i][j]);
        }
        printf("\n");
    }
}

void printLCS(char X[], int i, int j, char b[MAX][MAX])
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == '\\')
    {
        printLCS(X, i - 1, j - 1, b);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == '^')
    {
        printLCS(X, i - 1, j, b);
    }
    else
    {
        printLCS(X, i, j - 1, b);
    }
}

int main()
{
    char X[MAX], Y[MAX];
    int c[MAX][MAX];
    char b[MAX][MAX];
    int m, n;
    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);
    m = strlen(X);
    n = strlen(Y);
    LenLCS(X, Y, m, n, c, b);
    printf("\nLength of LCS = %d\n", c[m][n]);
    printf("Longest Common Subsequence = ");
    printLCS(X, m, n, b);
    printf("\n");
    return 0;
}