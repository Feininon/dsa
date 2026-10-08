#include <stdio.h>

void sortAct(int S[], int F[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (F[i] > F[j])
            {
                temp = F[i];
                F[i] = F[j];
                F[j] = temp;
                temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
    }
}

void printMax(int S[], int F[], int n)
{
    sortAct(S, F, n);
    printf("Selected Activities:\n");
    int i = 0;
    printf("%c : Start = %d, Finish = %d\n",
           'A' + i, S[i], F[i]);
    for (int j = 1; j < n; j++)
    {
        if (S[j] >= F[i])
        {
            printf("%c : Start = %d, Finish = %d\n",
                   'A' + j, S[j], F[j]);

            i = j;
        }
    }
}

int main()
{
    int S[] = {1, 3, 0, 5, 8, 5};
    int F[] = {2, 4, 6, 7, 9, 9};
    int n = 6;
    printMax(S, F, n);
    return 0;
}