#include <stdio.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
} Process;

int main() {
    Process p;

    printf("Enter process ID: ");
    scanf("%d", &p.pid);

    printf("Enter arrival time: ");
    scanf("%d", &p.arrival_time);

    printf("Enter burst time: ");
    scanf("%d", &p.burst_time);

    printf("\nProcess Details\n");
    printf("PID: %d\n", p.pid);
    printf("Arrival Time: %d\n", p.arrival_time);
    printf("Burst Time: %d\n", p.burst_time);

    return 0;
}
