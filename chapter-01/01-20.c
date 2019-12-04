/*
 * Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next  tab stop.
 * Assume a fixed set of tab stops, say every n columns. Should
 * n be a variable or a symbolic parameter?
 */

#include <stdio.h>

#define MAXSIZE 1000
#define TABWIDTH 8

char line[MAXSIZE];
char newLine[MAXSIZE];

int getLine();
void detab();

int main()
{
    while ((getLine()) > 0) {
        detab();
        printf("%s", newLine);
    }
}

/* getLine: read a line into line. */
int getLine()
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}

/* detab: replaces tabs with '-'. */
void detab()
{
    int c, i, k, w;
    for (i = 0, k = 0; (c = line[i]) != '\0'; ++i) {
        if (c != '\t')
            newLine[k++] = c;
        else
            w = TABWIDTH - (k % TABWIDTH);
            while (w-- > 0) {
                newLine[k++] = '-';
            }
    }
    newLine[k] = '\0';
}