#include <stdio.h>

#define MAX 20

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int completed;
} Process;

void inputProcesses(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        printf("PID: ");
        scanf("%d", &p[i].pid);

        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);

        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);

        p[i].completed = 0;
        p[i].completion_time = 0;
    }
}

void displayProcesses(Process p[], int n) {
    printf("\nPID\tArrival\tBurst\tCompletion\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].completion_time);
    }
}

void sjn(Process p[], int n) {
    int completed = 0;
    int current_time = 0;

    while (completed < n) {
        int shortest = -1;

        // Find the shortest job among processes that have arrived.
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].arrival_time <= current_time) {
                if (shortest == -1 ||
                    p[i].burst_time < p[shortest].burst_time) {
                    shortest = i;
                }
            }
        }

        // If no process has arrived yet, move time forward.
        if (shortest == -1) {
            current_time++;
            continue;
        }

        current_time += p[shortest].burst_time;
        p[shortest].completion_time = current_time;
        p[shortest].completed = 1;
        completed++;
    }
}

int main() {
    Process p[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    inputProcesses(p, n);
    sjn(p, n);

    printf("\nSJN Scheduling Result");
    displayProcesses(p, n);

    return 0;
}
