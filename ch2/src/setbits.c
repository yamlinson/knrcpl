#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
    int x, p, n, y, z;

    x = 71;
    p = 4;
    n = 3;
    y = 15;
    z = setbits(x,p,n,y);
    printf("%d, %d, %d, %d: %d\n", x, p, n, y, z);

    x = 38;
    p = 3;
    n = 3;
    y = 97;
    z = setbits(x,p,n,y);
    printf("%d, %d, %d, %d: %d\n", x, p, n, y, z);

    x = 62;
    p = 2;
    n = 3;
    y = 15;
    z = setbits(x,p,n,y);
    printf("%d, %d, %d, %d: %d\n", x, p, n, y, z);

    return 0;
}

int setbits(int x, int p, int n, int y) {
    /* Mask y and set to correct position */
    y = (y & ~(~0 << n)) << (p+1-n);
    /* Mask x to create 0s for y overlay */
    x = x & ~(~(~0 << n) << (p+1-n));
    /* set bits */
    return (x | y);
}
