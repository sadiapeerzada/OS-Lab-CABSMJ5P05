#include <stdio.h>

typedef struct {
    int pid;
    int burst;
    int waiting;
    int turnaround;
} Process;

int main(void) {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of processes must be positive.\n");
        return 1;
    }

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time for P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);

        if (p[i].burst < 0) {
            printf("Burst time cannot be negative.\n");
            return 1;
        }
    }

    /* Sort by burst time; equal burst times keep PID order. */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[j].burst < p[i].burst) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].waiting = 0;
    p[0].turnaround = p[0].burst;

    int total_waiting = p[0].waiting;
    int total_turnaround = p[0].turnaround;

    for (int i = 1; i < n; i++) {
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;

        total_waiting += p[i].waiting;
        total_turnaround += p[i].turnaround;
    }

    printf("\nSJN (Non-Preemptive) Scheduling\n");
    printf("Execution order: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", p[i].pid);
        if (i < n - 1) {
            printf(" -> ");
        }
    }
    printf("\n\n");

    printf("Process\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].burst, p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f\n",
           (float) total_waiting / n);
    printf("Average Turnaround Time: %.2f\n",
           (float) total_turnaround / n);

    return 0;
}
