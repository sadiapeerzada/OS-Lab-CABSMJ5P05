#include <stdio.h>

int main()
{
    int seconds;
    int hours, minutes, remainingSeconds;

    printf("Enter CPU burst time in seconds: ");
    scanf("%d", &seconds);

    hours = seconds / 3600;
    remainingSeconds = seconds % 3600;

    minutes = remainingSeconds / 60;
    remainingSeconds = remainingSeconds % 60;

    printf("CPU Time = %02d:%02d:%02d\n", hours, minutes, remainingSeconds);

    return 0;
}
