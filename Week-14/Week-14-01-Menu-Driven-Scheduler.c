#include <stdio.h>
#define MAXP 10
#define MAXS 300

typedef struct { int pid, at, bt, pr, ct; } Proc;
Proc p[MAXP];
int n, gk, g_id[MAXS], g_st[MAXS], g_en[MAXS];

void seg(int id, int st, int en) { g_id[gk] = id; g_st[gk] = st; g_en[gk++] = en; }

void non_preemptive(int mode) {                /* 0 = FCFS, 1 = SJN, 2 = Priority */
    int done[MAXP] = {0}, count = 0, time = 0, i, pick;
    gk = 0;
    while (count < n) {
        pick = -1;
        for (i = 0; i < n; i++) {
            if (done[i] || p[i].at > time) continue;
            if (pick == -1) { pick = i; continue; }
            int better = mode == 0 ? p[i].at < p[pick].at
                       : mode == 1 ? p[i].bt < p[pick].bt : p[i].pr < p[pick].pr;
            if (better) pick = i;
        }
        if (pick == -1) {                      /* idle until next arrival */
            int nx = -1;
            for (i = 0; i < n; i++) if (!done[i] && (nx == -1 || p[i].at < p[nx].at)) nx = i;
            seg(0, time, p[nx].at); time = p[nx].at;
            continue;
        }
        seg(p[pick].pid, time, time + p[pick].bt);
        time += p[pick].bt;
        p[pick].ct = time; done[pick] = 1; count++;
    }
}

void round_robin(int q) {
    int rem[MAXP], adm[MAXP] = {0}, queue[MAXS], f = 0, r = 0, time = 0, done = 0, i;
    gk = 0;
    for (i = 0; i < n; i++) rem[i] = p[i].bt;
    for (i = 0; i < n; i++)
        if (p[i].at <= 0) { queue[r++] = i; adm[i] = 1; }
    while (done < n) {
        if (f == r) {
            int nx = -1;
            for (i = 0; i < n; i++) if (!adm[i] && (nx == -1 || p[i].at < p[nx].at)) nx = i;
            seg(0, time, p[nx].at); time = p[nx].at;
            for (i = 0; i < n; i++)
                if (!adm[i] && p[i].at <= time) { queue[r++] = i; adm[i] = 1; }
            continue;
        }
        i = queue[f++];
        int run = rem[i] < q ? rem[i] : q;
        seg(p[i].pid, time, time + run);
        time += run; rem[i] -= run;
        for (int j = 0; j < n; j++)
            if (!adm[j] && p[j].at <= time) { queue[r++] = j; adm[j] = 1; }
        if (rem[i] > 0) queue[r++] = i; else { p[i].ct = time; done++; }
    }





}

void averages(float *w, float *t) {
    *w = *t = 0;
    for (int i = 0; i < n; i++) { *t += p[i].ct - p[i].at; *w += p[i].ct - p[i].at - p[i].bt; }
    *w /= n; *t /= n;
}

void report(const char *name) {
    float w, t;
    printf("\n=== %s ===\nGantt chart:\n", name);
    for (int i = 0; i < gk; i++) {
        if (g_id[i]) printf("|  P%-3d ", g_id[i]); else printf("| idle  ");
    }
    printf("|\n");
    for (int i = 0; i < gk; i++) printf("%-8d", g_st[i]);
    printf("%d\n\nPID\tAT\tBT\tPri\tCT\tTAT\tWT\n", g_en[gk - 1]);
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].ct,
               p[i].ct - p[i].at, p[i].ct - p[i].at - p[i].bt);
    averages(&w, &t);
    printf("Average WT = %.2f, Average TAT = %.2f\n", w, t);
}

int main(void) {
    int i, choice, q = 2;
    float w, t;
    const char *names[] = {"FCFS", "SJN", "Round Robin", "Priority"};

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d - arrival, burst, priority: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pr);
    }
    do {
        printf("\n1.FCFS 2.SJN 3.Round Robin 4.Priority 5.Compare 6.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice >= 1 && choice <= 4) {
            if (choice == 3) { printf("Enter time quantum: "); scanf("%d", &q); round_robin(q); }
            else non_preemptive(choice == 4 ? 2 : choice - 1);
            report(names[choice - 1]);
        } else if (choice == 5) {
            printf("\nAlgorithm     Avg WT   Avg TAT   Context switches\n");
            for (i = 0; i < 4; i++) {
                if (i == 2) round_robin(q); else non_preemptive(i == 3 ? 2 : i);
                averages(&w, &t);
                printf("%-12s  %6.2f   %7.2f   %d\n", names[i], w, t, gk - 1);
            }
        }
    } while (choice != 6);
    return 0;
}
