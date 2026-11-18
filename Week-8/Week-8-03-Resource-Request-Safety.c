#include <stdio.h>
#define N 5
#define M 3

int alloc[N][M] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int maxm[N][M]  = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int avail[M]    = {3, 3, 2};

int is_safe(int seq[]) {
    int work[M], fin[N] = {0}, i, j, k, count = 0;
    for (j = 0; j < M; j++) work[j] = avail[j];
    while (count < N) {
        int found = 0;
        for (i = 0; i < N; i++) {
            if (fin[i]) continue;
            for (j = 0; j < M && maxm[i][j] - alloc[i][j] <= work[j]; j++);
            if (j == M) {
                for (k = 0; k < M; k++) work[k] += alloc[i][k];
                fin[i] = 1; seq[count++] = i; found = 1;
            }
        }
        if (!found) return 0;
    }
    return 1;
}

int main(void) {
    int pid, req[M], seq[N], j, i;





    for (;;) {
        printf("\nEnter process id (-1 to stop): ");
        if (scanf("%d", &pid) != 1 || pid < 0) break;
        printf("Enter request vector: ");
        for (j = 0; j < M; j++) scanf("%d", &req[j]);

        for (j = 0; j < M && req[j] <= maxm[pid][j] - alloc[pid][j]; j++);
        if (j < M) { printf("Error: P%d exceeded its maximum claim\n", pid); continue; }
        for (j = 0; j < M && req[j] <= avail[j]; j++);
        if (j < M) { printf("P%d must WAIT: resources not available\n", pid); continue; }

        for (j = 0; j < M; j++) { avail[j] -= req[j]; alloc[pid][j] += req[j]; }   /* pretend */
        if (is_safe(seq)) {
            printf("Request GRANTED. Safe sequence: ");
            for (i = 0; i < N; i++) printf("P%d ", seq[i]);
            printf("\n");
        } else {
            for (j = 0; j < M; j++) {                 /* roll back */
                avail[j] += req[j]; alloc[pid][j] -= req[j];
            }
            printf("Request DENIED: it would lead to an unsafe state\n");
        }
    }
    return 0;
}
