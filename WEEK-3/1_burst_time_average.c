#include <stdio.h>

int main() {
    int n, i;
    float total = 0, average;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n];

    printf("Enter burst times for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &burst[i]);
        total += burst[i];
    }

    average = total / n;

    printf("\nTotal Burst Time = %.2f\n", total);
    printf("Average Burst Time = %.2f\n", average);

    return 0;
}
