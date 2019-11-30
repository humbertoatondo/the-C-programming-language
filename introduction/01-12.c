#include <stdio.h>

/* Write a program that prints its input one wor per line */
int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') 
            putchar('\n');
        else
            putchar(c);        
    }
}