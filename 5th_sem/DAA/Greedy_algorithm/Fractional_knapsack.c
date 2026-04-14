#include <stdio.h>
#include <time.h>

struct Item {
    float weight, profit, ratio;
};

int main() {
    int n, i, j;
    float capacity, totalProfit = 0;
    struct Item item[100], temp;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &item[i].weight, &item[i].profit);
        item[i].ratio = item[i].profit / item[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }

    clock_t start = clock();

    for (i = 0; i < n; i++) {
        if (capacity >= item[i].weight) {
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else {
            totalProfit += item[i].ratio * capacity;
            break;
        }
    }

    clock_t end = clock();
    printf("Maximum profit = %.2f\n", totalProfit);
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
