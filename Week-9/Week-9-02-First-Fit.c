#include <stdio.h>
#define MAXB 20

int main(void) {
    int nb, np, block[MAXB], orig[MAXB], proc[MAXB], where[MAXB], left[MAXB], i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);
    printf("Enter block sizes: ");
    for (j = 0; j < nb; j++) { scanf("%d", &block[j]); orig[j] = block[j]; }
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter process sizes: ");
    for (i = 0; i < np; i++) scanf("%d", &proc[i]);

    for (i = 0; i < np; i++) {
        where[i] = -1;
        for (j = 0; j < nb; j++)
            if (block[j] >= proc[i]) {        /* first block that is large enough */
                where[i] = j;
                block[j] -= proc[i];
                left[i] = block[j];
                break;
            }
    }
    printf("\nProcess\tSize\tBlock\tBlock size\tLeft in block\n");
    for (i = 0; i < np; i++) {
        printf("P%d\t%d\t", i + 1, proc[i]);
        if (where[i] != -1) printf("%d\t%d\t\t%d\n", where[i] + 1, orig[where[i]], left[i]);
        else printf("-\t-\t\tNot allocated\n");
    }
    printf("\nFree space per block: ");
    for (j = 0; j < nb; j++) printf("%d ", block[j]);
    printf("\n");
    return 0;
}
