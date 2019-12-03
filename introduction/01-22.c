/*
 * Write a program to "fold" long input lines into two or
 * more shorter lines after the last non-blank character
 * that occurs before the n-th column of input. Make sure
 * your program does something intelligent with very long
 * line, and if there are no blanks or tabs before the
 * specified column.
 */

#include <stdio.h>

#define MAXSIZE 1000
#define LINESIZE 40
#define OFFSET 10

char line[MAXSIZE];

int getLine();
void fold(int len);

int main()
{
    int len;
    while ((len = getLine()) > 0) {
        fold(len);
    }
}

int getLine()
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i++] = '\n';
    }
    line[i] = '\0';
    return i;
}

void fold(int k)
{
    char newLine[LINESIZE + OFFSET + 50];
    int i, j, prev, curr;
    curr = prev = 0;
    for (i = 0, j = 0; i < k; i++, j++) {
        newLine[j] = line[i];
        if (line[i] == ' ' || line[i] == '\t') {
            prev = curr;
            curr = j;
        }
        if (curr > LINESIZE) {
            i -= (curr - prev);
            newLine[prev++] = '\n';
            newLine[prev] = '\0';
            printf("%s", newLine);
            j = -1;
            prev = 0;
            curr = 0;
        }
    }
    newLine[prev++] = '\n';
    newLine[prev] = '\0';
    printf("%s", newLine);
}