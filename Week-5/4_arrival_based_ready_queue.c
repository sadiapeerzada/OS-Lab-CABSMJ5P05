#include <stdio.h>

typedef struct
{
    int pid;
    int arrival;
    int burst;
    int completed;
} Process;

int main()
{
    int n;
    Process p[100];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Arrival Time and Burst Time:\n");

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        p[i].completed = 0;

        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
    }

    int current_time = 0;
    int completed = 0;

    printf("\nReady Queue Simulation (FCFS):\n");

    while (completed < n)
    {
        int selected = -1;

        /*
           Find the first process that has arrived
           and is not completed.
        */
        for (int i = 0; i < n; i++)
        {
            if (!p[i].completed && p[i].arrival <= current_time)
            {
                if (selected == -1 ||
                    p[i].arrival < p[selected].arrival ||
                    (p[i].arrival == p[selected].arrival &&
                     p[i].pid < p[selected].pid))
                {
                    selected = i;
                }
            }
        }

        /*
           If no process has arrived yet,
           CPU stays idle until the next arrival.
        */
        if (selected == -1)
        {
            int next = -1;

            for (int i = 0; i < n; i++)
            {
                if (!p[i].completed)
                {
                    if (next == -1 || p[i].arrival < p[next].arrival)
                        next = i;
                }
            }

            current_time = p[next].arrival;
            printf("Time %d: CPU idle\n", current_time);
            continue;
        }

        printf("Time %d: P%d enters CPU (AT=%d, BT=%d)\n",
               current_time,
               p[selected].pid,
               p[selected].arrival,
               p[selected].burst);

        current_time += p[selected].burst;
        p[selected].completed = 1;
        completed++;

        printf("Time %d: P%d completed\n",
               current_time,
               p[selected].pid);

        /*
           Display processes currently waiting in
           the ready queue.
        */
        printf("Ready Queue: ");

        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (!p[i].completed && p[i].arrival <= current_time)
            {
                printf("P%d ", p[i].pid);
                found = 1;
            }
        }

        if (!found)
            printf("Empty");

        printf("\n\n");
    }

    return 0;
}
