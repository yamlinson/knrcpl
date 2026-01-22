#include <stdio.h>
#define MAXLINE 1000

void unescape(char to[], char from[]) {
    int i, j;
    for (i = j = 0; from[i] != '\0'; i++) {
        int c = from[i];
        if (c == '\\') {
            switch (from[i+1]) {
                case 'n':
                    to[j++] = '\n';
                    ++i;
                    break;
                case 't':
                    to[j++] = '\t';
                    ++i;
                    break;
                case '\\':
                    to[j++] = '\\';
                    ++i;
                    break;
                default:
                    to[j++] = c;
                    break;
            }
        }
        else
            to[j++] = c;
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
    char t[MAXLINE];

    if ((len = my_getline(s, MAXLINE))) {
        unescape(t, s);
        printf("%s", t);
    }
}
