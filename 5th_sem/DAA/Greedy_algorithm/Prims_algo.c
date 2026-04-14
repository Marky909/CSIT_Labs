#include <stdio.h>
#include <time.h>

int main() {
    int n, i, j, k, min, mincost = 0, a = 0, b = 0;
    int cost[20][20], visited[20] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    visited[1] = 1;
    clock_t start = clock();

    for (k = 1; k < n; k++) {
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (visited[i] && !visited[j] && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        printf("Edge (%d %d) cost=%d\n", a, b, min);
        mincost += min;
        visited[b] = 1;
    }

    clock_t end = clock();
    printf("Minimum cost = %d\n", mincost);
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
