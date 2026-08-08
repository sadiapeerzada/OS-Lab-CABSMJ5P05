#include <stdio.h>

int main()
{
    int pid;

    printf("Enter Process ID: ");
    scanf("%d", &pid);

    if (pid % 2 == 0)
    {
        printf("System Process\n");
    }
    else
    {
        printf("User Process\n");
    }

    return 0;
}
