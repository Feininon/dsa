#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

double benchmark_linear_search(int arr[], int n, int target) {
    clock_t start = clock();
    for (int i = 0; i < 1000; i++) {
        linear_search(arr, n, target);
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int sizes[] = {1000, 5000, 10000, 20000, 50000};
    double best[5], worst[5], avg[5];

    for (int k = 0; k < 5; k++) {
        int n = sizes[k];
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr[i] = i * 2;

        best[k]  = benchmark_linear_search(arr, n, arr[0]);     // First element
        worst[k] = benchmark_linear_search(arr, n, -1);         // Not present
        avg[k]   = benchmark_linear_search(arr, n, arr[n / 2]); // Middle element

        free(arr);
    }

    printf("=== LINEAR SEARCH ===\n");
    printf("Size, %d, %d, %d, %d, %d\n", sizes[0], sizes[1], sizes[2], sizes[3], sizes[4]);
    printf("Best, %.6f, %.6f, %.6f, %.6f, %.6f\n", best[0], best[1], best[2], best[3], best[4]);
    printf("Worst, %.6f, %.6f, %.6f, %.6f, %.6f\n", worst[0], worst[1], worst[2], worst[3], worst[4]);
    printf("Avg, %.6f, %.6f, %.6f, %.6f, %.6f\n", avg[0], avg[1], avg[2], avg[3], avg[4]);

    return 0;
}