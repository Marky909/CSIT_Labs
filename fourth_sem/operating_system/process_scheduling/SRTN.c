#include <stdio.h>

int main() 
{
    int arrival[10], burst[10], remaining[10];
    int waiting[10], turnaround[10];
    int i, n, time = 0, smallest, count = 0;
    double total_waiting = 0, total_turnaround = 0;

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &n);

    // Get arrival times
    for (i = 0; i < n; i++) {
        printf("Enter arrival time for Process P%d: ", i + 1);
        scanf("%d", &arrival[i]);
    }

    // Get burst times and copy them to remaining time
    for (i = 0; i < n; i++) {
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i]; // store original burst time
    }

    printf("\nProcess execution started...\n");

    while (count < n) {
        smallest = -1;

        // Find the process with the shortest remaining time at current time
        for (i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0) {
                if (smallest == -1 || remaining[i] < remaining[smallest]) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            time++; // No process is ready, move time forward
            continue;
        }

        remaining[smallest]--;
        time++;

        // If process finishes
        if (remaining[smallest] == 0) {
            count++;
            int finish_time = time;

            turnaround[smallest] = finish_time - arrival[smallest];
            waiting[smallest] = turnaround[smallest] - burst[smallest];

            total_waiting += waiting[smallest];
            total_turnaround += turnaround[smallest];
        }
    }

    // Output
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time = %.2lf", total_waiting / n);
    printf("\nAverage Turnaround Time = %.2lf\n", total_turnaround / n);

    return 0;
}
