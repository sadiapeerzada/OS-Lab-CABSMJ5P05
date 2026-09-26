#include <stdio.h>

int main(void) {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of processes must be positive.\n");
        return 1;
    }

    int burst[n], waiting[n], turnaround[n];
    int total_waiting = 0, total_turnaround = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &burst[i]);

        if (burst[i] < 0) {
            printf("Burst time cannot be negative.\n");
            return 1;
        }
    }

    waiting[0] = 0;
    turnaround[0] = burst[0];

    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
        turnaround[i] = waiting[i] + burst[i];
    }

    printf("\nFCFS Scheduling\n");
    printf("Process\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        total_waiting += waiting[i];
        total_turnaround += turnaround[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n",
           (float) total_waiting / n);
    printf("Average Turnaround Time: %.2f\n",
           (float) total_turnaround / n);

    return 0;
}
