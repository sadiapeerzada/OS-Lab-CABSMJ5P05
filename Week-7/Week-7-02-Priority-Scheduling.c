#include <stdio.h>
#define MAXP 20

void gantt(int *id, int *st, int *en, int k) {
    printf("\nGantt chart:\n");
    for (int i = 0; i < k; i++) {
        if (id[i]) printf("|  P%-3d ", id[i]); else printf("| idle  ");
    }
    printf("|\n");
    for (int i = 0; i < k; i++) printf("%-8d", st[i]);
    printf("%d\n", en[k - 1]);
}

int main(void) {
    int n, i, time = 0, k = 0, completed = 0;
    int at[MAXP], bt[MAXP], pr[MAXP], ct[MAXP], done[MAXP] = {0};





    int g_id[2 * MAXP], g_st[2 * MAXP], g_en[2 * MAXP];
    float sum_wt = 0, sum_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("P%d - arrival, burst, priority: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }
    while (completed < n) {
        int pick = -1;
        for (i = 0; i < n; i++) {
            if (done[i] || at[i] > time) continue;
            if (pick == -1 || pr[i] < pr[pick] ||
                (pr[i] == pr[pick] && at[i] < at[pick])) pick = i;
        }
        if (pick == -1) {                    /* CPU idle until next arrival */
            int next = -1;
            for (i = 0; i < n; i++)
                if (!done[i] && (next == -1 || at[i] < at[next])) next = i;
            g_id[k] = 0; g_st[k] = time; g_en[k++] = at[next];
            time = at[next];
            continue;
        }
        g_id[k] = pick + 1; g_st[k] = time;
        time += bt[pick];
        g_en[k++] = time;
        ct[pick] = time; done[pick] = 1; completed++;
    }
    gantt(g_id, g_st, g_en, k);
    printf("\nPID\tPri\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        int tat = ct[i] - at[i], wt = tat - bt[i];
        sum_wt += wt; sum_tat += tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, pr[i], at[i], bt[i], ct[i], tat, wt);
    }
    printf("\nAverage waiting time    = %.2f\n", sum_wt / n);
    printf("Average turnaround time = %.2f\n", sum_tat / n);
    return 0;
}
