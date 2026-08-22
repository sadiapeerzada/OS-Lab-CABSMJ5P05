#include <stdio.h>

#define MAX 20

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
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
    }
}

void calculateCompletionTime(Process p[], int n) {
    for (int i = 0; i < n; i++) {
        p[i].completion_time =
            p[i].arrival_time + p[i].burst_time;
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

int main() {
    Process p[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    inputProcesses(p, n);
    calculateCompletionTime(p, n);
    displayProcesses(p, n);

    return 0;
}
