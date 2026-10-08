#include <stdio.h>
#include <time.h>

double benchmark_binary_digits(int n) {
    clock_t start = clock();
    int count = 0;
    while (n > 0) {
        count++;
        n /= 2;
    }
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int sizes[] = {10, 500, 50000, 5000000, 500000000, };
    double times[5];

    for (int k = 0; k < 5; k++) {
        times[k] = benchmark_binary_digits(sizes[k]);
    }

    printf("=== BINARY DIGITS COUNT ===\n");
    printf("Size, %d, %d, %d, %d, %d\n", sizes[0], sizes[1], sizes[2], sizes[3], sizes[4]);
    printf("Time, %.6f, %.6f, %.6f, %.6f, %.6f\n", times[0], times[1], times[2], times[3], times[4]);

    return 0;
}