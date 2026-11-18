#include <stdio.h>
#define MAXP 20

int main(void) {
    int n, i, t = 0, done = 0, thr;
    int at[MAXP], bt[MAXP], pr[MAXP], rem[MAXP];
    int wait[MAXP] = {0}, first[MAXP], fin[MAXP];

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("P%d - arrival, burst, priority: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rem[i] = bt[i]; first[i] = -1;
    }
    printf("Enter starvation threshold (time units): ");
    scanf("%d", &thr);

    while (done < n) {                       /* simulate one time unit per iteration */
        int run = -1;
        for (i = 0; i < n; i++)
            if (at[i] <= t && rem[i] > 0 && (run == -1 || pr[i] < pr[run])) run = i;
        if (run == -1) { t++; continue; }
        if (first[run] == -1) first[run] = t;
        for (i = 0; i < n; i++)              /* every other ready process waits */
            if (i != run && at[i] <= t && rem[i] > 0) wait[i]++;
        rem[run]--; t++;
        if (rem[run] == 0) { fin[run] = t; done++; }
    }
    printf("\nPID\tPri\tAT\tBT\tFirstRun\tFinish\tStarvation\tStatus\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t\t%d\t%d\t\t%s\n", i + 1, pr[i], at[i], bt[i],
               first[i], fin[i], wait[i], wait[i] > thr ? "STARVED" : "ok");
    return 0;
}
