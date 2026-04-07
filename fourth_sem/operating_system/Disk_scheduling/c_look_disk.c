#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { 
    return (*(int*)a - *(int*)b); 
}

int main() {
    int n, head, dir;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++) 
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter the head movement direction (1 for high / 0 for low): ");
    scanf("%d", &dir);

    // Sort requests in ascending order
    qsort(req, n, sizeof(int), cmp);

    int seek = 0, cur = head;
    printf("Seek Sequence: ");

    // Find split point where requests >= head
    int split = 0; 
    while (split < n && req[split] < head) 
        split++;

    if (dir == 1) { // Moving towards higher values
        for (int i = split; i < n; i++) {
            seek += abs(req[i] - cur);
            cur = req[i];
            printf("%d ", cur);
        }
        if (split > 0) { // Wrap to lowest request
            seek += abs(cur - req[0]);
            cur = req[0];
            for (int i = 0; i < split; i++) {
                seek += abs(req[i] - cur);
                cur = req[i];
                printf("%d ", cur);
            }
        }
    } 
    else { // Moving towards lower values
        for (int i = split - 1; i >= 0; i--) {
            seek += abs(req[i] - cur);
            cur = req[i];
            printf("%d ", cur);
        }
        if (split < n) { // Wrap to highest request
            seek += abs(cur - req[n - 1]);
            cur = req[n - 1];
            for (int i = n - 1; i >= split; i--) {
                seek += abs(req[i] - cur);
                cur = req[i];
                printf("%d ", cur);
            }
        }
    }

    printf("\nTotal Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / n);

    return 0;
}
