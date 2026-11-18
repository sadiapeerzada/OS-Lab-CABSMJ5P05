#include <stdio.h>

int main(void) {
    FILE *fp = fopen("processes.txt", "r");
    int pid, burst, count = 0;
    if (fp == NULL) { perror("Cannot open processes.txt"); return 1; }

    while (fscanf(fp, "%d %d", &pid, &burst) == 2) count++;
    fclose(fp);
    printf("Number of process entries in file = %d\n", count);
    return 0;
}
