#include <stdio.h>
#define N 5                              /* processes */
#define M 3                              /* resource types */

int main(void) {
    int alloc[N][M], maxm[N][M], need[N][M], avail[M], work[M];
    int fin[N] = {0}, seq[N], count = 0, i, j, k;

    printf("Enter Allocation matrix (%d x %d):\n", N, M);
    for (i = 0; i < N; i++) {
        printf("P%d: ", i);
        for (j = 0; j < M; j++) scanf("%d", &alloc[i][j]);
    }
    printf("Enter Max matrix (%d x %d):\n", N, M);
    for (i = 0; i < N; i++) {
        printf("P%d: ", i);
        for (j = 0; j < M; j++) scanf("%d", &maxm[i][j]);
    }
    printf("Enter Available vector: ");
    for (j = 0; j < M; j++) scanf("%d", &avail[j]);

    printf("\nNeed = Max - Allocation:\n");
    for (i = 0; i < N; i++) {
        printf("P%d: ", i);
        for (j = 0; j < M; j++) {
            need[i][j] = maxm[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j < M; j++) work[j] = avail[j];

    while (count < N) {
        int found = 0;
        for (i = 0; i < N; i++) {
            if (fin[i]) continue;
            for (j = 0; j < M && need[i][j] <= work[j]; j++);
            if (j == M) {                    /* Pi can finish: it returns its resources */
                for (k = 0; k < M; k++) work[k] += alloc[i][k];
                fin[i] = 1; seq[count++] = i; found = 1;
            }
        }
        if (!found) {
            printf("\nSystem is in an UNSAFE state - deadlock is possible.\n");






            return 0;
        }
    }
    printf("\nSystem is in a SAFE state.\nSafe sequence: ");
    for (i = 0; i < N; i++) printf("P%d%s", seq[i], i < N - 1 ? " -> " : "\n");
    return 0;
}
