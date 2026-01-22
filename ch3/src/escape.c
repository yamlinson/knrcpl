#include <stdio.h>
#define MAXLINE 1000

void escape(char to[], char from[]) {
    int i, j;
    for (i = j = 0; from[i] != '\0'; i++) {
        int c = from[i];
        switch (c) {
            case '\n':
                to[j++] = '\\';
                to[j++] = 'n';
                break;
            case '\t':
                to[j++] = '\\';
                to[j++] = 't';
                break;
            default:
                to[j++] = c;
                break;
        }
    }
    to[j] = '\0';
}

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
    char t[2*MAXLINE];

    if ((len = my_getline(s, MAXLINE))) {
        escape(t, s);
        printf("%s\n", t);
    }
}
