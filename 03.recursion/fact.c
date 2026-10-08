#include <stdio.h>
#include <time.h>

double benchmark_factorial(int n) {
    clock_t start = clock();
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int sizes[] = {10000, 500000, 700000, 1000000, 2000000};
    double times[5];

    for (int k = 0; k < 5; k++) {
        times[k] = benchmark_factorial(sizes[k]);
    }

    printf("=== FACTORIAL ===\n");
    printf("Size, %d, %d, %d, %d, %d\n", sizes[0], sizes[1], sizes[2], sizes[3], sizes[4]);
    printf("Time, %.6f, %.6f, %.6f, %.6f, %.6f\n", times[0], times[1], times[2], times[3], times[4]);

    return 0;
}