#include <stdio.h>
#include <time.h>

void tower_of_hanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    tower_of_hanoi(n - 1, from, aux, to);
    tower_of_hanoi(n - 1, aux, to, from);
}

double benchmark_hanoi(int n) {
    clock_t start = clock();
    tower_of_hanoi(n, 'A', 'C', 'B');
    clock_t end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    int sizes[] = {10, 15, 20, 25, 28};
    double times[5];

    for (int k = 0; k < 5; k++) {
        times[k] = benchmark_hanoi(sizes[k]);
    }

    printf("=== TOWER OF HANOI ===\n");
    printf("Size, %d, %d, %d, %d, %d\n", sizes[0], sizes[1], sizes[2], sizes[3], sizes[4]);
    printf("Time, %.6f, %.6f, %.6f, %.6f, %.6f\n", times[0], times[1], times[2], times[3], times[4]);

    return 0;
}