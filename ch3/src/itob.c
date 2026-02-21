#include <stdio.h>

void reverse(char s[]) {
    int i, j, c;
    for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i)
        ;
    for (j = 0, --i; i > j; ++j, --i) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

char dectob(int n) {
    if (n < 10) {
        return n + '0';
    }
    return (n - 10) + 'A';
}

void itob(int n, char s[], int b) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;

    do {
        s[i++] = dectob(n % b);
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    int n, b;
    char s[128];

    n = 18;
    b = 4;
    itob(n,s,b);
    printf("%d in base %d is %s\n", n, b, s);

    s[0] = '\0';

    n = 192;
    b = 2;
    itob(n,s,b);
    printf("%d in base %d is %s\n", n, b, s);

    s[0] = '\0';

    n = -35;
    b = 17;
    itob(n,s,b);
    printf("%d in base %d is %s\n", n, b, s);

    s[0] = '\0';

    n = 12345678;
    b = 32;
    itob(n,s,b);
    printf("%d in base %d is %s\n", n, b, s);
}
