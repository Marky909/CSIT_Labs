#include <stdio.h>

void findavgTimeSJF(int bt[], int n) {
    int p[n], wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Assign process IDs
    for (int i = 0; i < n; i++) p[i] = i + 1;

    // Sort by burst time using simple selection sort
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (bt[j] < bt[min]) min = j;

        // Swap burst time and process ID
        int temp = bt[i]; bt[i] = bt[min]; bt[min] = temp;
        temp = p[i]; p[i] = p[min]; p[min] = temp;
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("P   BT   WT   TAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d  %3d  %3d  %4d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n];
    printf("Enter Burst Time:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    findavgTimeSJF(bt, n);
    return 0;
}
