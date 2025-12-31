#include <stdio.h>

/* 1-8: Count only spaces, tabs, and newlines */
int main() {
    int c, nw;
    nw = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            nw++;
        }
    }

    printf("%d", nw);
    return 0;
}
