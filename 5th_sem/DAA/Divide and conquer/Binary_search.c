#include <stdio.h>
#include <time.h>

int main() {
    int n, a[100], key, low = 0, high, mid;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &key);

    high = n - 1;
    clock_t start = clock();

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            printf("Element found at position %d\n", mid + 1);
            break;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (low > high)
        printf("Element not found\n");

    clock_t end = clock();
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
