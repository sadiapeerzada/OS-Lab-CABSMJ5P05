#include <stdio.h>
#define MAXB 10

int blk[MAXB] = {100, 500, 200, 300, 600};
int proc[] = {212, 417, 112, 426};
int nb = 5, np = 4;

void simulate(const char *name, int mode) {      /* 0 first, 1 best, 2 worst */
    int owner[MAXB], i, j, pick, internal = 0, unalloc = 0, free_total = 0;
    for (j = 0; j < nb; j++) owner[j] = -1;
    printf("\n%s   (1 char = 20 units, # used, . wasted)\n", name);
    for (i = 0; i < np; i++) {
        pick = -1;
        for (j = 0; j < nb; j++) {
            if (owner[j] != -1 || blk[j] < proc[i]) continue;
            if (pick == -1 || (mode == 1 && blk[j] < blk[pick]) ||
                              (mode == 2 && blk[j] > blk[pick])) pick = j;
            if (mode == 0) break;
        }
        if (pick == -1) {
            printf("  P%d (%d) could NOT be allocated\n", i + 1, proc[i]);
            unalloc++;
        } else owner[pick] = i;
    }
    for (j = 0; j < nb; j++) {
        int w = blk[j] / 20, used = owner[j] == -1 ? 0 : (proc[owner[j]] + 19) / 20;
        printf("  B%d %3d |", j + 1, blk[j]);
        for (i = 0; i < w; i++) putchar(i < used ? '#' : '.');
        if (owner[j] == -1) { printf("| free partition\n"); free_total += blk[j]; }
        else {
            int waste = blk[j] - proc[owner[j]];
            printf("| P%d (%d), internal waste %d\n", owner[j] + 1, proc[owner[j]], waste);
            internal += waste;
        }
    }
    printf("  Internal fragmentation : %d units\n", internal);
    printf("  Free partitions        : %d units%s\n", free_total,
           unalloc ? " (external fragmentation: a process is still waiting)" : "");
    printf("  Unallocated processes  : %d\n", unalloc);
}

int main(void) {
    printf("Partitions: 100 500 200 300 600 | Processes: 212 417 112 426\n");
    simulate("FIRST-FIT", 0);
    simulate("BEST-FIT", 1);
    simulate("WORST-FIT", 2);
    return 0;
}
