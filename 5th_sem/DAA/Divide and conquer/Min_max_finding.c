#include <stdio.h>
#include <time.h>

struct Pair {
    int min;
    int max;
};

struct Pair minmax(int arr[], int low, int high) {
    struct Pair p, left, right;
    if (low == high) {
        p.min = p.max = arr[low];
        return p;
    }
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            p.min = arr[low];
            p.max = arr[high];
        } else {
            p.min = arr[high];
            p.max = arr[low];
        }
        return p;
    }
    int mid = (low + high) / 2;
    left = minmax(arr, low, mid);
    right = minmax(arr, mid + 1, high);
    p.min = (left.min < right.min) ? left.min : right.min;
    p.max = (left.max > right.max) ? left.max : right.max;
    return p;
}

int main() {
    int n, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();
    struct Pair result = minmax(arr, 0, n - 1);
    clock_t end = clock();

    printf("Minimum = %d\n", result.min);
    printf("Maximum = %d\n", result.max);
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
