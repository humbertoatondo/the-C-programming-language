/* 
 * Write a program to print all input lines that are
 * longer than 80 characters.
 */

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define UPPER 80     /* lines with len grater than UPPER will get printed */

    int getLine(char line[]);
void copy(char to[], char from[]);

int main()
{
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getLine(line)) > 0)
        if (len > UPPER)
            printf("%d %s\n", len, line);
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[])
{
    int c, i;
    for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) 
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}