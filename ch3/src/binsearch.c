#include <stdio.h>

/* int binsearch(int x, int v[], int n) { */
/*     int low, high, mid; */
/**/
/*     low = 0; */
/*     high = n - 1; */
/*     while (low <= high) { */
/*         mid = (low+high) / 2; */
/*         if (x < v[mid]) */
/*             high = mid - 1; */
/*         else if (x > v[mid]) */
/*             low = mid + 1; */
/*         else */
/*             return mid; */
/*     } */
/*     return -1; */
/* } */

int binsearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low+high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return (v[low] == x && low < n) ? low : -1;
}

int main() {
    int x, n, p;
    int v[16];

    x = 3;
    n = 16;
    for (int i = 0; i < 16; ++i)
        v[i] = i;
    p = binsearch(x, v, n);
    printf("%d is%s in given array\n", x, (p != -1) ? "" : " not");
    if (p != -1)
        printf("Pos: %d\n", p);

    x = 3;
    n = 16;
    for (int i = 0; i < 16; ++i)
        v[i] = i + 5;
    p = binsearch(x, v, n);
    printf("%d is%s in given array\n", x, (p != -1) ? "" : " not");
    if (p != -1)
        printf("Pos: %d\n", p);

    x = 3;
    n = 16;
    for (int i = 0; i < 16; ++i)
        v[i] = 2 * i;
    p = binsearch(x, v, n);
    printf("%d is%s in given array\n", x, (p != -1) ? "" : " not");
    if (p != -1)
        printf("Pos: %d\n", p);
}
