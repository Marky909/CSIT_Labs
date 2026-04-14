#include <stdio.h>
#include <time.h>

int main() {
    int a, b, temp;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    clock_t start = clock();

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    clock_t end = clock();
    printf("GCD = %d\n", a);
    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
