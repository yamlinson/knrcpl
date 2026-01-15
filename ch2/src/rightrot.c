#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
    int i;
    unsigned y, z;
    y = z = x;
    for (i = 0; y > 0; ++i)
        y = y >> 1;
    z = (x & ~(~0 << n)) << (i-n);
    x = x >> n;
    return (z | x);
}

int main() {
    unsigned x, y;
    int n;

    x = 240;
    n = 4;
    y = rightrot(x, n);
    printf("%d, %d: %d\n", x, n, y);
    
    x = 255;
    n = 3;
    y = rightrot(x, n);
    printf("%d, %d: %d\n", x, n, y);
    
    x = 193;
    n = 1;
    y = rightrot(x, n);
    printf("%d, %d: %d\n", x, n, y);
}
