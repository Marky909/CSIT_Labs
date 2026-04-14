#include <stdio.h>
#include <time.h>

int main() {
    int n, cost[20][20], dist[20], visited[20] = {0};
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &start);

    clock_t startTime = clock();

    for (i = 1; i <= n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }
    dist[start] = 0;
    visited[start] = 1;

    for (i = 1; i < n; i++) {
        int min = 999, next = -1;
        for (j = 1; j <= n; j++) {
            if (dist[j] < min && !visited[j]) {
                min = dist[j];
                next = j;
            }
        }
        if (next == -1)
            break;
        visited[next] = 1;
        for (j = 1; j <= n; j++) {
            if (!visited[j] && dist[next] + cost[next][j] < dist[j])
                dist[j] = dist[next] + cost[next][j];
        }
    }

    clock_t endTime = clock();
    printf("Shortest distances:\n");
    for (i = 1; i <= n; i++)
        printf("%d -> %d = %d\n", start, i, dist[i]);
    printf("Execution time: %f seconds\n", (double)(endTime - startTime) / CLOCKS_PER_SEC);
    return 0;
}
