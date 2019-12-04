/*
 * Write a program to remove trailing blanks and tabs
 * from each line of input, and to delete entirely blank
 * lines.
 */

#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[]);
void removeTabs(char s[]);
void removeTrailing(char s[], int len);

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getLine(line)) > 0) {
        if (len > 1) {
            removeTrailing(line, len);
            removeTabs(line);
            printf("%s", line);
        }
    }
    return 0;
}

/* 
 * getLine: read a line into s, if input is just
 * blank space return 1, else return length.
 */
int getLine(char s[])
{
    int c, i, flag;
    flag = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c != '\n' && c != '\t' && c != ' ')
            flag = 1;
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    if (flag == 0)
        i = 1;
    return i;
}

void removeTrailing(char s[], int j)
{
    while (s[j] == '\n' || s[j] == '\t' || s[j] == ' ')
        --j;
    s[j] = '\0';

}

/* removeTabs: remove tabs from line */
void removeTabs(char s[])
{
    int i;
    i = 0;
    while (s[i] != '\n') {
        if (s[i] == '\t')
            s[i] = ' ';
        ++i;
    }
}