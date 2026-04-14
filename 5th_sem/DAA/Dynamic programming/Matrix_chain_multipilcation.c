#include <stdio.h>
#include <limits.h>
#include <time.h>

int main() {
    int n, i, j, k, L;
    int p[20], m[20][20], q;

    printf("Enter number of matrices: ");
    scanf("%d", &n);
    printf("Enter dimensions array:\n");
    for (i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    clock_t start = clock();

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    clock_t end = clock();
    printf("Minimum multiplication cost = %d\n", m[1][n]);
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
