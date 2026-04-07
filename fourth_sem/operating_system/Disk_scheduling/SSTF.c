#include <stdio.h>
#include <stdlib.h>

typedef struct { 
    int pos; 
    int done; 
} Node;

int main() {
    int n, head;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    Node R[n];
    for (int i = 0; i < n; i++) 
        R[i] = (Node){ req[i], 0 };

    int seek = 0;

    printf("Seek Sequence: ");
    for (int c = 0; c < n; c++) {
        int best = -1, bestd = 1e9;
        for (int i = 0; i < n; i++) 
            if (!R[i].done) {
                int d = abs(R[i].pos - head);
                if (d < bestd) {
                    bestd = d;
                    best = i;
                }
            }

        R[best].done = 1;
        seek += abs(R[best].pos - head);
        head = R[best].pos;
        printf("%d%c", head, c < n - 1 ? ' ' : '\n');
    }

    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / n);

    return 0;
}
