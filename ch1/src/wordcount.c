#include <stdio.h>

#define IN  1
#define OUT 0

int main() {

    int state, c, nw, nl, nc;
    nw = nl = nc = 0;
    state = OUT;

    while((c = getchar()) != EOF) {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d\t%d\t%d\n", nc, nw, nl);
    return 0;
}
