#include <stdio.h>
#define DISK 32
#define MAXF 10

int owner[DISK];                  /* 0 = free, -1 = reserved, k = file number */
int reserved[] = {2, 3, 7, 8, 9, 15, 16};

int first_free(void) {
    for (int i = 0; i < DISK; i++) if (owner[i] == 0) return i;
    return -1;
}

int main(void) {
    int n, f, i, free_blocks = 0, idx_blk[MAXF], data[MAXF][DISK], size[MAXF];
    char name[MAXF][20];

    for (i = 0; i < (int)(sizeof(reserved) / sizeof(reserved[0])); i++) owner[reserved[i]] = -1;
    for (i = 0; i < DISK; i++) if (owner[i] == 0) free_blocks++;

    printf("Disk has %d blocks, %d free. Enter number of files: ", DISK, free_blocks);
    scanf("%d", &n);
    for (f = 1; f <= n; f++) {
        printf("File %d - name and size in blocks: ", f);
        scanf("%19s %d", name[f - 1], &size[f - 1]);
        if (size[f - 1] + 1 > free_blocks) {
            printf("  Not enough free blocks for '%s'\n", name[f - 1]);
            size[f - 1] = -1; continue;
        }
        idx_blk[f - 1] = first_free();
        owner[idx_blk[f - 1]] = f;                 /* index block */
        for (i = 0; i < size[f - 1]; i++) {
            int b = first_free();
            owner[b] = f; data[f - 1][i] = b;      /* any free block can be used */
        }
        free_blocks -= size[f - 1] + 1;
    }
    printf("\nFile\tIndex block\tIndex contents (data blocks)\n");
    for (f = 0; f < n; f++) {
        if (size[f] < 0) continue;
        printf("%s\t%d\t\t[", name[f], idx_blk[f]);
        for (i = 0; i < size[f]; i++) printf("%d%s", data[f][i], i < size[f] - 1 ? ", " : "");
        printf("]\n");
    }
    printf("\nDisk map ('#' reserved, '.' free, lowercase = index block, UPPERCASE = data):\n");
    for (i = 0; i < DISK; i++) {
        if (i % 8 == 0) printf("  %2d-%2d: ", i, i + 7);
        if (owner[i] == -1) printf("# ");
        else if (owner[i] == 0) printf(". ");
        else if (i == idx_blk[owner[i] - 1]) printf("%c ", name[owner[i] - 1][0] | 32);
        else printf("%c ", name[owner[i] - 1][0] & ~32);
        if (i % 8 == 7) printf("\n");
    }
    if (n > 0 && size[0] >= 3)
        printf("\nDirect access: logical block 2 of '%s' is physical block %d\n",
               name[0], data[0][2]);
    return 0;
}
