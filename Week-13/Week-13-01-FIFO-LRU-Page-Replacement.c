#include <stdio.h>
#define MAXF 10
#define MAXR 50

int ref[MAXR], n, nf;

void show(int *frame, int i, int hit) {
    printf("%3d |", ref[i]);
    for (int j = 0; j < nf; j++) {
        if (frame[j] == -1) printf("  -"); else printf(" %2d", frame[j]);
    }
    printf(" | %s\n", hit ? "Hit" : "Fault");
}

int main(void) {
    int frame[MAXF], stamp[MAXF], i, j, hit, faults, next;

    printf("Enter number of frames: ");
    scanf("%d", &nf);
    printf("Enter length of reference string: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (i = 0; i < n; i++) scanf("%d", &ref[i]);

    printf("\nFIFO page replacement\nRef | Frames | Result\n");
    for (j = 0; j < nf; j++) frame[j] = -1;
    faults = 0; next = 0;
    for (i = 0; i < n; i++) {
        hit = 0;
        for (j = 0; j < nf; j++) if (frame[j] == ref[i]) hit = 1;
        if (!hit) { frame[next] = ref[i]; next = (next + 1) % nf; faults++; }
        show(frame, i, hit);
    }
    printf("FIFO page faults = %d, hit ratio = %.2f\n", faults, (float)(n - faults) / n);

    printf("\nLRU page replacement\nRef | Frames | Result\n");
    for (j = 0; j < nf; j++) { frame[j] = -1; stamp[j] = -1; }
    faults = 0;
    for (i = 0; i < n; i++) {
        int pos = -1;
        for (j = 0; j < nf; j++) if (frame[j] == ref[i]) pos = j;
        hit = (pos != -1);
        if (!hit) {
            pos = 0;                           /* choose empty frame, else least recently used */
            for (j = 0; j < nf; j++) {
                if (frame[j] == -1) { pos = j; break; }
                if (stamp[j] < stamp[pos]) pos = j;
            }
            frame[pos] = ref[i]; faults++;
        }
        stamp[pos] = i;                        /* remember time of last use */
        show(frame, i, hit);
    }
    printf("LRU page faults = %d, hit ratio = %.2f\n", faults, (float)(n - faults) / n);
    return 0;
}
