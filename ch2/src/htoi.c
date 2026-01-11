#include <stdio.h>
#define MAXLINE 32

int htoi(char s[]);
int hex_to_dec(char c);
int is_valid_hex_char(char c);
int my_getline(char s[], int lim);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = my_getline(line, MAXLINE) > 0))
        printf("%d\n", htoi(line));

    return 0;
}

int htoi(char s[]) {
    int i, n;

    i = n = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    for (; is_valid_hex_char(s[i]); ++i) {
        n = 16 * n + hex_to_dec(s[i]);
    }

    return n;
}

int hex_to_dec(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return 10 + c - 'a';
    if (c >= 'A' && c <= 'F')
        return 10 + c - 'A';
    return 0;
}

int is_valid_hex_char(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'a' && c <= 'f')
        return 1;
    if (c >= 'A' && c <= 'F')
        return 1;
    return 0;
}

int my_getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
