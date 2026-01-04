#include <stdio.h>

#define IN  1
#define OUT 0

/* Prints a histogram of the lengths of the words given as input */
int main() {
    int i, j, c, l, state;
    int lengths[16];

    state = OUT;
    l = 0;

    for (i = 0; i < 16; i++)
        lengths[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            if (l > 0) {
                if (l >= 16)
                    ++lengths[15];
                else
                    ++lengths[l-1];
            }
            l = 0;
        } else if (c == '-') {
            /* Hyphens don't count toward length, but also don't break the word */
            ;
        } else {
            ++l;
        }
    }

    for (i = 0; i < 16; i++) {
        if (i == 15)
            printf("16+:\t");
        else
            printf("%d:\t", i+1);
        for (j = 1; j <= lengths[i]; j++) {
            printf("x");
        }
        printf("\n");
    }

    return 0;
}
