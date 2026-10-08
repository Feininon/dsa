#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_best(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i;
}

void generate_worst(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = n - 1 - i;
}

void generate_avg(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 100000;
}

double bubble_sort(int arr[], int n) {
    clock_t start = clock();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    srand((unsigned int)time(NULL));

    int sizes[] = {1000, 5000, 10000, 20000, 50000};
    double best[5], worst[5], avg[5];

    for (int k = 0; k < 5; k++) {
        int n = sizes[k];
        int *arr = (int *)malloc(n * sizeof(int));

        generate_best(arr, n);
        best[k] = bubble_sort(arr, n);

        generate_worst(arr, n);
        worst[k] = bubble_sort(arr, n);

        generate_avg(arr, n);
        avg[k] = bubble_sort(arr, n);

        free(arr);
    }

    printf("Size, %d, %d, %d, %d, %d\n", sizes[0], sizes[1], sizes[2], sizes[3], sizes[4]);
    printf("Best, %.6f, %.6f, %.6f, %.6f, %.6f\n", best[0], best[1], best[2], best[3], best[4]);
    printf("Worst, %.6f, %.6f, %.6f, %.6f, %.6f\n", worst[0], worst[1], worst[2], worst[3], worst[4]);
    printf("Avg, %.6f, %.6f, %.6f, %.6f, %.6f\n", avg[0], avg[1], avg[2], avg[3], avg[4]);

    return 0;
}