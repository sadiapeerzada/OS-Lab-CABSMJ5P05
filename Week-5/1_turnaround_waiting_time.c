#include <stdio.h>

int main()
{
    int n;
    int bt[100], ct[100], tat[100], wt[100];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    /*
       Assumption: all processes arrive at time 0
       and are executed in FCFS order.
    */
    ct[0] = bt[0];

    for (int i = 1; i < n; i++)
        ct[i] = ct[i - 1] + bt[i];

    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i];       // TAT = CT - AT, AT = 0
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               i + 1, bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
