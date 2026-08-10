#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    char names[n][20];

    printf("Enter process names in the order they arrive in the ready queue:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d name: ", i + 1);
        scanf("%s", names[i]);
    }

    printf("\nOrder of execution (Ready Queue - FCFS order):\n");
    for (i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }

    return 0;
}
