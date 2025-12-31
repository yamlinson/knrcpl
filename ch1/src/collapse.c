#include <stdio.h>

/* 1-9: remove duplicate whitespace characters */
int main() {
    int c, r, last;

    while ((c = getchar()) != EOF) {
        /* check for repeated whitespace character */
        r = 0;
        if (c == ' ' || c == '\t' || c == '\n') {
            if (c == last) {
                r = 1;
            }
            last = c;
        } else { /* reset on non-whitespace characters */
            last = -1;
        }
        if (r == 0) {
            putchar(c);
        }
    }
    return 0;
}
