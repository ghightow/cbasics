/*
 * Reverses input lines one at a time
 */

#include <stdio.h>

#define MAXLINE 1000 /* Note: MAXLINE includes terminating newline and null characters */

/* getbigline: read an aribitrarily long line placing as much as
 * possible into 's' and returning the full length
 */

int getbigline(char s[], int lim) {
    int c;
    int len = 0;
    int slen = 0;

    while ((c = getchar()) != EOF && c != '\n') {
        if (slen < (lim - 2))
            s[slen++] = c;
        ++len;
    }

    s[slen++] = '\n';
    s[slen] = '\0';

    return len;
}

/* reverse: reverses a line
 */

void reverse(char s[], int length) {
    char temp;
    for (int i = 0; i < (length - i - 1); i++) {
        temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}

/* Main */

int main() {

    char line[MAXLINE];

    int len = 0;
    while ((len = getbigline(line, MAXLINE)) > 0) {
        reverse(line, len);
        printf("%s", line);
    }

}


