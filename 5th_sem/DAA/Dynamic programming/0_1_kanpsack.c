#include <stdio.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W, i, w;
    int weight[20], profit[20], dp[20][50];

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &weight[i]);
    printf("Enter profits:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &profit[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    clock_t start = clock();

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i] <= w)
                dp[i][w] = max(profit[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    clock_t end = clock();
    printf("Maximum profit = %d\n", dp[n][W]);
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
