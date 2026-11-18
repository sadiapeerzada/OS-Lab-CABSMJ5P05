#include <stdio.h>
#include <stdlib.h>
#define MAXR 50

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int report(const char *name, int *seq, int len) {
    int total = 0, i;
    printf("\n%s seek sequence: ", name);
    for (i = 0; i < len; i++) {
        printf("%d%s", seq[i], i < len - 1 ? " -> " : "\n");
        if (i) total += abs(seq[i] - seq[i - 1]);





    }
    printf("%s total head movement = %d\n", name, total);
    return total;
}

int main(void) {
    int n, i, head, disk, dir, req[MAXR], lo[MAXR], up[MAXR], nl = 0, nu = 0;
    int seq[2 * MAXR + 4], len, s, c;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request queue: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size (cylinders 0..size-1): ");
    scanf("%d", &disk);
    printf("Enter direction (1 = towards higher, 0 = towards lower): ");
    scanf("%d", &dir);

    for (i = 0; i < n; i++) { if (req[i] < head) lo[nl++] = req[i]; else up[nu++] = req[i]; }
    qsort(lo, nl, sizeof(int), cmp);
    qsort(up, nu, sizeof(int), cmp);

    len = 0; seq[len++] = head;                /* ---- SCAN ---- */
    if (dir) {
        for (i = 0; i < nu; i++) seq[len++] = up[i];
        seq[len++] = disk - 1;
        for (i = nl - 1; i >= 0; i--) seq[len++] = lo[i];
    } else {
        for (i = nl - 1; i >= 0; i--) seq[len++] = lo[i];
        seq[len++] = 0;
        for (i = 0; i < nu; i++) seq[len++] = up[i];
    }
    s = report("SCAN  ", seq, len);

    len = 0; seq[len++] = head;                /* ---- C-SCAN (return jump counted) ---- */
    if (dir) {
        for (i = 0; i < nu; i++) seq[len++] = up[i];
        seq[len++] = disk - 1; seq[len++] = 0;
        for (i = 0; i < nl; i++) seq[len++] = lo[i];
    } else {
        for (i = nl - 1; i >= 0; i--) seq[len++] = lo[i];
        seq[len++] = 0; seq[len++] = disk - 1;
        for (i = nu - 1; i >= 0; i--) seq[len++] = up[i];
    }
    c = report("C-SCAN", seq, len);

    printf("\nComparison: SCAN = %d, C-SCAN = %d cylinders\n", s, c);
    return 0;
}
