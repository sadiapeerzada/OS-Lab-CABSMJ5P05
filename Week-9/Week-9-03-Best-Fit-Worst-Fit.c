#include <stdio.h>
#define MAXB 20

int nb, np, orig[MAXB], proc[MAXB];

void simulate(const char *name, int worst) {
    int block[MAXB], i, j, pick, allocated = 0, total = 0, largest = 0;
    for (j = 0; j < nb; j++) block[j] = orig[j];
    printf("\n%s\n", name);
    for (i = 0; i < np; i++) {
        pick = -1;
        for (j = 0; j < nb; j++) {
            if (block[j] < proc[i]) continue;
            if (pick == -1 || (!worst && block[j] < block[pick]) ||
                              ( worst && block[j] > block[pick])) pick = j;
        }
        if (pick == -1) printf("  P%d (%d) -> not allocated\n", i + 1, proc[i]);
        else {
            printf("  P%d (%d) -> block %d (size %d), hole left %d\n", i + 1, proc[i],
                   pick + 1, block[pick], block[pick] - proc[i]);
            block[pick] -= proc[i];
            allocated++;
        }
    }
    for (j = 0; j < nb; j++) { total += block[j]; if (block[j] > largest) largest = block[j]; }
    printf("  Holes left     : ");
    for (j = 0; j < nb; j++) printf("%d ", block[j]);
    printf("\n  Allocated      : %d of %d processes\n", allocated, np);
    printf("  Total free     : %d, largest hole: %d\n", total, largest);
    printf("  Fragmentation  : %.1f%% (1 - largest hole / total free)\n",
           total ? 100.0 * (1.0 - (double)largest / total) : 0.0);
}

int main(void) {
    int i, j;
    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes: ");
    for (j = 0; j < nb; j++) scanf("%d", &orig[j]);
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter process sizes: ");
    for (i = 0; i < np; i++) scanf("%d", &proc[i]);
    simulate("BEST-FIT (smallest block that fits)", 0);
    simulate("WORST-FIT (largest block)", 1);
    return 0;
}
