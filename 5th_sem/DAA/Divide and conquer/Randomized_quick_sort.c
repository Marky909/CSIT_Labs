#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

int randomPartition(int a[], int low, int high) {
    int pivot = low + rand() % (high - low + 1);
    int temp = a[pivot];
    a[pivot] = a[high];
    a[high] = temp;
    return partition(a, low, high);
}

void randomQuickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(a, low, high);
        randomQuickSort(a, low, pi - 1);
        randomQuickSort(a, pi + 1, high);
    }
}

int main() {
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    srand((unsigned)time(NULL));
    clock_t start = clock();
    randomQuickSort(a, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nExecution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
