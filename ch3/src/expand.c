#include <stdio.h>

int rangeable_chars(char c, char d) {
    if (c >= 'a' && c <= 'z' && d >= 'a' && d <= 'z' ||
        c >= 'A' && c <= 'Z' && d >= 'A' && d <= 'Z' ||
        c >= '0' && c <= '9' && d >= '0' && d <= '9' )
        return 1;
    else
        return 0;
}

void expand(char s[], char t[]) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] == '-' && i > 0) {
            if (rangeable_chars(s[i-1], s[i+1])) {
                int d = s[i+1] - s[i-1];
                if (d > 1) {
                    for (int k = 1; k < d; k++)
                        t[j++] = s[i-1] + k;
                } else if (d < -1) {
                    for (int k = -1; k > d; k--)
                        t[j++] = s[i-1] + k;
                } else
                    t[j++] = '-';
            } else
                t[j++] = '-';
        } else {
            t[j++] = s[i];
        }
    }
    t[j] = '\0';
}

int main() {
    char t[128];

    char test1[] = "a-zA-Z0-9";
    expand(test1, t);
    printf("%s\n", t);

    char test2[] = "z-aZ-A9-0";
    expand(test2, t);
    printf("%s\n", t);

    char test3[] = "a-dZ-W5-8";
    expand(test3, t);
    printf("%s\n", t);

    char test4[] = "-a-aD-48-";
    expand(test4, t);
    printf("%s\n", t);

    char test5[] = "a-b-c";
    expand(test5, t);
    printf("%s\n", t);

    char test6[] = "-a-z";
    expand(test6, t);
    printf("%s\n", t);
}
