#include <stdio.h>

int main() {
    int c, i, nwhite, nother;
    int ndigits[10];

    nwhite = nother = 0;

    for (i = 0; i < 10; i++) {
        ndigits[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigits[c - '0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            ++nwhite;
        else
            ++nother;
    }

    for (i = 0; i < 10; i++)
        printf("%d:\t\t%d\n", i, ndigits[i]);

    printf("whitespace:\t%d\n", nwhite);
    printf("other:\t\t%d\n", nother);

    return 0;
}
