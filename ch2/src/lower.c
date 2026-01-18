#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main() {
    int len;
    char s[MAXLINE];

    while ((len = my_getline(s, MAXLINE)) > 0) {
        for (int i = 0; i < len; ++i)
            s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] - 'A' + 'a') : s[i];
        printf("%s", s);
    }
}
