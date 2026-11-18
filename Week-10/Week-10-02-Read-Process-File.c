#include <stdio.h>

int main(void) {
    FILE *fp = fopen("processes.txt", "r");
    int pid, burst, total = 0;
    if (fp == NULL) { perror("Cannot open processes.txt"); return 1; }

    printf("PID\tBurst time\n");
    printf("---\t----------\n");
    while (fscanf(fp, "%d %d", &pid, &burst) == 2) {   /* stop at end of file */
        printf("%d\t%d\n", pid, burst);
        total += burst;
    }
    fclose(fp);
    printf("\nTotal burst time = %d\n", total);
    return 0;





}
