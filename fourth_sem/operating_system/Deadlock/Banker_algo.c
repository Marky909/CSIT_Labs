#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int f[n], ans[n], ind = 0;

    // Input Allocation Matrix
    printf("Enter Allocation Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Input Max Matrix
    printf("Enter Max Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    // Input Available Resources
    printf("Enter Available Resources (length %d):\n", m);
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Initialize Finish array and calculate Need matrix
    for (i = 0; i < n; i++) {
        f[i] = 0;
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // Banker's Algorithm Main Logic
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    for (j = 0; j < m; j++)
                        avail[j] += alloc[i][j];
                    ans[ind++] = i;
                    f[i] = 1;
                }
            }
        }
    }

    // Check if all processes are finished
    int isSafe = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            isSafe = 0;
            printf("\nThe system is NOT in a safe state.\n");
            break;
        }
    }

    if (isSafe) {
        printf("\nThe system is in a SAFE state.\nSafe Sequence: ");
        for (i = 0; i < n; i++) {
            printf("P%d", ans[i]);
            if (i != n - 1)
                printf(" -> ");
        }
        printf("\n");
    }

    return 0;
}
