#include <stdio.h>
#include <time.h>

int set[20], subset[20], n;

void generateSubset(int i, int currentSum, int target) {
    if (i == n) {
        if (currentSum == target) {
            printf("{ ");
            for (int j = 0; j < n; j++) {
                if (subset[j] == 1)
                    printf("%d ", set[j]);
            }
            printf("}\n");
        }
        return;
    }

    subset[i] = 1;
    generateSubset(i + 1, currentSum + set[i], target);
    subset[i] = 0;
    generateSubset(i + 1, currentSum, target);
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);
    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);

    clock_t start = clock();
    printf("Subsets that sum to %d are:\n", target);
    generateSubset(0, 0, target);
    clock_t end = clock();

    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
