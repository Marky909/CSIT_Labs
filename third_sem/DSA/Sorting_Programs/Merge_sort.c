#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i = 0, j = 0, k = left;
    int n1 = mid - left + 1, n2 = right - mid;
    int leftSub[n1], rightSub[n2];

    for (i = 0; i < n1; i++) leftSub[i] = arr[left + i];
    for (j = 0; j < n2; j++) rightSub[j] = arr[mid + 1 + j];

    for (i = 0, j = 0; i < n1 && j < n2; k++) 
        arr[k] = (leftSub[i] <= rightSub[j]) ? leftSub[i++] : rightSub[j++];
    
    while (i < n1) arr[k++] = leftSub[i++];
    while (j < n2) arr[k++] = rightSub[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {120, 110, 130, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    mergeSort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    return 0;
}
