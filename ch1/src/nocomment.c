#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int lim);

/* nocomment removes comments from C files */
/* double slash comments are not currently supported */
int main() {
    int len, inc, ins;
    char line[MAXLINE];

    char *s = "/* Comments in strings are ignored */";
    
    inc = ins = 0;
    
    while ((len = my_getline(line, MAXLINE)) > 0) {
        for (int i = 0; i < len; ++i) {
            int c = line[i];
            if (c == '"') {
                ins = !ins;
                putchar(c);
                continue;
            }
            if (c == '/' && line[i+1] == '*' && !ins) {
                inc = 1;
                ++i;
                continue;
            }
            else if (c == '*' && line[i+1] == '/' && !ins) {
                inc = 0;
                ++i;
                continue;
            }
            if (!inc)
                putchar(c);
        }
    }
    return 0;
}

/* my_getline is a simplified implementation of getline */
/* it gets lines from stdin and stores them in a given string, returning their length */
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
