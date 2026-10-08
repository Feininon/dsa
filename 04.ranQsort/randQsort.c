#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort_recursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort_recursive(arr, low, pi - 1);
        quick_sort_recursive(arr, pi + 1, high);
    }
}

void generate_best_quicksort(int arr[], int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    generate_best_quicksort(arr, low, mid - 1);
    generate_best_quicksort(arr, mid + 1, high);
    swap(&arr[mid], &arr[high]);
}

void generate_best(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i;
    generate_best_quicksort(arr, 0, n - 1);
}

void generate_worst(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = i;
}

void generate_avg(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 100000;
}
double quick_sort(int arr[], int n) {
    clock_t start = clock();
    quick_sort_recursive(arr, 0, n - 1);
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    srand((unsigned int)time(NULL));
    int sizes[] = {100, 1000, 2500, 5000, 10000, 20000};
    double best[6], worst[6], avg[6];

    for (int k = 0; k < 6; k++) {
        int n = sizes[k];
        int *arr = (int *)malloc(n * sizeof(int));
        generate_best(arr, n);
        best[k] = quick_sort(arr, n);
        generate_worst(arr, n);
        worst[k] = quick_sort(arr, n);
        generate_avg(arr, n);
        avg[k] = quick_sort(arr, n);
        free(arr);
    }
    printf("=== QUICK SORT ===\n");
    printf("Size, %d, %d, %d, %d, %d, %d\n", sizes[0], sizes[1], sizes[2], sizes[3], sizes[4],sizes[5] );
    printf("Best, %.6f, %.6f, %.6f, %.6f, %.6f, %.6f\n", best[0], best[1], best[2], best[3], best[4],best[5]);
    printf("Worst, %.6f, %.6f, %.6f, %.6f,%.6f,  %.6f\n", worst[0], worst[1], worst[2], worst[3], worst[4],worst[5]);
    printf("Avg, %.6f, %.6f, %.6f, %.6f,%.6f,  %.6f\n", avg[0], avg[1], avg[2], avg[3], avg[4],avg[5]);

    return 0;
}