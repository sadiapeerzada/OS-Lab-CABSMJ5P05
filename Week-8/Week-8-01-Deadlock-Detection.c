#include <stdio.h>
#define MAXP 10

int n, g[MAXP][MAXP], state[MAXP], parent[MAXP];
int cyc_start = -1, cyc_end = -1;

int dfs(int u) {                       /* state: 0 = new, 1 = on stack, 2 = finished */
    state[u] = 1;
    for (int v = 0; v < n; v++) {
        if (!g[u][v]) continue;
        if (state[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return 1;
        } else if (state[v] == 1) {    /* back edge: circular wait found */
            cyc_start = v; cyc_end = u;
            return 1;
        }
    }
    state[u] = 2;
    return 0;
}

int main(void) {
    int i, j, path[MAXP], len = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter wait-for matrix (1 if Pi waits for Pj):\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < n; j++) scanf("%d", &g[i][j]);
    }
    for (i = 0; i < n; i++) parent[i] = -1;
    for (i = 0; i < n && cyc_start == -1; i++)
        if (state[i] == 0) dfs(i);

    if (cyc_start == -1) {
        printf("\nNo circular wait found - system is deadlock free.\n");
        return 0;
    }
    for (i = cyc_end; i != cyc_start; i = parent[i]) path[len++] = i;
    path[len++] = cyc_start;
    printf("\nDEADLOCK detected. Circular wait: ");
    for (i = len - 1; i >= 0; i--) printf("P%d -> ", path[i]);
    printf("P%d\n", path[len - 1]);
    printf("Deadlocked processes: ");
    for (i = len - 1; i >= 0; i--) printf("P%d ", path[i]);
    printf("\n");
    return 0;
}
