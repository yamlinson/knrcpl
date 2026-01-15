#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
    int x, p, n, y;

    x = 170;
    p = 5;
    n = 2;
    y = invert(x, p, n);
    printf("%d, %d, %d: %d\n", x, p, n, y);

    x = 255;
    p = 5;
    n = 3;
    y = invert(x, p, n);
    printf("%d, %d, %d: %d\n", x, p, n, y);

    x = 1;
    p = 5;
    n = 2;
    y = invert(x, p, n);
    printf("%d, %d, %d: %d\n", x, p, n, y);
}

unsigned invert(unsigned x, int p, int n) {
    return (x ^ (~(~0 << n) << (p+1-n)));
}
