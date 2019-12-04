/* 
 * Write a program to print a histogram of frequencies
 * of different characters in its input.
 */

#include <stdio.h>

    int main()
{
    int c, i, j, list[26];

    for (i = 0; i < 26; ++i)
        list[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= 'a' && c <= 'z')
            ++list[c-'a'];

    for (i = 0; i < 26; ++i) {
        printf("%c : ", 'a'+i);
        for (j = 0; j < list[i]; ++j)
            putchar('*');

        putchar('\n');
    }
}