#include <stdio.h>

int main()
{
    int n = 3;
    int bt[3];
    int time = 0;

    printf("Enter burst time for 3 processes:\n");

    for (int i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("\nGantt Chart:\n\n");

    printf("|");
    for (int i = 0; i < n; i++)
        printf("  P%d  |", i + 1);

    printf("\n0");

    for (int i = 0; i < n; i++)
    {
        time += bt[i];
        printf("%7d", time);
    }

    printf("\n");

    return 0;
}
