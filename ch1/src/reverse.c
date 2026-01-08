#include <stdio.h>
#define MAXLINE 1000

int getline_local(char s[], int lim);
void reverse(char s[]);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getline_local(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

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

int getline_local(char s[], int lim) {
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
