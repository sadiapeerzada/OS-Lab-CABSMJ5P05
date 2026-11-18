#include <stdio.h>
#include <stdlib.h>
#define MAXR 50

int main(void) {
    int n, i, head, cur, req[MAXR], total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);
    printf("Enter request queue: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);

    cur = head;
    printf("\nHead movement:\n");
    for (i = 0; i < n; i++) {                 /* serve requests in arrival order */
        int d = abs(req[i] - cur);
        printf("  %3d -> %3d : %3d\n", cur, req[i], d);
        total += d;
        cur = req[i];
    }
    printf("\nTotal head movement = %d cylinders\n", total);
    printf("Average seek length = %.2f\n", (float)total / n);
    return 0;
}
