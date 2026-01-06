#include <stdio.h>
#define MINLINE 80
#define MAXLINE 1000

int getline_local(char s[], int lim);

/* prints all lines over MINLINE chars */
int main() {
    int len, min;
    char line[MAXLINE];
    
    min = MINLINE;
    while ((len = getline_local(line, MAXLINE)) > 0) {
        if (len > min) {
            printf("%s", line);
        }
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
