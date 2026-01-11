#include <stdio.h>
#define TABSIZE 8
#define MAXLINE 1000

int my_getline(char s[], int lim);

int main() {
    int len, c, i, j;
    char line[MAXLINE];
    char cline[MAXLINE*TABSIZE]; // Prevent overflow if max tabs fed as input

    while ((len = my_getline(line, MAXLINE)) > 0) {
        j = 0;
        for (i = 0; i < len; ++i) {
            c = line[i];
            if (c == '\t') {
                cline[j] = ' ';
                ++j;
                int d = TABSIZE - (j % TABSIZE);
                for (int k = 0; k < d; ++k) {
                    cline[j] = ' ';
                    ++j;
                }
            } else {
                cline[j] = c;
                ++j;
            }
        }
        printf("%s", cline);
    }
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
