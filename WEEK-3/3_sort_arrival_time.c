#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    char names[n][20];
    int arrival[n];

    printf("Enter process name and arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d name: ", i + 1);
        scanf("%s", names[i]);
        printf("Arrival time: ");
        scanf("%d", &arrival[i]);
    }

    // Simple bubble sort based on arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arrival[j] > arrival[j + 1]) {
                int temp = arrival[j];
                arrival[j] = arrival[j + 1];
                arrival[j + 1] = temp;

                char tempName[20];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);
            }
        }
    }

    printf("\nProcesses sorted by arrival time (ascending):\n");
    for (i = 0; i < n; i++) {
        printf("%s -> Arrival Time = %d\n", names[i], arrival[i]);
    }

    return 0;
}
