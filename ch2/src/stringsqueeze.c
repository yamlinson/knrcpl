#include <stdio.h>
#define MAXLINE 1000

int my_getline(char s[], int lim);

int main() {
    int len_s, len_r;
    char s[MAXLINE];
    char r[MAXLINE];
    
    printf("Original string\n");
    len_s = my_getline(s, MAXLINE);
    printf("String to remove\n");
    len_r = my_getline(r, MAXLINE);

    for (int i = 0; i < len_r; ++i) {
        int j, k;
        for (j = k = 0; j < len_s; ++j) {
            if (s[j] != r[i] && s[j] != '\n')
                s[k++] = s[j];
        }
        s[k] = '\0';
    }

    printf("%s\n", s);
    return 0;
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
