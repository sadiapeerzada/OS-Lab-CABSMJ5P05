#include <stdio.h>

int main() {
    float busy_time, idle_time, total_time, utilization;

    printf("Enter CPU busy time: ");
    scanf("%f", &busy_time);

    printf("Enter CPU idle time: ");
    scanf("%f", &idle_time);

    total_time = busy_time + idle_time;

    if (total_time == 0) {
        printf("Total time cannot be zero.\n");
        return 1;
    }

    utilization = (busy_time / total_time) * 100;

    printf("CPU Utilization = %.2f%%\n", utilization);

    return 0;
}
