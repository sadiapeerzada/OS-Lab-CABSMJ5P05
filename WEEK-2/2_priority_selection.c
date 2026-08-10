#include <stdio.h>

int main() {
    int priority[5];
    int i, minIndex = 0;

    printf("Enter priorities of 5 processes (1=High, 2=Medium, 3=Low):\n");
    for (i = 0; i < 5; i++) {
        printf("Priority of P%d: ", i + 1);
        scanf("%d", &priority[i]);
    }

    // Lower number = higher priority, so find the minimum value
    for (i = 1; i < 5; i++) {
        if (priority[i] < priority[minIndex]) {
            minIndex = i;
        }
    }

    printf("\nProcess P%d runs first (Priority = %d).\n", minIndex + 1, priority[minIndex]);

    return 0;
}
