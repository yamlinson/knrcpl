#include <stdio.h>
#define MAXLINE 1000

int getline_local(char s[], int lim);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = getline_local(line, MAXLINE)) > 0) {
        int c, i, p;
        p = 0;
        for (i = len-2; i >= 0; i--) {
            c = line[i];
            if (c != ' ' && c != '\t' && c != '\n') {
                p = 1;
                line[i+1] = '\0';
                break;
            }
        }
        if (p == 1)
            printf("%s\n", line);
    }
    return 0;
}

int getline_local(char s[], int lim) {
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
