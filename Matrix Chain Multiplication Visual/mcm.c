#include <time.h>
#include <limits.h>
#include <stdio.h>

void program_with_dp(int p[], int n) {
    int m[n][n];

    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
}

int program_without_dp(int p[], int i, int j) {
    if (i == j) {
        return 0;
    }

    int minOperations = INT_MAX;
    for (int k = i; k < j; k++) {
        int operations = program_without_dp(p, i, k) + program_without_dp(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (operations < minOperations) {
            minOperations = operations;
        }
    }

    return minOperations;
}

int main() {
    int p[] = {26, 24, 68, 30, 17, 17, 65, 12, 26, 72, 19, 72, 29, 34, 12, 16, 43, 52, 18};
    int n = sizeof(p) / sizeof(p[0]);

    int iterations = 100;  // Increase the number of iterations

    clock_t total_time_with_dp = 0;
    clock_t total_time_without_dp = 0;

    for (int i = 0; i < iterations; i++) {
        clock_t start_time = clock();
        program_with_dp(p, n);
        clock_t end_time = clock();
        total_time_with_dp += end_time - start_time;

        start_time = clock();
        program_without_dp(p, 1, n - 1);
        end_time = clock();
        total_time_without_dp += end_time - start_time;
    }

    double average_execution_time_with_dp = (double)total_time_with_dp / (CLOCKS_PER_SEC * iterations);
    double average_execution_time_without_dp = (double)total_time_without_dp / (CLOCKS_PER_SEC * iterations);

    printf("Average Execution time with DP: %f sec\n", average_execution_time_with_dp);
    printf("Average Execution time without DP: %f sec\n", average_execution_time_without_dp);

    // Save the execution times to a file
    FILE *file = fopen("execution_times.txt", "w");
    if (file != NULL) {
        fprintf(file, "Average Execution time with DP: %f\n", average_execution_time_with_dp);
        fprintf(file, "Average Execution time without DP: %f\n", average_execution_time_without_dp);
        fclose(file);
    }

    return 0;
}
