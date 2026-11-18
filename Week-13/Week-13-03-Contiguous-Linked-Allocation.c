#include <stdio.h>
#define DISK 32
#define MAXF 10

int reserved[] = {2, 3, 7, 8, 9, 15, 16};
int nres = sizeof(reserved) / sizeof(reserved[0]);

void init(int *own) {
    for (int i = 0; i < DISK; i++) own[i] = 0;
    for (int i = 0; i < nres; i++) own[reserved[i]] = -1;
}

void map(const char *title, int *own, char *nm) {
    printf("%s\n", title);
    for (int i = 0; i < DISK; i++) {
        if (i % 8 == 0) printf("  %2d-%2d: ", i, i + 7);
        printf("%c ", own[i] == -1 ? '#' : own[i] == 0 ? '.' : nm[own[i] - 1]);
        if (i % 8 == 7) printf("\n");
    }
}

int main(void) {
    int n, f, i, j, size[MAXF], own_c[DISK], own_l[DISK];
    char nm[MAXF];

    printf("Enter number of files: ");
    scanf("%d", &n);
    for (f = 0; f < n; f++) {
        printf("File %d - name (one letter) and size: ", f + 1);
        scanf(" %c %d", &nm[f], &size[f]);
    }

    init(own_c);
    printf("\n--- CONTIGUOUS ALLOCATION (first fit) ---\n");
    for (f = 0; f < n; f++) {
        int start = -1;
        for (i = 0; i + size[f] <= DISK && start == -1; i++) {
            for (j = 0; j < size[f] && own_c[i + j] == 0; j++);
            if (j == size[f]) start = i;
        }
        if (start == -1) {
            int fr = 0;
            for (i = 0; i < DISK; i++) if (own_c[i] == 0) fr++;
            printf("File %c (%d blocks): FAILED - no run of %d free blocks\n",
                   nm[f], size[f], size[f]);
            printf("    (but %d blocks are free in total)\n", fr);
        } else {
            for (j = 0; j < size[f]; j++) own_c[start + j] = f + 1;






            printf("File %c (%d blocks): start = %d, length = %d (blocks %d-%d)\n",
                   nm[f], size[f], start, size[f], start, start + size[f] - 1);
        }
    }
    map("Disk map:", own_c, nm);

    init(own_l);
    printf("\n--- LINKED ALLOCATION ---\n");
    for (f = 0; f < n; f++) {
        int blk[DISK], cnt = 0;
        for (i = 0; i < DISK && cnt < size[f]; i++) if (own_l[i] == 0) blk[cnt++] = i;
        if (cnt < size[f]) {
            printf("File %c (%d blocks): FAILED - disk full\n", nm[f], size[f]);
            continue;
        }
        printf("File %c: ", nm[f]);
        for (j = 0; j < cnt; j++) { own_l[blk[j]] = f + 1; printf("%d -> ", blk[j]); }
        printf("NULL\n");
    }
    map("Disk map:", own_l, nm);
    return 0;
}
