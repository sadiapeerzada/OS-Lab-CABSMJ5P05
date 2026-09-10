#include <stdio.h>

int main()
{
    int n;
    float bt[100], wt[100], response_ratio;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter waiting time and burst time for each process:\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nP%d waiting time: ", i + 1);
        scanf("%f", &wt[i]);

        printf("P%d burst time: ", i + 1);
        scanf("%f", &bt[i]);

        response_ratio = (wt[i] + bt[i]) / bt[i];

        printf("P%d Response Ratio = %.2f\n",
               i + 1, response_ratio);
    }

    return 0;
}
