#include <stdio.h>

#define MAX 20

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
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

void displayProcesses(Process p[], int n) {
    printf("\nPID\tArrival\tBurst\n");
    printf("----------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time);
    }
}

int main() {
    Process p[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    inputProcesses(p, n);
    displayProcesses(p, n);

    return 0;
}
