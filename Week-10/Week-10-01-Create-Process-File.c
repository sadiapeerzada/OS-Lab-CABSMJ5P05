#include <stdio.h>

int main(void) {
    FILE *fp = fopen("processes.txt", "w");
    int n, pid, burst, i;
    if (fp == NULL) { perror("Cannot create file"); return 1; }

    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Process %d - PID and burst time: ", i + 1);
        scanf("%d %d", &pid, &burst);
        fprintf(fp, "%d %d\n", pid, burst);   /* one record per line */
    }
    fclose(fp);
    printf("%d process records written to processes.txt\n", n);
    return 0;
}
