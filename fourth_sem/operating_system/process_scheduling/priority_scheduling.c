#include <stdio.h>
#define MAX 5

void findavgTimePriority(int p[], int bt[], int pr[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Sort based on priority using bubble sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (pr[j] > pr[j + 1]) {
                int t;
                t = pr[j]; pr[j] = pr[j + 1]; pr[j + 1] = t;
                t = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = t;
                t = p[j];  p[j] = p[j + 1];   p[j + 1] = t;
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    printf("PID  BT  PR  WT  TAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d   %2d  %2d  %2d  %3d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int p[MAX], bt[MAX], pr[MAX], n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter process number: ");
        scanf("%d", &p[i]);
        printf("Enter burst time of P%d: ", p[i]);
        scanf("%d", &bt[i]);
        printf("Enter priority of P%d: ", p[i]);
        scanf("%d", &pr[i]);
    }

    findavgTimePriority(p, bt, pr, n);
    return 0;
}
