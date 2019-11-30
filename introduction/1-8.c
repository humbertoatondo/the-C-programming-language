#include <stdio.h>

/* Write a program to count blanks, tabs, and newlines */
int main()
{
    int c, nc;
    nc = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n' || c == '\t' || c == ' ')
            ++nc;
    printf("Counter: %d\n", nc);
}