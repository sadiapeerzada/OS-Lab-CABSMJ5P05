#include <stdio.h>

int main()
{
    int processes;
    int contextSwitchTime;
    int totalOverhead;

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter context switch time (ms): ");
    scanf("%d", &contextSwitchTime);

    totalOverhead = processes * contextSwitchTime;

    printf("Total Context Switch Overhead = %d ms\n", totalOverhead);

    return 0;
}
