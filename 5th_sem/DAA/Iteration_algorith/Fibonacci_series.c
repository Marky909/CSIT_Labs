#include <stdio.h>
#include <time.h>

int main() {
    int n, a = 0, b = 1, c;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    clock_t start = clock();

    if (n >= 1) printf("Fibonacci Series: %d ", a);
    if (n >= 2) printf("%d ", b);

    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    clock_t end = clock();
    printf("\nExecution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
