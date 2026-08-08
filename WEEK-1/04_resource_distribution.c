#include <stdio.h>

int main()
{
    int printers;
    int users;
    int printersPerUser;
    int remainingPrinters;

    printf("Enter total number of printers: ");
    scanf("%d", &printers);

    printf("Enter number of users: ");
    scanf("%d", &users);

    if (users <= 0)
    {
        printf("Number of users must be greater than 0.\n");
        return 1;
    }

    printersPerUser = printers / users;
    remainingPrinters = printers % users;

    printf("Each user gets %d printer(s)\n", printersPerUser);
    printf("Remaining printers = %d\n", remainingPrinters);

    return 0;
}
