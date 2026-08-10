#include <stdio.h>

int main() {
    int n, i, minIndex = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n];
    char names[n][20];

    printf("Enter process name and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d name: ", i + 1);
        scanf("%s", names[i]);
        printf("Burst time: ");
        scanf("%d", &burst[i]);
    }

    for (i = 1; i < n; i++) {
        if (burst[i] < burst[minIndex]) {
            minIndex = i;
        }
    }

    printf("\nProcess with shortest burst time: %s (Burst Time = %d)\n",
           names[minIndex], burst[minIndex]);

    return 0;
}
