#include <stdio.h>
#include <stdlib.h>
#define MAXR 50

int main(void) {
    int n, i, head, req[MAXR], used[MAXR] = {0};
    int cur, total_sstf = 0, total_fcfs = 0, served;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request queue: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);

    cur = head;                                /* FCFS total for comparison */
    for (i = 0; i < n; i++) { total_fcfs += abs(req[i] - cur); cur = req[i]; }

    cur = head;
    printf("\nSSTF seek sequence: %d", cur);
    for (served = 0; served < n; served++) {
        int best = -1;
        for (i = 0; i < n; i++)                /* closest pending request */
            if (!used[i] && (best == -1 || abs(req[i] - cur) < abs(req[best] - cur))) best = i;
        total_sstf += abs(req[best] - cur);
        cur = req[best];
        used[best] = 1;
        printf(" -> %d", cur);
    }
    printf("\n\nFCFS total head movement = %d\n", total_fcfs);
    printf("SSTF total head movement = %d\n", total_sstf);
    printf("Improvement over FCFS    = %.1f%%\n", 100.0 * (total_fcfs - total_sstf) / total_fcfs);
    return 0;
}
