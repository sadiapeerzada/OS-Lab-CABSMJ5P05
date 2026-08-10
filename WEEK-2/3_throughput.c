#include <stdio.h>

int main() {
    int n;
    float total_time, throughput;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter total time taken: ");
    scanf("%f", &total_time);

    if (total_time == 0) {
        printf("Total time cannot be zero.\n");
        return 1;
    }

    throughput = n / total_time;

    printf("Throughput = %.2f processes/unit time\n", throughput);

    return 0;
}
