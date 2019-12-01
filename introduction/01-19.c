/*
 * Write a function reverse(s) that reverses the
 * character string s. Use it to write a program that 
 * reverses its input a line at a time.
 */

#include <stdio.h>

#define LINESIZE 1000

int getLine(char line[]);
void reverse(char s[], int len);

int main()
{
    char line[LINESIZE];
    int len;
    while ((len = getLine(line)) > 0)
        reverse(line, len);
}
 /* getLine: read a lien into s. */
int getLine(char s[])
{
    int i, c;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    return i;
}

/* reverse: prints a string backwards. */
void reverse(char s[], int j)
{
    for (; j >= 0; --j) 
        putchar(s[j]);
    putchar('\n');
}