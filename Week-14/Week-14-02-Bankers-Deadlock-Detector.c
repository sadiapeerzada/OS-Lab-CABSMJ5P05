#include <stdio.h>
#define N 5
#define M 3

int alloc[N][M] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int maxm[N][M]  = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int avail[M]    = {3, 3, 2};

int need(int i, int j) { return maxm[i][j] - alloc[i][j]; }

int is_safe(int seq[]) {
    int work[M], fin[N] = {0}, i, j, k, count = 0;
    for (j = 0; j < M; j++) work[j] = avail[j];
    while (count < N) {
        int found = 0;
        for (i = 0; i < N; i++) {
            if (fin[i]) continue;





            for (j = 0; j < M && need(i, j) <= work[j]; j++);
            if (j == M) {
                for (k = 0; k < M; k++) work[k] += alloc[i][k];
                fin[i] = 1; seq[count++] = i; found = 1;
            }
        }
        if (!found) return 0;
    }
    return 1;
}

void show_state(void) {
    int seq[N], i, j;
    printf("\nProc  Alloc   Max    Need\n");
    for (i = 0; i < N; i++) {
        printf("P%d    ", i);
        for (j = 0; j < M; j++) printf("%d ", alloc[i][j]);
        printf("  ");
        for (j = 0; j < M; j++) printf("%d ", maxm[i][j]);
        printf("  ");
        for (j = 0; j < M; j++) printf("%d ", need(i, j));
        printf("\n");
    }
    printf("Available: %d %d %d\n", avail[0], avail[1], avail[2]);
    if (is_safe(seq)) {
        printf("State: SAFE, sequence ");
        for (i = 0; i < N; i++) printf("P%d ", seq[i]);
        printf("\n");
    } else printf("State: UNSAFE - deadlock possible\n");
}

void request(void) {
    int pid, req[M], seq[N], j;
    printf("Enter process id: "); scanf("%d", &pid);
    printf("Enter request vector: "); for (j = 0; j < M; j++) scanf("%d", &req[j]);
    for (j = 0; j < M; j++)
        if (req[j] > need(pid, j)) { printf("Error: P%d exceeded max claim\n", pid); return; }
    for (j = 0; j < M; j++)
        if (req[j] > avail[j]) { printf("P%d must WAIT: not enough available\n", pid); return; }
    for (j = 0; j < M; j++) { avail[j] -= req[j]; alloc[pid][j] += req[j]; }
    if (is_safe(seq)) printf("Request GRANTED (state stays safe)\n");
    else {
        for (j = 0; j < M; j++) { avail[j] += req[j]; alloc[pid][j] -= req[j]; }
        printf("Request DENIED: granting it would make the state UNSAFE\n");
    }
}

void release(void) {
    int pid, rel[M], j;
    printf("Enter process id: "); scanf("%d", &pid);
    printf("Enter resources to release: "); for (j = 0; j < M; j++) scanf("%d", &rel[j]);
    for (j = 0; j < M; j++)
        if (rel[j] > alloc[pid][j]) { printf("Error: P%d holds less than that\n", pid); return; }
    for (j = 0; j < M; j++) { alloc[pid][j] -= rel[j]; avail[j] += rel[j]; }
    printf("Resources released by P%d\n", pid);
}

int main(void) {
    int choice;
    do {
        printf("\n1.Request 2.Release 3.Show state 4.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        if (choice == 1) request();
        else if (choice == 2) release();
        else if (choice == 3) show_state();
    } while (choice != 4);
    return 0;
}
