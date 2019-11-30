#include <stdio.h>

/* Write a program to print a histogram of lengths of
 * words in its input. */
int main()
{
    int c;

    while ((c = getchar()) != EOF)
        if (c == ' ' || c == '\t' || c == '\n')
            putchar('\n');
        else
            putchar('*');
}