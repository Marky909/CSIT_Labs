#include <stdio.h>

int main() {
    int a[100], key, n, i, found = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the values of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the key value you want to search for: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("Search successful! Key found at position %d\n", i + 1);
            found = 1;  // Mark that the key was found
            break;      // Exit loop after finding the key
        }
    }

    if (!found) {
        printf("Search unsuccessful! Key not found in the array.\n");
    }

    return 0;
}
