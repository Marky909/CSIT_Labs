#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){ return (*(int*)a - *(int*)b); }

int main() {
    int n, head, disk_size, dir;
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size: ");
    scanf("%d", &disk_size);

    printf("Enter the head movement direction (1 for high / 0 for low): ");
    scanf("%d", &dir);

    qsort(req, n, sizeof(int), cmp);

    int seek = 0, cur = head;
    printf("Seek Sequence: ");

    int split = 0; while (split < n && req[split] < head) split++;

    if (dir == 1) { // move high, wrap to 0, then continue high
        for (int i = split; i < n; i++) { seek += abs(req[i]-cur); cur=req[i]; printf("%d ", cur); }
        if (cur != disk_size-1) { seek += abs((disk_size-1)-cur); cur = disk_size-1; }
        // wrap: end -> 0 (no service during wrap)
        if (cur != 0) { seek += (disk_size-1) - 0; cur = 0; }
        for (int i = 0; i < split; i++) { seek += abs(req[i]-cur); cur=req[i]; printf("%d%c", cur, i+1<split ? ' ':'\n'); }
        if (split==0) printf("\n");
    } else { // move low, wrap to disk_size-1, then continue low
        for (int i = split-1; i >= 0; i--) { seek += abs(req[i]-cur); cur=req[i]; printf("%d ", cur); }
        if (cur != 0) { seek += abs(cur-0); cur = 0; }
        // wrap: 0 -> end
        if (cur != disk_size-1) { seek += (disk_size-1) - 0; cur = disk_size-1; }
        for (int i = n-1; i >= split; i--) { seek += abs(req[i]-cur); cur=req[i]; printf("%d%c", cur, i>split ? ' ':'\n'); }
        if (split==n) printf("\n");
    }

    printf("Total Seek Time = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / n);
    return 0;
}
