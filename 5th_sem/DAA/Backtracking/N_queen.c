#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[20], n;

int place(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void queen(int row) {
    for (int col = 1; col <= n; col++) {
        if (place(row, col)) {
            board[row] = col;
            if (row == n) {
                for (int i = 1; i <= n; i++)
                    printf("Queen %d -> Column %d\n", i, board[i]);
                printf("\n");
            } else {
                queen(row + 1);
            }
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    clock_t start = clock();
    queen(1);
    clock_t end = clock();

    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
