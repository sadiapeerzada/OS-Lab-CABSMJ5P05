#include <stdio.h>
#define MAXP 20

int main(void) {
    int page_size, np, table[MAXP], nl, i, addr;

    printf("Enter page size (bytes): ");
    scanf("%d", &page_size);
    printf("Enter number of pages of the process: ");
    scanf("%d", &np);
    printf("Enter frame number for each page:\n");
    for (i = 0; i < np; i++) {
        printf("  page %d -> frame: ", i);
        scanf("%d", &table[i]);
    }
    printf("Enter number of logical addresses: ");
    scanf("%d", &nl);
    for (i = 0; i < nl; i++) {
        printf("\nLogical address %d: ", i + 1);
        scanf("%d", &addr);
        int page = addr / page_size;          /* page number = address / page size  */
        int offset = addr % page_size;        /* offset      = address % page size  */
        printf("  page number = %d, offset = %d\n", page, offset);
        if (page >= np)
            printf("  INVALID: page %d is not in the page table (address out of range)\n", page);
        else
            printf("  frame = %d, physical address = %d*%d + %d = %d\n", table[page],
                   table[page], page_size, offset, table[page] * page_size + offset);
    }
    return 0;
}
