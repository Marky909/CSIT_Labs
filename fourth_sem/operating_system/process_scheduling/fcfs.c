#include <stdio.h>

void findavgTime(int bt[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("Process %d: BT=%d WT=%d TAT=%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int bt[] = {10, 5, 8 , 12, 6};
    int n = sizeof(bt) / sizeof(bt[0]);
    findavgTime(bt, n);
    return 0;
}