#include <stdio.h>

int main() {
    int arrival[10], burst[10], remaining[10];
    int wt[10], tat[10];
    int i, n, time = 0, remain, quantum;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);
    remain = n;

    for (i = 0; i < n; i++) {
        printf("Enter arrival time for Process P%d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int flag = 0;
    for (time = 0, i = 0; remain != 0; ) {
        if (remaining[i] > 0 && arrival[i] <= time) {
            if (remaining[i] <= quantum) {
                time += remaining[i];
                remaining[i] = 0;
                flag = 1;
            } else {
                remaining[i] -= quantum;
                time += quantum;
            }

            if (remaining[i] == 0 && flag == 1) {
                remain--;
                tat[i] = time - arrival[i];
                wt[i] = tat[i] - burst[i];
                total_wt += wt[i];
                total_tat += tat[i];
                flag = 0;
            }
        }

        if (i == n - 1)
            i = 0;
        else if (arrival[i + 1] <= time)
            i++;
        else
            i = 0;
    }

    // Display results
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
