#include <stdio.h>
#define MAXP 20
#define QSZ 1000

int n, tq, id[MAXP], at[MAXP], bt[MAXP], rem[MAXP], ct[MAXP], admitted[MAXP];
int queue[QSZ], front = 0, rear = 0;

void admit(int time) {                      /* put newly arrived processes in the queue */
    for (int i = 0; i < n; i++)
        if (!admitted[i] && at[i] <= time) { queue[rear++] = i; admitted[i] = 1; }
}

void gantt(int *gi, int *st, int *en, int k) {
    printf("\nGantt chart:\n");
    for (int i = 0; i < k; i++) {
        if (gi[i]) printf("|  P%-3d ", gi[i]); else printf("| idle  ");
    }
    printf("|\n");
    for (int i = 0; i < k; i++) printf("%-8d", st[i]);
    printf("%d\n", en[k - 1]);
}

int main(void) {
    int i, j, t, time = 0, done = 0, k = 0;
    int g_id[QSZ], g_st[QSZ], g_en[QSZ];
    float sum_wt = 0, sum_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        id[i] = i + 1;
        printf("P%d - arrival time, burst time: ", id[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    for (i = 0; i < n - 1; i++)             /* sort by arrival time */
        for (j = 0; j < n - i - 1; j++)
            if (at[j] > at[j + 1]) {
                t = at[j]; at[j] = at[j + 1]; at[j + 1] = t;
                t = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = t;
                t = rem[j]; rem[j] = rem[j + 1]; rem[j + 1] = t;
                t = id[j]; id[j] = id[j + 1]; id[j + 1] = t;
            }
    admit(0);
    while (done < n) {
        if (front == rear) {                /* ready queue empty: CPU idle */
            int next = -1;
            for (i = 0; i < n; i++)
                if (!admitted[i] && (next == -1 || at[i] < at[next])) next = i;
            g_id[k] = 0; g_st[k] = time; g_en[k++] = at[next];
            time = at[next];
            admit(time);
            continue;
        }
        i = queue[front++];





        int run = rem[i] < tq ? rem[i] : tq;
        g_id[k] = id[i]; g_st[k] = time;
        time += run;
        g_en[k++] = time;
        rem[i] -= run;
        admit(time);                        /* arrivals during the slice queue first */
        if (rem[i] > 0) queue[rear++] = i;
        else { ct[i] = time; done++; }
    }
    gantt(g_id, g_st, g_en, k);
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        int tat = ct[i] - at[i], wt = tat - bt[i];
        sum_wt += wt; sum_tat += tat;
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", id[i], at[i], bt[i], ct[i], tat, wt);
    }
    printf("\nAverage waiting time    = %.2f\n", sum_wt / n);
    printf("Average turnaround time = %.2f\n", sum_tat / n);
    printf("Context switches        = %d\n", k - 1);
    return 0;
}
